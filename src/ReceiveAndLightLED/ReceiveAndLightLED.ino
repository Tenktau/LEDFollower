#include <FastLED.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#define NUM_LEDS 5 // 定义 led 数量
#define DATA_PIN 3 // 定义 开发板的IO 3 为数据引脚

SoftwareSerial softSerial(10,11);
String input;
volatile int pos_x;
volatile char ch;

CRGB leds[NUM_LEDS]; // 定义CRGB的led等数组

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  // pos_x = 0;
  // ch = 0;
  // input = "";
  Serial.begin(115200);
  softSerial.begin(115200);
  Serial.println("======Serial initialized successfully.======"); //TestPoint
}

void loop() {
  if (softSerial.available() > 0) {
    Serial.print("======Loop Begin======\n");       //TestPoint
    input = softSerial.readStringUntil('\n');
    input.trim();
    Serial.print("====== Input: ");       //TestPoint
    Serial.print(input);       //TestPoint
    Serial.print("======\n");       //TestPoint
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, input);
    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.f_str());
      return;
    } else {
        double tag_rot = doc["tag_rot"];
        int tag_id = doc["tag_id"];
        int pos_x = doc["pos_x"];
        int pos_y = doc["pos_y"];
        Serial.print("\n======Indexing pos_x: ");       //TestPoint
        Serial.println(pos_x);       //TestPoint
        Serial.print("======\n");       //TestPoint
        if (pos_x != 0){
          Serial.print("\n======Received pos_x: ");       //TestPoint
          Serial.print(pos_x);       //TestPoint
          Serial.print("======\n");       //TestPoint
          int index = pos_x/30;
          leds[index] = CRGB::White;
          FastLED.show();
          Serial.print("\n======Lighted LED: ");       //TestPoint
          Serial.print(index);       //TestPoint
          Serial.print("======\n");       //TestPoint
          // leds[index] = CRGB::Black;
          delay(1000);
        }
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
