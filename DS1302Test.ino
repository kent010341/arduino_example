#include <DS1302.h>

DS1302 rtc(10, 9, 8);

void setup() {
  // put your setup code here, to run once:
  rtc.halt(false);
  Serial.begin(9600);
  // 以下是設定時間的方法，在電池用完之前，只要設定一次就行了
  rtc.setDOW(FRIDAY);        // 設定週幾，如FRIDAY
  rtc.setTime(14, 52, 00);     // 設定時間 時，分，秒 (24hr format)
  rtc.setDate(30, 8, 2017);   // 設定日期 日，月，年
}

void loop() {
  // put your main code here, to run repeatedly:
  // 週幾
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // 日期
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // 時間
  Serial.println(rtc.getTimeStr());
  
  // 每次更新延遲1秒
  delay (1000);
}
