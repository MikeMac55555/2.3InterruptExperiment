#include "mbed.h"
#include "C12832.h"
C12832 lcd(p5, p7, p6, p8, p11);
int x=0;
InterruptIn joystickcenter(p14);
InterruptIn button(p9);
DigitalOut led(LED1);
DigitalOut flash(LED4);
//Timer debounce();

void flip() {
    //if (debounce.read_ms() < 1000){
    led = !led; // toggles the led when the joystick button is pressed.
        //debounce.reset();
    x=1;    
    }    

int main() {
    joystickcenter.rise(&flip); // attach the function address to the rising edge
    button.mode(PullUp); // With this, no external pullup resistor needed
    button.rise(&flip); // attach the function address to the rising edge
    while(1) { // wait around, interrupts will interrupt this!
        if(x==1){
            lcd.printf("hello");
            x=0;
        }
        flash = !flash; // turns LED4 on if off, off if on
        wait(0.25); // the instruction to wait for a quarter-second
    }
}
