#include "main.h"
#include "Fireworks.h"

CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];
int led_order_array[NUM_LEDS_PER_STRIP * NUM_STRIPS];


void setup() {
  delay(3000); // sanity delay
  Serial.begin(9600); 
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );

}
bool isInit =true;

void generate_led_order_array() {
   int ledindex = 0;

    for (int i = 0; i < NUM_STRIPS * STRIP_SPLIT; i++)
    {
      for (int x = NUM_LEDS_PER_STRIP / STRIP_SPLIT; x > 0; x--)
      {
        Serial.println((i*(NUM_LEDS_PER_STRIP / STRIP_SPLIT))+(x-1));
        Serial.println(ledindex);

        led_order_array[ledindex] = (i*(NUM_LEDS_PER_STRIP / STRIP_SPLIT))+(x-1);
        ledindex ++;
      }
    }
  
}

void loop()
{
  if(isInit) {
    generate_led_order_array();
    fireworks();
    isInit = false;
  }
  fireworksUpdate();
  FastLED.delay(20);
}