#!/usr/bin/env bash

make

mkdir -p build/isodir
mkdir -p build/isodir/boot
mkdir -p build/isodir/boot/grub

cp x86nix build/isodir/boot/x86nix
cat > build/isodir/boot/grub/grub.cfg << EOF
menuentry "x86nix" {
	multiboot /boot/x86nix
}
EOF
grub-mkrescue -o x86nix.iso build/isodir

