#include "my.h"

char* my_strdup(char* str){
	if(str){
		int i;
		char* newStr = (char*)malloc(my_strlen(str));
		for(i = 0; str[i]; i++)
			newStr[i] = str[i];
		newStr[i] = '\0';
		return newStr;
	}
	return NULL;
}
