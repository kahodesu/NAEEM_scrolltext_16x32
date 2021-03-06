//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
/////////CODE FOR NAEEM'S PROJECT ON THE LED DISPLAY /////////
/////////Obv just a tweak of the demo code below:    /////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

// scrolltext demo for Adafruit RGBmatrixPanel library.
// Demonstrates double-buffered animation on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// Similar to F(), but for PROGMEM string pointers rather than literals
#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
// Last parameter = 'true' enables double-buffering, for flicker-free,
// buttery smooth animation.  Note that NOTHING WILL SHOW ON THE DISPLAY
// until the first call to swapBuffers().  This is normal.
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);
// Double-buffered mode consumes nearly all the RAM available on the
// Arduino Uno -- only a handful of free bytes remain.  Even the
// following string needs to go in PROGMEM:

const char str[] PROGMEM = "How could they not die? Their brain is scrambled from all that listening. One is still alive, in a trance. A child takes two years to speak. And this is only a bird.";
//const char str[] PROGMEM = "naeem";
int    textX   = matrix.width(),
       textMin = sizeof(str) * -6;


void setup() {
  matrix.begin();
  matrix.setTextWrap(false); // Allow text to run off right edge
  matrix.setTextSize(1);
}

void loop() {
  byte i;

  // Clear background
  matrix.fillScreen(0);

  // Draw big scrolly text on top
  matrix.setTextColor(matrix.ColorHSV(0, 0, 68, true));
  matrix.setCursor(textX,5);
  matrix.print(F2(str));

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin){
  textX = matrix.width();

  }
   delay(25);

  // Update display
  matrix.swapBuffers(false);

}

