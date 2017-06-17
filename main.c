#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* (*memset_ptr)(void * str, int c, size_t n);
volatile memset_ptr memset_s = &memset;

size_t _strlen(const char * s);
size_t _strnlen(const char * s, size_t maxlen);

char* _strchr(const char * s, int c);
char* _strrchr(const char * s, int c);

size_t _strlcpy(char * d, const char * s, size_t dsize);

char * _strtolower(char * s, size_t len);
char * _strtoupper(char * s, size_t len);
char * _strshift(char * s, size_t len, int diff, int min, int max); 

int main() {

	/*Task #1*/
	/*unsigned char * pc = (unsigned char *)(&memset);
	*pc = 0x90;*/ // Seg fault, because of trying to write to const memory.

	/*Task #2*/

	/*memset_s((void*)memset_s,0,sizeof(memset_s));
	printf("%p\n",memset_s);*/ //Seg fault ?? don't know why

	char str[] = "QQQQQqwertyuiopasdfghjklzxcvbnm\0";

	printf("Length of str: %d\n",(int)_strlen(str));
	printf("Length of str (_strnlen(str,24)): %d\n",(int)_strnlen(str,24));

	if( _strchr(str,'a') )
		printf("'a' found!\n");
	if( _strrchr(str,'6'))
		printf("'6' found!\n");

	_strtoupper(str,15);
	printf("%s\n",str);
	_strtolower(str,10);
	printf("%s\n",str);

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

char * _strtolower(char * s, size_t len) {
	return _strshift(s,len,'a'-'A','A','Z');
}
char * _strtoupper(char * s, size_t len) {
	return _strshift(s,len,'A'-'a','a','z');
}
char * _strshift(char * s, size_t len, int diff, int min, int max) {
	int	i = 0;
	if(s) {
		while(s[i] && (i < len)) {
			if((s[i] >= min) && (s[i] <= max)) {
				//printf("s[i] = %c\n",s[i]);
				//printf("Before shift: %c\n",s[i]);
				//printf("%d\n",diff);
				s[i] += diff;
				//printf("After shift: %c\n",s[i-1]);
				//getchar();
			}
			i++;
		}
	}

	return s;
}

size_t _strlcpy(char * d, const char * s, size_t dsize) {
	int	i = 0,
		s_size = _strlen(s);
	for( i = 0 ; i <= ((dsize-1) < s_size ? dsize-1 : s_size) ; ++i ) {
		d[i] = s[i];
	}

	return s_size;
}
