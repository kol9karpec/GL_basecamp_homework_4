#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* (*memset_ptr)(void * str, int c, size_t n);
volatile memset_ptr memset_s = &memset;

size_t _strlen(const char * s);
size_t _strnlen(const char * s, size_t maxlen);

char* _strchr(const char * s, int c);
char* _strrchr(const char * s, int c);


int main() {

	/*Task #1*/
	/*unsigned char * pc = (unsigned char *)(&memset);
	*pc = 0x90;*/ // Seg fault, because of trying to write to const memory.

	/*Task #2*/

	/*memset_s((void*)memset_s,0,sizeof(memset_s));
	printf("%p\n",memset_s);*/ //Seg fault ?? don't know why

	char str[] = "qwertyuiopasdfghjklzxcvbnm\0";

	printf("Length of str: %d\n",(int)_strlen(str));
	printf("Length of str (_strnlen(str,24)): %d\n",(int)_strnlen(str,24));

	if( _strchr(str,'a') )
		printf("'a' found!\n");
	if( _strchr(str,'6'))
		printf("'6' found!\n");

	return 0;
}

size_t _strlen(const char * s) {
	size_t 	result = 0,
		i = 0;

	while(s[i++]) {
		result++;
	}


	return result;
}

size_t _strnlen(const char * s, size_t maxlen) {
	size_t	result = 0,
		i = 0;

	while(s[i] && i < maxlen) {
		result++;
		i++;
	}


	return result;
}

char* _strchr(const char * s, int c) {
	char	*result = NULL;
	int 	i = 0;

	while(s[i]) {
		if((int)s[i] == c) {
			result = (char*)(&s[i]);
		}
		i++;
	}
	return result;
}

char* _strrchr(const char * s, int c){
	char	*result = NULL;
	int 	i = _strlen(s)-1;

	while(s[i]) {
		if((int)s[i] == c) {
			result = (char*)(&s[i]);
		}
		i--;
	}
	return result;
}


