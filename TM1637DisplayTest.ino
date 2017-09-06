#include <TM1637Display.h>

#define CLK 9
#define DIO 8

String dw = "";
String hh = "";
String mm = "";
String ss = "";
float t = 0;

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(0xA);
}

void loop() {
  
  // 取得星期幾
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // 取得日期
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // 取得時間
  dw = rtc.getTimeStr();
  Serial.println(dw);
  
  hh = dw.substring(0,2);          // 時數
  mm = dw.substring(3,5);          // 分鐘數
  ss = dw.substring(6,8);          // 秒數 

  // 顯示四位數中間的冒號
  uint8_t segto;
  int value = 1000;
  // 顯示 時：分
  int  t =  hh.toInt()*100  + mm.toInt();
  // 顯示 分：秒
  //  int t =  mm.toInt() *100 +ss.toInt();
  segto = 0x80 | display.encodeDigit((t / 100)%10);
  display.setSegments(&segto, 1, 1);
  delay(500);

  // 顯示時間
  display.showNumberDec(t, true);
  delay(500);
}
