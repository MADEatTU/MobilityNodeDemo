#include <can.h>
#include <mcp2515.h>


void setup() {
  MCP2515 mcp2515(10);
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setLoopbackMode();
  self.ID = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  // compare button state to previous
  // if button pressed == self.ID
    // set self.LED status == button status
  // else:
    // button_pressed(button_pressed, button_status)
  
  // on interupt: if can_id == self.ID:
    // set self.LED status == frame.data[0]
  
}

void button_pressed(int pin, bool button_status) {
  
  struct can_frame frame;
  frame.can_id = pin; // Target board ID corrosponding to button ID
  frame.can_dlc = 4;
  frame.data[0] = true; // Send status of button 
  frame.data[1] = 0xFF;
  frame.data[2] = 0xFF;
  frame.data[3] = 0xFF;
  
  /* send out the message to the bus and
  tell other devices this is a standard frame from 0x00. */
  mcp2515.sendMessage(&frame);
}
