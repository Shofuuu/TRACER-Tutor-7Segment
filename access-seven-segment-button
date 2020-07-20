/*
 * Seven segment display scanning mode
 * Seven segment pinout
 * Common anode
 * A B C D E F G H
 * | | | | | | | |
 * 9 8 7 6 5 4 3 2
 *
 * Common pinout
 * SEG1 SEG2
 *  |    |
 *  10   11
 *
 * PNP BJT Transistor as switch
 *
 * Button active low : 12
 */

#include <Arduino.h>

void segment_init(){
  pinMode(12, INPUT_PULLUP);

  for(uint8_t pin=2; pin<=9; pin++)
    pinMode(pin, OUTPUT);

  for(uint8_t seg=10; seg<11; seg++){
    pinMode(seg, OUTPUT);
    digitalWrite(seg, HIGH); // turn off seven segment
  }
}

void segment_number(uint8_t number){
  uint8_t decode[10][8] = { // seven segment number
    {1,0,1,0,0,0,0,0}, // 0
    {1,1,1,1,1,0,0,1}, // 1
    {1,0,1,0,0,1,0,0}, // 2
    {1,0,1,1,0,0,0,0}, // 3
    {1,0,0,1,1,0,0,1}, // 4
    {1,0,0,1,0,0,1,0}, // 5
    {1,0,0,0,0,0,1,0}, // 6
    {1,1,1,1,1,0,0,0}, // 7
    {1,0,0,0,0,0,0,0}, // 8
    {1,0,0,1,0,0,0,0}  // 9
  };

  for(uint8_t pin=0; pin<8; pin++)
    digitalWrite( pin+2, decode[number][pin]);
}

void segment_select(uint8_t digit){
  uint8_t __digit__[2] = {10, 11};

  for(uint8_t pin=0; pin<2; pin++) // turn off all seven segment
    digitalWrite(__digit__[pin], HIGH);

  digitalWrite(__digit__[digit], LOW); // turn on selected seven segment
}

void segment_write(uint8_t number){
  segment_select(0);
  segment_number(
    number/10
  );
  delayMicroseconds(500);

  segment_select(1);
  segment_number(
    number - ((number/10)*10)
  );
  delayMicroseconds(500);
}

static uint8_t counter = 0;

void setup() {
  segment_init();
}

void loop() {
  if(!digitalRead(12)){
    counter++;
    delay(150);
  }
  
  segment_write(counter);
}
