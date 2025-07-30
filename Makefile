ASM=nasm
CC=gcc
LD=ld
CFLAGS=-m32 -ffreestanding -nostdlib -Wall -Ikernel

all: cherryktest.iso

bootloader.bin:
	$(ASM) boot/boot.asm -f bin -o bootloader.bin

kernel.o: kernel/*.c kernel/ktest.h
	$(CC) -m32 -ffreestanding -nostdlib -c kernel/*.c

kernel.bin: kernel.o
	$(LD) -m elf_i386 -T linker.ld -o kernel.elf kernel/*.o
	objcopy -O elf32-i386 -R .note -R .comment -S kernel.elf kernel.bin

cherryktest.iso: bootloader.bin kernel.bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/
	cp iso/grub.cfg isodir/boot/grub/
	grub-mkrescue -o cherryktest.iso isodir

run: cherryktest.iso
	qemu-system-i386 -cdrom cherryktest.iso

clean:
	rm -rf *.bin *.iso *.o *.elf isodir kernel/*.o
