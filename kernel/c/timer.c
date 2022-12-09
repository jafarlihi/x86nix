#include "timer.h"
#include "irq.h"
#include "isr.h"
#include "ports.h"

volatile unsigned int timer_ticks = 0;

void timer_handler(registers_t *r) {
    timer_ticks++;
}

void init_timer() {
    irq_install_handler(0, timer_handler);
}

void timer_wait(int ticks) {
    unsigned long eticks;

    eticks = timer_ticks + ticks;
    while(timer_ticks < eticks) {
        asm volatile ("sti//hlt//cli");
    }
}

void timer_phase(int hz) {
    int divisor = 1193180 / hz;
    outportb(0x43, 0x36);
    outportb(0x40, divisor & 0xFF);
    outportb(0x40, divisor >> 8);
}

