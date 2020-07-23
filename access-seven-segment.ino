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
  for(uint8_t pin=2; pin<=9; pin++){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  
  pinMode(10, OUTPUT); // enable seven segment
  digitalWrite(10, HIGH); // Turn off seven segment
}

void loop(){
  //Turn On Seven Segment
  digitalWrite(10,LOW);
  
  // Send number 3 to seven segment
  digitalWrite(2, HIGH); // H
  digitalWrite(3, LOW); // G
  digitalWrite(4, HIGH); // F
  digitalWrite(5, HIGH); // E
  digitalWrite(6, LOW); // D
  digitalWrite(7, LOW); // C
  digitalWrite(8, LOW); // B
  digitalWrite(9, LOW); // A
}
