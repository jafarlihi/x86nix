#ifndef ISR_H
#define ISR_H

#include <stdint.h>

typedef struct registers {
    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
} registers_t;

void isr_handler(registers_t *regs);
void isr_install_handler(int32_t isr, void (*handler)(registers_t *r));
void isr_uninstall_handler(int32_t isr);

#endif

