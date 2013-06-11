#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bswap32(x) ((x << 24) & 0xff000000 ) | ((x <<  8) & 0x00ff0000 ) | ((x >>  8) & 0x0000ff00 ) | ((x >> 24) & 0x000000ff )

typedef struct {
	unsigned int Magic;
	unsigned int Unk0;
	unsigned int Unk1;
	unsigned int Unk2;
	unsigned int Unk3;
	unsigned int DataSize;
	unsigned int MagicXorSize;
} TwoWorldsHeader;

unsigned char TwoWorldsObfTable[32] = {
    0x36, 0xEF, 0x64, 0xBA, 
	0x43, 0x39, 0x09, 0xD4,
	0x5D, 0xE3, 0xEA, 0x6F, 
	0x43, 0x8D, 0xFF, 0x40, 
    0x03, 0x75, 0x94, 0x1C, 
	0x4B, 0xA2, 0xF9, 0x43,
	0x10, 0xDF, 0x66, 0x9C, 
	0x0C, 0x95, 0xED, 0xFE, 
} ;

unsigned int two_worlds_checksum(unsigned char* pbInp, unsigned int cbInp) {
	int x;
	unsigned int sig = 0;
	for (x = 0; x < cbInp; x++) {
		sig ^= (pbInp[x] ^ TwoWorldsObfTable[( x & 0x1f)]) << ((x << 3) & 0x18);
	}
	return sig;
}


int main(int argc, const char **argv) {
	unsigned int datasize;
	unsigned char *dataptr;
	unsigned char *temptr;
	TwoWorldsHeader *twh;
	FILE *f;

	if (argc < 2) {
		printf(
			"Use this application in CMD\n"
			"Usage: %s <filename>\n"
			"Press return to exit\n",
			argv[0]
			);
		getchar();
		return 0;
	}

	f = fopen(argv[1], "rb+");
	
	if (!f) {
		printf("Unable to open file '%s'\n", argv[1]);
		return 0;
	}

	fseek(f, 0, SEEK_END);
	datasize = ftell(f);
	rewind(f);

	temptr = (unsigned char*)malloc(4);
	dataptr = (unsigned char*)malloc(datasize);
	twh = (TwoWorldsHeader*)dataptr;
	

	fread(dataptr, 1, datasize, f);
	
	printf("File Magic: %08X\n", bswap32(twh->Magic));

	if (twh->Magic != 0x11087319) {
		printf("Invalid magic\n");
		fclose(f);
		return 0;
	}
	
	printf("Fixing Data size check...\n");
	
	fseek(f, 0x18, SEEK_SET);

	*(unsigned int*)temptr = twh->DataSize ^ twh->Magic;
	printf("Data Size XOR Magic: %08X\n", *(unsigned int*)temptr);

	fwrite(temptr, 1, sizeof(int), f);
	fflush(f);

	printf("Done\n");

	printf("Fixing data checksum...\n");
	dataptr += 0x1C;
	*(unsigned int*)temptr = bswap32(two_worlds_checksum(dataptr, bswap32(twh->DataSize)));
	printf("Data checksum: %08X\n", *(unsigned int*)temptr);

	fseek(f, datasize - 4, SEEK_SET);
	fwrite(temptr, 1, sizeof(int), f);
	fflush(f);

	printf("Done\n");
	fclose(f);

	return 0;
}