#include <FastLED.h>
#define NUM_LEDS 5 // 定义 led 数量
#define DATA_PIN 3 // 定义 开发板的IO 3 为数据引脚
#define numdata_length 2
String cmd = "";
int numdata[numdata_length] = {0};
int flag = 0;
int x = 0;
CRGB leds[NUM_LEDS]; // 定义CRGB的led等数组

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(115200);
  Serial.println("Serial initialized successfully.");
}

void loop() {
  int j = 0;
  while (Serial.available() > 0){
    cmd += char(Serial.read());
    delay(2);
    flag = 1;
  }
  while (flag == 1){
    for (int i=0 ; i< cmd.length() ; i++){
      if (cmd[i] == ','){
        j++;
      }
      else{
        numdata[j] = numdata[j]*10 + (cmd[i] - '0');
      }
    }
  cmd = String("");

  if (numdata[0] <= 30){
    x = 0;
    numdata[0] = 0;
  }
  else if (numdata[0] <= 60){
    x = 1;
    numdata[0] = 0;
  }
  else if (numdata[0] <= 90){
    x = 2;
    numdata[0] = 0;
  }
  else if (numdata[0] <= 120){
    x = 3;
    numdata[0] = 0;
  }
  else if (numdata[0] <= 150){
    x = 4;
    numdata[0] = 0;
  }
  else{
    x = 0;
    numdata[0] = 0;
  }

  leds[x] = CRGB::White;
  FastLED.show();
  delay(500);
  leds[x] = CRGB::Black;
  FastLED.show();
  flag = 0;
  }

  // // 每一个led逐个闪烁绿色
  // for(int i = 0; i < NUM_LEDS; i++ ) {
  //   leds[i] = CRGB::Green;
  //   FastLED.show();
  //   delay(100);
  //   leds[i] = CRGB::Black;
  //   FastLED.show();
  //   delay(100);
  // }

  // delay(1000);

  // // 整个灯条 彩虹色渐变
  // int h = 0;
  // for(int j = 0; j< 255; j++) {
  //   for (int i = 0; i < NUM_LEDS; i++) {
  //     leds[i] = CHSV( (h + (255 / NUM_LEDS) * i), 255, 255); //用HSV色彩空间，不断改变H即可
  //     FastLED.show();
  //   }
  //   delay(1);
  //   h = (h + 2) % 255;
  // }

  // // 整个灯条熄灭
  // for(int i = 0; i < NUM_LEDS; i++ ){
  //   leds[i] = CRGB::Black;
  // }
  // FastLED.show();

  delay(1000);
}