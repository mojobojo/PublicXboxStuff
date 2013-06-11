
typedef struct _somedata
{
	char *str;
	int val;
	unsigned char arr[16];
} somedata;

unsigned char *cp = "Hello World!";
int x = 10;
somedata some;

extern void afunctocall(char *c);

void memcpy(void *dest, void *src, int size)
{
	unsigned char *a = dest, *b = src;
	while (size--)
		*a++ = *b++;
}

int main()
{
	some.str = cp;
	some.val = x * 5;
	memcpy(some.arr, some.str, 12);
	
	afunctocall(some.arr);
	return 0;
}
