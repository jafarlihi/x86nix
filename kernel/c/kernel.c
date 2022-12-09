#include "tty.h"
#include "multiboot.h"
#include "gdt.h"
#include "idt.h"
#include "irq.h"
#include "timer.h"
#include "ps2.h"
#include "printf.h"
#include <stdint.h>

void kernel_main(uint32_t mboot_magic, multiboot_info_t *mboot_header) {
    init_tty();

    if (mboot_magic != MULTIBOOT_BOOTLOADER_MAGIC) {
        tty_writestring("Error: We weren't booted by a compliant bootloader!\n");
        return;
    }

    if ((mboot_header->flags & (1<<6)) == 0) {
        tty_writestring("Error: No Multiboot memory map was provided!\n");
        return;
    }

    init_gdt();
    tty_writestring("GDT initialized\n");
    init_idt();
    tty_writestring("IDT initialized\n");
    init_irq();
    tty_writestring("IRQ initialized\n");

    timer_phase(100);
    init_timer();
    tty_writestring("Timer initialized\n");

    init_ps2();
    tty_writestring("Keyboard initialized\n");

    printf("Memory map:\n");
    for(int i = 0; i < mboot_header->mmap_length; i += sizeof(multiboot_memory_map_t)) {
        multiboot_memory_map_t *mmmt = (multiboot_memory_map_t *)(mboot_header->mmap_addr + i);

        printf("Start Addr: %x | Length: %x | Size: %x | Type: %d\n",
                (uint32_t)mmmt->addr, (uint32_t)mmmt->len, mmmt->size, mmmt->type);

        if(mmmt->type == MULTIBOOT_MEMORY_AVAILABLE) {
        }
    }

    while (1) {}
}

