//**************************************************************//
//  Name    : shiftOutCode, Hello World
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis
//  Date    : 25 Oct, 2006
//  Modified: 23 Mar 2010
//  Version : 2.0
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255
//****************************************************************
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;
int dataPin2 = 9;

int led_shift[4] = {1, 2, 3, 4};
int transistor_shift[2] = {1, 2};
byte led_display = 0;
byte layer_display = 0;


void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop() {
  // count from 0 to 255 and display the number
  // on the LEDs


  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      led_display = 1 << led_shift[i];
      layer_display = 1 << transistor_shift[j];

      // take the latchPin low so
      // the LEDs don't change while you're sending in bits:
      digitalWrite(latchPin, LOW);
      // shift out the bits:

      // Need to do multiple shiftOuts with daisy-chained registers.
      // Shift to the layer register
      shiftOut(dataPin, clockPin, MSBFIRST, layer_display);

      // Shift to the led register
      shiftOut(dataPin, clockPin, MSBFIRST, led_display);
      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);
      // pause before next value:
      delay(500);
    }
  }
}
