#include <FastLED.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#define NUM_LEDS 5 // 定义 led 数量
#define DATA_PIN 3 // 定义 开发板的IO 3 为数据引脚

SoftwareSerial softSerial(10,11);
volatile int pos_x;
volatile char ch;
String json;
CRGB leds[NUM_LEDS]; // 定义CRGB的led等数组

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pos_x = 0;
  ch = 0;
  json = "";
  Serial.begin(115200);
  softSerial.begin(115200);
  Serial.println("Serial initialized successfully.");
}

void loop() {
  if (softSerial.available() > 0) {
    ch = char(softSerial.read());
    json = String(json) + String(ch);
    if (ch == '}') {
      JsonDocument doc; //声明一个JsonDocument对象
      deserializeJson(doc, json);
      JsonObject obj = doc.as<JsonObject>();
      int pos_x = doc["pos_x"];
      if (pos_x != 0){
        int index = pos_x/30;
        leds[index] = CRGB::White;
        FastLED.show();
        // leds[index] = CRGB::Black;
        delay(1000);
      }
      else{
        leds[4] = CRGB::Green;
      }
      json = "";
      }
  }
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

  // delay(1000);
// }
