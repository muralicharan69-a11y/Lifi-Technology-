#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define ldr 8

String duration = "";

void setup() {
  Serial.begin(9600);

  pinMode(ldr, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.clear();

  lcd.print("LiFi Project");
  delay(3000);

  lcd.clear();
  lcd.print("Send any message");
  lcd.setCursor(0, 1);
  lcd.print("from LiFi App..");
  delay(3000);

  lcd.clear();
}

void loop() {

  int val = digitalRead(ldr);

  // Start receiving when LDR detects LOW
  if (val == 0) {

    duration = "";

    while (true) {

      int val2 = digitalRead(ldr);

      // Store each received bit
      duration += String(val2);

      // End of transmission
      if (val2 == 1) {
        break;
      }

      delay(200);
    }

    Serial.print("Received code: ");
    Serial.println(duration);

    // -------------------------------
    // MESSAGE DECODING
    // -------------------------------

    if (duration == "01") {
      displayMessage("hi");
    }

    else if (duration == "001") {
      displayMessage("hello");
    }

    else if (duration == "0001") {
      displayMessage("how are you?");
    }

    else if (duration == "00001") {
      displayMessage("I am fine");
    }

    else if (duration == "000001") {
      displayMessage("ok");
    }

    else if (duration == "0000001") {
      displayMessage("good morning");
    }

    else if (duration == "00000001") {
      displayMessage("good afternoon");
    }

    else if (duration == "000000001") {
      displayMessage("good evening");
    }

    else if (duration == "0000000001") {
      displayMessage("thank you");
    }

    else if (duration == "00000000001") {
      displayMessage("sorry");
    }

    else if (duration == "000000000001") {
      displayMessage("please");
    }

    else if (duration == "0000000000001") {
      displayMessage("welcome");
    }

    else if (duration == "00000000000001") {
      displayMessage("yes");
    }

    else if (duration == "000000000000001") {
      displayMessage("no");
    }

    else if (duration == "0000000000000001") {
      displayMessage("good night");
    }

    else if (duration == "00000000000000001") {
      displayMessage("see you");
    }

    else if (duration == "000000000000000001") {
      displayMessage("take care");
    }

    else if (duration == "0000000000000000001") {
      displayMessage("I love you");
    }

    else if (duration == "00000000000000000001") {
      displayMessage("where are you?");
    }

    else if (duration == "000000000000000000001") {
      displayMessage("what are you doing?");
    }

    else if (duration == "0000000000000000000001") {
      displayMessage("I am coming");
    }

    else if (duration == "00000000000000000000001") {
      displayMessage("wait");
    }

    else if (duration == "000000000000000000000001") {
      displayMessage("start");
    }

    else if (duration == "0000000000000000000000001") {
      displayMessage("stop");
    }

    else if (duration == "00000000000000000000000001") {
      displayMessage("help");
    }

    else if (duration == "000000000000000000000000001") {
      displayMessage("emergency");
    }

    else {
      lcd.clear();
      lcd.print("Unknown message");

      Serial.println("Unknown message");
    }

    delay(1000);
  }
}


// ------------------------------------
// FUNCTION TO DISPLAY MESSAGE
// ------------------------------------

void displayMessage(String message) {

  Serial.print("Received message: ");
  Serial.println(message);

  lcd.clear();

  // LCD is 16x2
  if (message.length() <= 16) {
    lcd.setCursor(0, 0);
    lcd.print(message);
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print(message.substring(0, 16));

    lcd.setCursor(0, 1);
    lcd.print(message.substring(16));
  }
}
