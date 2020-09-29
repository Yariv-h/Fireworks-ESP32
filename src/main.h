#include <FastLED.h>

#define LED_PIN     5
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define BRIGHTNESS  200
#define FRAMES_PER_SECOND 60


//Make sure when changing the following, to enable in the main.cpp file the reference to fireworks array
    //according to the STRIP_SPLIT
     //  VVVVVVV
     //   VVVV 
     //    V
#define STRIP_SPLIT 2   //Define how many "virtual strips" each of the outputs should be split into
                        //NUM_LEDS_PER_STRIP must be dividable by this number
#define NUM_LEDS_PER_STRIP 300
#define NUM_STRIPS 1