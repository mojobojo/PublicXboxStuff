/*
Copyright (C) 2011  mojobojo

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; only version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
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
unsigned int   gfx_cp_siz = 0x3200000;

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

int compresscfx()
{
	int ret;
	unsigned have;
	z_stream strm;

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = gfx_buf_siz;
	strm.next_in = gfx_buf;
	strm.avail_out = gfx_cp_siz;
	strm.next_out = gfx_out_buf;
	ret = deflateInit(&strm, 9);
	if(ret != Z_OK)
		return ret;

	ret = deflate(&strm, Z_FINISH);
	gfx_cp_siz -= strm.avail_out;

	(void)deflateEnd(&strm);
	return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

void makegfxhdr()
{
	gfx_hdr = (CFXHDR*)malloc(8);
	memset(gfx_hdr, 0, 8);
	memcpy(gfx_hdr->magic, CFX_MAGIC, 4); 
	gfx_hdr->uncompressed_size = gfx_buf_siz + 8;
}

void outputgfx(char *fname)
{
	FILE *f = fopen(fname, "wb");
	if (!f)
	{
		printf("Unable to open output file %s!\n", fname);
		exit(-1);
	}

	fwrite(gfx_hdr, 1, 8, f);
	fwrite(gfx_out_buf, 1, gfx_cp_siz, f);
	fflush(f);
	fclose(f);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf(
			"regfx "TOOL_VER" for Crysis 2, Copyright (C) 2011 mojobojo\n"
			"regfx comes with ABSOLUTELY NO WARRANTY; This is free software,\n" 
			"and you are welcome to redistribute it under certain conditions;\n" 
			"go to \"http://www.gnu.org/licenses/gpl2.html\" for more information.\n\n"
			"Usage:\n"
			"	regfx input.bin output.gfx\n"
		);
		exit(-1);
	}
	
	loadtobuf(argv[1]);
	compresscfx();
	makegfxhdr();
	outputgfx(argv[2]);
	freeall();
	
	printf("File successfully compressed!\n");

	return 0;
}
