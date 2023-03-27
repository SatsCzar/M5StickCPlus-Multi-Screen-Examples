#include <M5StickCPlus.h>

#include <string>

enum ScreenState { SCREEN1, SCREEN2, SCREEN3 };

ScreenState currentScreenState = SCREEN1;
const int NUM_SCREEN_STATES = 3;

void setup() {
  M5.begin();

  M5.Lcd.setTextSize(2);
  M5.Lcd.setRotation(1);
  M5.Axp.ScreenBreath(9);

  drawScreen1();
}

void loop() {
  if (checkButtons()) {
    changeScreenState();
  }
  delay(100);
}

boolean checkButtons() {
  M5.update();
  if (M5.BtnA.wasPressed() || M5.BtnB.wasPressed() || M5.Axp.GetBtnPress()) {
    return true;
  }

  return false;
}

void drawScreen1() {
  M5.Lcd.setCursor(5, 10);
  M5.Lcd.setTextSize(3);
  M5.Lcd.print("Block Height:");
  M5.Lcd.setCursor(60, 80);
  M5.Lcd.print(719805);
}

void drawScreen2() {
  M5.Lcd.setCursor(5, 10);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("BitcoinPrice");
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(5, 80);
  M5.Lcd.print("R$ 145000");
}

void drawScreen3() {
  M5.Lcd.setCursor(5, 10);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Fee: 15 sats/byte");
}

void changeScreenState() {
  currentScreenState =
      static_cast<ScreenState>((currentScreenState + 1) % NUM_SCREEN_STATES);
  updateScreen();
}

void updateScreen() {
  clearScreen();
  
  switch (currentScreenState) {
    case SCREEN1:
      drawScreen1();
      break;
    case SCREEN2:
      drawScreen2();
      break;
    case SCREEN3:
      drawScreen3();
      break;
  }
}

void clearScreen() { M5.Lcd.fillRect(0, 0, 240, 135, BLACK); }