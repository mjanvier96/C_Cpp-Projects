#include "my.h"

char* my_strcat(char* dst, char* src){
	if(dst && src){
		int length = my_strlen(dst);
		int i;
		for(i = 0; src[i] != '\0'; i++)
			dst[length + i] = src[i];
		dst[length + i] = '\0';
		return dst;
	}
	return NULL;
}
