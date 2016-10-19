#include "my.h"

char* my_strfind(char* str, char c){
	if(str){
		int i;
		for(i = 0; str[i]; i++){
			if(str[i] == c)
				return &str[i];
			}
	}
	return NULL;
}
