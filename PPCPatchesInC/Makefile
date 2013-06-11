
all:
	xenon-gcc -c -m32 start.S -o start.o
	xenon-gcc -c -mno-toc -m32 -O2 -W -Wall -G 0 -fomit-frame-pointer ppc.c -o ppc.o
	xenon-ld -melf32ppc -o ldsf.elf start.o ppc.o -T ppc.ld
	xenon-objcopy ldsf.elf ppc.bin -O binary
	
clean:
	rm -f *.o ppc.bin ldsf.elf
