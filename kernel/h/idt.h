#ifndef IDT_H
#define IDT_H

typedef struct idt_ptr {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed)) idt_ptr_t;

extern idt_ptr_t idt_ptr;

void init_idt();
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

#endif

