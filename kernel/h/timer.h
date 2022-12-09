#ifndef TIMER_H
#define TIMER_H

#include "isr.h"

void timer_handler(registers_t *r);
void init_timer();
void timer_wait(int ticks);
void timer_phase(int hz);

#endif

