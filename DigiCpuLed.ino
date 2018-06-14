#include <DigiUSB.h>
/*
 * DigiUSB by Digistump
 * rest of the codes by M3NI
 * email: m3ni021@gmail.com & admin@m3ni.ir
 */
void setup() {
  DigiUSB.begin();
  pinMode(1, OUTPUT); 
}

void get_input() {
  int lastRead;
  // when there are no characters to read, or the character isn't a newline
  while (true) { // loop forever
    if (DigiUSB.available()) {
      // something to read
      lastRead = DigiUSB.read();
      DigiUSB.write(lastRead);
      
      if (lastRead == 'h') { //the CMD file included in the github will send h when cpu goes above 90%
        digitalWrite(1, HIGH);
        delay(500)
      } //blinks the LED on the Digispark
      else {
        digitalWrite(1, LOW);
      }
    }
    
    // refresh the usb port for 10 milliseconds
    DigiUSB.delay(10);
  }
}

void loop() {
  // print output
  DigiUSB.println("Waiting for input...");
  // get input
  get_input();
}
