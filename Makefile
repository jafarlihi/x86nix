TARGET:=x86nix

CSOURCES:=./kernel/c
SSOURCES:=./kernel/s
HEADERS:=./kernel/h

BUILD:=./build

CC:=i686-elf-gcc
CFLAGS:=-std=gnu11 -O2 -ffreestanding -Wall -Wextra -nostdlib -lgcc -I$(HEADERS)

CFILES:=$(shell find $(CSOURCES) -printf '%P ' -name '*.c')
SFILES:=$(shell find $(SSOURCES) -printf '%P ' -name '*.s')
COFILES:=$(patsubst %.c,$(BUILD)/%.o,$(CFILES))
SOFILES:=$(patsubst %.s,$(BUILD)/%.o,$(SFILES))

.PHONY: build clean
.DEFAULT_GOAL:=build

build: mkdir $(COFILES) $(SOFILES)
	$(CC) -T linker.ld $(COFILES) $(SOFILES) -o $(TARGET) $(CFLAGS)

clean:
	rm -rf $(BUILD)
	rm -f x86nix
	rm -f x86nix.iso

mkdir:
	mkdir -p $(BUILD)

$(COFILES): $(BUILD)/%.o: $(CSOURCES)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SOFILES): $(BUILD)/%.o: $(SSOURCES)/%.s
	$(CC) $(CFLAGS) -c $< -o $@
