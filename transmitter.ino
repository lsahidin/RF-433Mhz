//Test and text transmission with RF module for Arduino
//TRANSMITTER
#include <VirtualWire.h>

// try to send 2 different value type
int readSensor;
char senstoChar[3];

void setup()
{
  vw_set_ptt_inverted(true);  // Required by the RF module
  vw_setup(2000);            // bps connection speed
  vw_set_tx_pin(3);         // Arduino pin to connect the receiver data pin
}
 
void loop()
{
  //Message to send:
  char *msg = "Value Sensor: ";
  readSensor = 255;
  itoa(readSensor, senstoChar, 5);
  strcat(msg, senstoChar);         // Joining two arrays, gabung bro
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();        // We wait to finish sending the message
  delay(200);         // We wait to send the message again                
}