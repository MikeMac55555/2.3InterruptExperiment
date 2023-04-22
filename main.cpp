#include "mbed.h"
InterruptIn joystickcenter(p14);
InterruptIn button(p9);
DigitalOut led(LED1);
DigitalOut flash(LED4);
void flip() {
 led = !led; // toggles the led when the joystick button is pressed.
}
int main() {
 joystickcenter.rise(&flip); // attach the function address to the rising edge
 button.mode(PullUp); // With this, no external pullup resistor needed
 button.rise(&flip); // attach the function address to the rising edge
 while(1) { // wait around, interrupts will interrupt this!
 flash = !flash; // turns LED4 on if off, off if on
 wait(0.25); // the instruction to wait for a quarter-second
 }
}
