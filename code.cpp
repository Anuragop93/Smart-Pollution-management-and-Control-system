#include <Arduino.h>
#include <WiFi.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <U8g2lib.h>

// ===================== OLED =====================
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

// ===================== LED & BUZZER =====================
#define GREEN_LED1 5
#define RED_LED1 4
#define BUZZER1 15

#define GREEN_LED2 27
#define RED_LED2 12
#define BUZZER2 14

// ===================== MQ135 =====================
#define MQ135_CHAMBER 34
#define MQ135_FACTORY 35

// ===================== PMS5003 =====================
#define PMS_RX_PIN 16
#define PMS_TX_PIN 17
#define PMS_SERIAL Serial1

// ===================== MOTOR =====================
#define MOTOR_PIN 33

uint8_t buffer[64];
int bufferIndex = 0;

uint16_t pmValue = 0;
int mqChamber = 0;
int mqFactory = 0;

// ===================== Thresholds =====================
#define MQ_THRESHOLD 450
#define PM_THRESHOLD 500

// ===================== OLED FUNCTION =====================
void drawCentered(const char* text, const uint8_t* font, int y) {
  u8g2.setFont(font);
  int textWidth = u8g2.getStrWidth(text);
  int x = (128 - textWidth) / 2;
  u8g2.drawStr(x, y, text);
}

// ===================== MAIN FUNCTION =====================
void sendData() {

  // MQ READ
  mqChamber = analogRead(MQ135_CHAMBER);
  mqFactory = analogRead(MQ135_FACTORY);

  // PM SENSOR READ
  while (PMS_SERIAL.available()) {

    buffer[bufferIndex++] = PMS_SERIAL.read();

    if (bufferIndex >= 32) {

      for (int i = 0; i < bufferIndex - 31; i++) {

        if (buffer[i] == 0x42 && buffer[i + 1] == 0x4D) {

          pmValue = (buffer[i + 12] << 8) | buffer[i + 13];

          bufferIndex = 0;

          break;
        }
      }
    }

    if (bufferIndex >= 63) {
      bufferIndex = 0;
    }
  }

  // CONDITIONS
  bool factoryAlert = (mqFactory > MQ_THRESHOLD);
  bool pmAlert = (pmValue > PM_THRESHOLD);

  // ===================== MOTOR =====================
  digitalWrite(MOTOR_PIN, pmAlert);

  // ===================== LED =====================
  digitalWrite(GREEN_LED1, !pmAlert);
  digitalWrite(RED_LED1, pmAlert);
  digitalWrite(BUZZER1, pmAlert);

  digitalWrite(GREEN_LED2, !factoryAlert);
  digitalWrite(RED_LED2, factoryAlert);
  digitalWrite(BUZZER2, factoryAlert);

  // ===================== STATUS =====================
  String status;

  if (!factoryAlert && !pmAlert) {
    status = "SAFE";
  }
  else if (factoryAlert && !pmAlert) {
    status = "WARNING";
  }
  else if (!factoryAlert && pmAlert) {
    status = "BAD AQI";
  }
  else {
    status = "DANGER";
  }

  // ===================== OLED =====================
  u8g2.clearBuffer();

  drawCentered(status.c_str(), u8g2_font_logisoso20_tr, 40);

  u8g2.sendBuffer();

  // ===================== SERIAL =====================
  Serial.print("MQ Chamber: ");
  Serial.print(mqChamber);

  Serial.print(" | MQ Factory: ");
  Serial.print(mqFactory);

  Serial.print(" | PM: ");
  Serial.print(pmValue);

  Serial.print(" | STATUS: ");
  Serial.println(status);
}

// ===================== SETUP =====================
void setup() {

  pinMode(GREEN_LED1, OUTPUT);
  pinMode(RED_LED1, OUTPUT);
  pinMode(BUZZER1, OUTPUT);

  pinMode(GREEN_LED2, OUTPUT);
  pinMode(RED_LED2, OUTPUT);
  pinMode(BUZZER2, OUTPUT);

  pinMode(MOTOR_PIN, OUTPUT);

  Serial.begin(115200);

  PMS_SERIAL.begin(9600, SERIAL_8N1, PMS_RX_PIN, PMS_TX_PIN);

  Wire.begin(19, 22);

  u8g2.begin();

  Serial.println("SYSTEM STARTED");
}

// ===================== LOOP =====================
void loop() {

  sendData();

  delay(1000);
}
