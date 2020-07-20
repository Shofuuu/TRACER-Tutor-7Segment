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
 */

#include <Arduino.h>

void setup(){
  for(uint8_t pin=2; pin<=9; pin++)
    pinMode(pin, OUTPUT);
  
  pinMode(10, OUTPUT); // enable seven segment
}

void loop(){
  // Send number 3 to seven segment
  digitalWrite(2, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(2, LOW);
  digitalWrite(2, LOW);
  digitalWrite(2, LOW);
}
