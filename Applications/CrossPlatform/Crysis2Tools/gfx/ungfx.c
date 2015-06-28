/*
2011  mojobojo
*/

#include <stdio.h>
#include <stdlib.h>
#include "zlib.h"

#define TOOL_VER  "1.1"
#define CFX_MAGIC "CFX\x0A"

typedef struct
{
	unsigned char magic[4];
	int   uncompressed_size;
} CFXHDR;

unsigned char  gfx_out_buf[0x3200000]; // 50mb should be enough
CFXHDR        *gfx_hdr;
unsigned char *gfx_buf;
unsigned int   gfx_buf_siz;


void loadtobuf(char *fname)
{
	FILE *f = fopen(fname, "rb");
	
	if (!f)
	{
		printf("Unable to open %s!\n", fname);
		exit(-1);
	}

	fseek(f, 0, SEEK_END);
	gfx_buf_siz = ftell(f);
	rewind(f);
	
	if (gfx_buf_siz <= 0)
	{
		printf("Size of the file is invalid!\n");
		fclose(f);
		exit(-1);
	}
	
	gfx_buf = (unsigned char*)malloc(gfx_buf_siz);
	fread(gfx_buf, 1, gfx_buf_siz, f);
	fclose(f);
}

void freeall()
{
	free(gfx_buf);
}

int decompresscfx()
{
	int ret;
	unsigned have;
	z_stream strm;

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = gfx_buf_siz - 8;
	strm.next_in = gfx_buf + 8;
	strm.avail_out = gfx_hdr->uncompressed_size;
	strm.next_out = gfx_out_buf;
	ret = inflateInit(&strm);
	if(ret != Z_OK)
		return ret;

	ret = inflate(&strm, Z_FINISH);

	(void)inflateEnd(&strm);
	return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

int loadcfx()
{
	gfx_hdr = (CFXHDR*)gfx_buf;
	if (memcmp(gfx_hdr->magic, CFX_MAGIC, 4) || gfx_hdr->uncompressed_size == 0)
	{
		printf("Bad file integrity!\n");
		exit(-1);
	}
	return 1;
}

void outputbin(char *fname)
{
	FILE *f = fopen(fname, "wb");
	if (!f)
	{
		printf("Unable to open output file %s!\n", fname);
		exit(-1);
	}
	
	fwrite(gfx_out_buf, 1, gfx_hdr->uncompressed_size - 8, f);
	fflush(f);
	fclose(f);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf(
			"ungfx "TOOL_VER" for Crysis 2, Copyright (C) 2011 mojobojo\n"
			"ungfx comes with ABSOLUTELY NO WARRANTY; This is free software,\n" 
			"and you are welcome to redistribute it under certain conditions;\n" 
			"go to \"http://www.gnu.org/licenses/gpl2.html\" for more information.\n\n"
			"Usage:\n"
			"	ungfx input.gfx output.bin\n"
		);
		exit(-1);
	}
	
	loadtobuf(argv[1]);
	loadcfx();
	decompresscfx();
	outputbin(argv[2]);
	freeall();
	
	printf("File successfully decompressed!\n");

	return 0;
}
