
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <RTClib.h>

// Pin Definitions
#define LDR_PIN 2
#define BUZZER_PIN 8
#define SERVO_PIN 3
#define SS_PIN 10
#define RST_PIN 9

// RFID and RTC Setup
MFRC522 rfid(SS_PIN, RST_PIN);
RTC_DS3231 rtc;
Servo gateServo;

// Authorized UID List
const byte authorizedUID[][4] = {
  {0x03, 0x1F, 0x6E, 0x14}
//  {0xE3, 0x72, 0x32, 0x29}
};
const int numAuthorizedTags = sizeof(authorizedUID) / sizeof(authorizedUID[0]);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  // RTC Init
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC. Check wiring!");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power. Setting time to compile time...");
    rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  }

  // Pin Setup
  pinMode(LDR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  gateServo.attach(SERVO_PIN);
  gateServo.write(0); // Gate closed initially

  Serial.println("System Initialized. Monitoring laser sensor...");
}

void loop() {
  if (digitalRead(LDR_PIN) == HIGH) {
    Serial.println("Laser interrupted! Someone is at the gate.");
    Serial.println("Waiting for RFID card...");

    unsigned long startTime = millis();
    bool cardDetected = false;

    while (millis() - startTime < 5000) {
      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
        cardDetected = true;

        Serial.print("Card UID: ");
        for (byte i = 0; i < rfid.uid.size; i++) {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
          Serial.print(rfid.uid.uidByte[i], HEX);
          Serial.print(" ");
        }
        Serial.println();

        if (isAuthorized(rfid.uid.uidByte)) {
          DateTime now = rtc.now();
          Serial.print("Access Granted at ");
          Serial.print(now.year()); Serial.print("/");
          Serial.print(now.month()); Serial.print("/");
          Serial.print(now.day()); Serial.print(" ");
          Serial.print(now.hour()); Serial.print(":");
          Serial.print(now.minute()); Serial.print(":");
          Serial.println(now.second());

          openGate();
        } else {
          Serial.println("Access Denied: Unauthorized card.");
          soundBuzzer();
        }

        rfid.PICC_HaltA(); // Stop reading card
        break;
      }
    }

    if (!cardDetected) {
      Serial.println("Timeout: No RFID card presented.");
      beep();
    }

    delay(1000); // Prevent repeated triggers
    Serial.println("Resuming laser monitoring...\n");
  }
}

bool isAuthorized(byte *uid) {
  for (int i = 0; i < numAuthorizedTags; i++) {
    bool match = true;
    for (int j = 0; j < 4; j++) {
      if (uid[j] != authorizedUID[i][j]) {
        match = false;
        break;
      }
    }
    if (match) return true;
  }
  return false;
}

void openGate() {
  gateServo.write(90);
  Serial.println("Gate opened.");
  delay(3000);
  gateServo.write(0);
  Serial.println("Gate closed.");
}

void soundBuzzer() {
  for (int freq = 2000; freq <= 4000; freq += 10) {
    tone(BUZZER_PIN, freq);
    delay(5);
  }

  // Sweep down from 4000 to 2000 Hz
  for (int freq = 4000; freq >= 2000; freq -= 10) {
    tone(BUZZER_PIN, freq);
    delay(5);
  }

  noTone(BUZZER_PIN);  // Optional short pause between cycles
  delay(100);
}

void beep() {
  for (int i = 0; i < 3; i++) {           // 3 beeps
    tone(BUZZER_PIN, 4000);               // Play 4kHz tone
    delay(200);                          // Beep duration
    noTone(BUZZER_PIN);                   // Stop tone
    delay(200);                          // Pause between beeps
  }
  delay(100);
}