    //Figure-Eight animation for Neopixel Ring Bangle Bracelet
    //By Dano Wall and Becky Stern for Adafruit Industries
    //modifications by Dawn Isabel (dki)
    #include <Adafruit_NeoPixel.h>
    #include <colors.h>
     
    #define PIN 1 //marked D1 on GEMMA
     
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = pin number (most are valid)
    // Parameter 3 = pixel type flags, add together as needed:
    //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);
     
    //Array of pixels in order of animation - 70 in total
    byte sine[] = {4, 3, 2, 1, 0, 15, 14, 13, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 36, 35, 34, 33, 32, 47, 46, 45, 44, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 44, 43, 42, 41, 40, 39, 38, 37, 36, 28, 29, 30, 31, 16, 17, 18, 19, 20, 12, 11, 10, 9, 8, 7, 6, 5}; 
    
    // arrange colors below
    uint8_t myColors[][3] = {     // trailing color
                              DEEPSKYBLUE,
                              OCEAN,
                              BLUE,
                              VIOLET                            
                              };  // leading color
                              
    #define REPEATS 3                 // length of each color in pixels
    #define TOTALPIXELS sizeof(sine)  // how many pixels total on the bracelet
     
    void setup() {
      strip.begin();
      strip.setBrightness(30); //adjust brightness here
      strip.show(); // Initialize all pixels to 'off'
    }
     
    void loop() {
      int numcolors = sizeof(myColors) / 3;
      int numlit = numcolors * REPEATS;
    
      for(int i=0; i<TOTALPIXELS; i++) { 
        strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
        
        delay(60);    
        for (int j=0; j<numlit; j++) {
          strip.setPixelColor(sine[(j+i+1)%TOTALPIXELS], strip.Color(myColors[j/REPEATS][0], myColors[j/REPEATS][1], myColors[j/REPEATS][2])); // gradient 
        }
        strip.show();
        
      }
      
    }
