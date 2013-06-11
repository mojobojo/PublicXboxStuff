#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned char *filebuf;
unsigned int filebuflen;

void decrypt()
{
	unsigned char *data = (filebuf + 0x22C);
	int i;
	for (i = 0; i < filebuflen - 0x22C; i++)
	{
		unsigned char a = data[i] ^ *((unsigned char*)filebuf + i % 0x101 + 296);
		data[i] = a ^ 0x7B;
	}
}

void outputfile(char *fname)
{
	FILE *f = fopen(fname, "wb");
	
	assert(f != 0);
	
	fwrite(filebuf, 1, filebuflen, f);
	
	fflush(f);
	fclose(f);
}

void mmap_buf(char *fname)
{
	FILE *f = fopen(fname, "rb");
	
	assert(f != 0);
	
	fseek(f, 0, SEEK_END);
	filebuflen = ftell(f);
	rewind(f);
	filebuf = calloc(1, filebuflen);
	fread(filebuf, 1, filebuflen, f);
	fclose(f);
	
	assert(filebuflen > 0 );
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("usage: bf3decrypt infile outfile\n", argv[0]);
		return 1;
	}
	
	mmap_buf(argv[1]);
	
	if (filebuf[0] != 0x00 && 
		filebuf[1] != 0xD1 && 
		filebuf[2] != 0xCE &&
		filebuf[3] != 0x00)
	{
		printf("Invalid File!\n");
		free(filebuf);
		return 1;
	}
	
	decrypt();
	outputfile(argv[2]);
	
	free(filebuf);
	return 0;
}
