#include <stdio.h>
#include <string.h>

int main() {
	unsigned char * pc = (unsigned char *)(&memset);
	*pc = 0x90;

	return 0;
}
