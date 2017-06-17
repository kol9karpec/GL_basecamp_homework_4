#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* (*memset_ptr)(void * str, int c, size_t n);

volatile memset_ptr memset_s = &memset;

int main() {

	/*Task #1*/
	/*unsigned char * pc = (unsigned char *)(&memset);
	*pc = 0x90;*/ // Seg fault, because of trying to write to const memory.

	/*Task #2*/

	/*memset_s((void*)memset_s,0,sizeof(memset_s));
	printf("%p\n",memset_s);*/ //Seg fault ?? don't know why

	return 0;
}
