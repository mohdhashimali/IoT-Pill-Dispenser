#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <AccelStepper.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// RTC setup
RTC_DS3231 rtc;

// Motor pin definitions
#define motorPin1  8
#define motorPin2  9
#define motorPin3  10
#define motorPin4  11

#define MotorInterfaceType 8
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);

// Time settings for pill dispensing
int amHr = 8, amMin = 0, amSec = 0;
int pmHr = 00, pmMin = 40, pmSec = 20;

// Pin definitions
const int led = 2;
const int button = 5;
const int buzzer = 3;

// Button state
int buttonState = 0;

// Minimum and maximum values structure for each input
typedef struct minMax_t {
  int minimum;
  int maximum;
};

// Function to validate user input
bool checkInput(const int value, const minMax_t minMax) {
  if ((value >= minMax.minimum) && (value <= minMax.maximum))
    return true;

  Serial.print(value);
  Serial.print(" is out of range ");
  Serial.print(minMax.minimum);
  Serial.print(" - ");
  Serial.println(minMax.maximum);
  return false;
}

// Function to update RTC time using user input
void updateRTC() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Edit Mode...");

  const char txt[6][15] = { "year [4-digit]", "month [1~12]", "day [1~31]", "hours [0~23]", "minutes [0~59]", "seconds [0~59]" };
  const minMax_t minMax[] = { {2000, 9999}, {1, 12}, {1, 31}, {0, 23}, {0, 59}, {0, 59} };

  String str = "";
  long newDate[6];
  DateTime newDateTime;

  while (1) {
    while (Serial.available()) {
      Serial.read();  // Clear serial buffer
    }

    for (int i = 0; i < 6; i++) {
      while (1) {
        Serial.print("Enter ");
        Serial.print(txt[i]);
        Serial.print(" (or -1 to abort) : ");

        while (!Serial.available()) {
          ; // Wait for user input
        }

        str = Serial.readString();  // Read user input

        if ((str == "-1") || (str == "-1\n") || (str == "-1\r") || (str == "-1\r\n")) {
          Serial.println("\nABORTED");
          return;
        }

        newDate[i] = str.toInt();   // Convert user input to number and save to array

        if (checkInput(newDate[i], minMax[i]))
          break;
      }

      Serial.println(newDate[i]); // Show user their input
    }

    newDateTime = DateTime(newDate[0], newDate[1], newDate[2], newDate[3], newDate[4], newDate[5]);
    if (newDateTime.isValid())
      break;

    Serial.println("Date/time entered was invalid, please try again.");
  }

  rtc.adjust(newDateTime);
  Serial.println("RTC Updated!");
}

// Function to update LCD text
void updateLCD() {
  DateTime rtcTime = rtc.now();
  char timeBuffer[] = "hh:mm:ss";
  
  lcd.setCursor(0, 0);
  lcd.print("Time");
  lcd.setCursor(5, 0);
  lcd.print(rtcTime.toString(timeBuffer));
}

void setup() {
  stepper.setMaxSpeed(1000);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
  rtc.begin();
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  DateTime rtcTime = rtc.now();
  buttonState = digitalRead(button);

  updateLCD();
  
  if (rtcTime.hour() == amHr && rtcTime.minute() == amMin && rtcTime.second() == amSec) {
    lcd.clear();
    rotateAM(); // Start stepper
  }
  
  if (rtcTime.hour() == pmHr && rtcTime.minute() == pmMin && rtcTime.second() == pmSec) {
    lcd.clear();
    rotatePM(); // Start stepper
  }
  
  if (buttonState == HIGH) {
    lcd.clear();
    digitalWrite(led, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Pills Taken");
  }

  if (Serial.available()) {
    char input = Serial.read();
    if (input == 'u') updateRTC();
  }
}

void rotateAM() {
  stepper.enableOutputs();
  stepper.setCurrentPosition(0);

  while (stepper.currentPosition() != 2048) {
    stepper.setSpeed(500);
    stepper.runSpeed();
  }
  
  stepper.disableOutputs();
  digitalWrite(led, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("Take your pill!");
  ringBuzzer();
}

void rotatePM() {
  stepper.enableOutputs();
  stepper.setCurrentPosition(0);

  while (stepper.currentPosition() != 2048) {
    stepper.setSpeed(500);
    stepper.runSpeed();
  }
  
  stepper.disableOutputs();
  lcd.setCursor(0, 1);
  lcd.print("Take your Pill!");
  digitalWrite(led, HIGH);
  ringBuzzer();
}

void ringBuzzer() {
  digitalWrite(buzzer, HIGH);
  delay(2000);  // Buzzer rings for 2 seconds
  digitalWrite(buzzer, LOW);
}

void rotateOver() {
  stepper.enableOutputs();
  stepper.setCurrentPosition(0);

  while (stepper.currentPosition() != 2048) {
    stepper.setSpeed(500);
    stepper.runSpeed();
  }
  
  stepper.disableOutputs();
  lcd.setCursor(0, 1);
  lcd.print("Timer Overridden");
  digitalWrite(led, HIGH);
}
