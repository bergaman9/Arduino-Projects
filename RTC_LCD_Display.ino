#include <LiquidCrystal.h>
#include <virtuabotixRTC.h>

// RTC module pins
int CLK_PIN = 6;
int DAT_PIN = 7;
int RST_PIN = 8;

// Initialize virtuabotixRTC object
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);

// LCD pins
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize LCD screen (16 columns, 2 rows)
  lcd.begin(16, 2);
}

void loop() {
  // Update time from RTC module
  myRTC.updateTime();

  // Clear LCD screen
  lcd.clear();

  // Display date on the first row
  lcd.setCursor(0, 0);
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);

  // Display time on the second row
  lcd.setCursor(0, 1);
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);

  // Refresh every second
  delay(1000);
}
