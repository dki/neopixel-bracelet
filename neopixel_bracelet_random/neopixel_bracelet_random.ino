    //Random Flash animation for Neopixel Ring Bangle Bracelet
    //by Dano Wall and Becky Stern for Adafruit Industries
    //based on the Sparkle Skirt, minus the accelerometer
    //modifications to fix simultaneous light-up by Dawn Isabel (dki)
    #include <Adafruit_NeoPixel.h>
    #include <colors.h>
     
    #define PIN 1
     
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = pin number (most are valid)
    // Parameter 3 = pixel type flags, add together as needed:
    //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);
     
    // Add colors by name from colors.h
    uint8_t myColors[][3] = { RASPBERRY,
                              OCEAN, 
                              VIOLET,
                              };
                                   
    // don't edit the line below
    #define FAVCOLORS sizeof(myColors) / 3
     
    void setup() {
      strip.begin();
      strip.setBrightness(20);
      strip.show(); // Initialize all pixels to 'off'
    }
     
    void loop() {
      flashRandom(5, 10);  // first number is 'wait' delay, shorter num == shorter twinkle
      flashRandom(5, 30);  // second number is how many neopixels to simultaneously light up
      flashRandom(5, 20);
    }
     
    void flashRandom(int wait, uint8_t howmany) {
      howmany = howmany % 64;
      uint8_t rands[64];

      // pick a random favorite color!
      int c = random(FAVCOLORS);
      int red = myColors[c][0];
      int green = myColors[c][1];
      int blue = myColors[c][2];
     
      for(uint16_t i=0; i<howmany; i++) {     
        // get a random pixel from the list
        rands[i] = random(strip.numPixels());
      }
        
        
      // now we will 'fade' it in 5 steps
      for (int x=0; x < 5; x++) {
        int r = red * (x+1); r /= 5;
        int g = green * (x+1); g /= 5;
        int b = blue * (x+1); b /= 5;

        for (int j=0; j<howmany; j++) {
          strip.setPixelColor(rands[j], strip.Color(r, g, b));
        }
        
        strip.show();
        delay(wait);
      }
      
      // & fade out in 5 steps
      for (int x=5; x >= 0; x--) {
        int r = red * x; r /= 5;
        int g = green * x; g /= 5;
        int b = blue * x; b /= 5;

        for (int j=0; j<howmany; j++) {
          strip.setPixelColor(rands[j], strip.Color(r, g, b));
        }
        strip.show();
        delay(wait);
      }
      
      // LEDs will be off when done (they are faded to 0)
    }
