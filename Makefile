
GPPFLAGS = -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti
ASFLAGS = 
LDFLAGS = -ffreestanding -O2 -nostdlib -lgcc
OBJS = loader.o kernel.o gdt.o port.o tty.o

%.o: %.cpp
	i686-elf-g++ $(GPPFLAGS) -o $@ -c $<

%.o: %.s
	i686-elf-as $(ASFLAGS) -o $@ $<

vide: linker.ld $(OBJS)
	i686-elf-gcc $(LDFLAGS) -T $< -o $@ $(OBJS)

petrichor.iso: vide
	mkdir -p isodir/boot/grub
	cp vide isodir/boot/vide
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub2-mkrescue -o petrichor.iso isodir

run: petrichor.iso
	qemu-system-i386 petrichor.iso

.PHONY: clean
clean:
	rm $(OBJS)
	rm vide
	rm petrichor.iso
	rm -r isodir