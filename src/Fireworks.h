#ifndef __FIREWORKS_H_INCLUDED_
#define __FIREWORKS_H_INCLUDED_
#include "main.h"

#define MAX_NUMBER_OF_SPARKS 60       // The maximum number of sparks from a firework explosion
#define MIN_NUMBER_OF_SPARKS 20       // The minimum number of sparks from a firework explosion
#define SPARK_FADE_TIME 5000          // Amount of miliseconds to stay in FADE stage

extern CRGBPalette16 spark_palette;

extern CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];
extern int led_order_array[NUM_LEDS_PER_STRIP * NUM_STRIPS];

void fireworks();
void fireworksUpdate();

class Firework
{
    private:
        enum stage
        {
            LAUNCH,
            EXPLOSION,
            FADING,
            WAITING
        };
        stage current_stage;                                    // What stage of the firework are we currently at
        uint32_t next_launch_time;                                   // Time for next flare launch
        uint16_t next_launch_max_wait;                          // Maximum time to wait for next launch
        uint16_t next_launch_min_wait;                          // Minimum time to wait for next launch
        bool launched;                                          // Is the flare launched yet?
        float flare_velocity;                                   // Speed of the flare when it is launched
        float flare_position;                                   // Current position of the flare
        uint8_t strip_number;                                   // What strip this firework object is displayed on
        float gravity;                                          // Gravity makes things accelerate back down
        //float64_t spark_deceleration;                               // Deceleration speed of the sparks
        uint8_t number_of_sparks;                               // Number of sparks from explosion
        float spark_position[MAX_NUMBER_OF_SPARKS];             // Position of all the sparks
        float spark_velocity[MAX_NUMBER_OF_SPARKS];             // The current velocity of all the sparks
        uint8_t spark_gradient_index[MAX_NUMBER_OF_SPARKS];     // The index of the active_spark_palette this spark gets its color from
        bool spark_velocity_direction[MAX_NUMBER_OF_SPARKS];    // The direction of the spark
        CRGBPalette16 *active_spark_palette;                    // The palette this firework object will get colors from
        bool get_random_palette;                                // True = random palette will be picked when new flare is generated. False = will get palette from the global active_palette 
        uint8_t flare_hue;                                      // Hue of the flare
        uint8_t flare_sat;                                      // Saturation of the flare
        uint8_t flare_val;                                      // Brightness of the flare
        uint8_t flare_tail_length;                              // How much to fade the tail of the flare each iteration (determines length of the "tail")
        uint32_t spark_fade_end;                                // Time to end FADE stage and proceed to next flare launch
        
    public:
        Firework(uint8_t strip_n);                              // The firework class constructor
        void prepare_for_launch();                              // This function resets all positions, and generates new random values
        void launch();                                          // This function handles updating of velocities, positions, colors, etc for the flare in the "launch part" of the animation
        void explosion();                                       // This function handles updating of velocities, positions, colors, etc for the sparks in the "explosion part" of the animation
        void fading();                                          // This function handles updating of velocities, positions, colors, etc for the sparks in the "fading part" of the animation
        void update_firework();                                 // This function check the stage of the firework, and calls the appropriate function
        void set_palette(CRGBPalette16 *palette);               // Function for updating the active_spark_palette variable of the Firework object 
};

extern Firework firework0;
extern Firework firework1;
extern Firework firework2;
extern Firework firework3;
extern Firework firework4;
extern Firework firework5;
extern Firework firework6;
extern Firework firework7;
extern Firework firework8;
extern Firework firework9;
extern Firework firework10;
extern Firework firework11;
extern Firework firework12;
extern Firework firework13;
extern Firework firework14;
extern Firework firework15;


#endif