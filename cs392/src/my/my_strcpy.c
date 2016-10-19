#include "my.h"

char* my_strcpy(char* dst, char* src){
	int i = 0;
	if(dst && src){
		for(i = 0; src[i] && src[i] != '\0'; i++)
			dst[i] = src[i];
		dst[i] = '\0';
		return dst;
	}
	return NULL;
}
