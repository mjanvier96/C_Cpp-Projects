#include "my.h"


char* my_strrfind(char* str, char c){
	int i;
	int index = -1;
	if(str){
		for(i = 0; str[i]; i++){
			if(str[i] == c)
				index = i + 1;
		}
	}
	if(index > 0)
		return &str[index - 1];
	return NULL;
}
