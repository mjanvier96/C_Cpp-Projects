#include "my.h"

char* my_strconcat(char* a, char* b){
	
	if(a || b){
		int i = 0;
		int j = 0;
		if(!b){
			char* newStr = (char*)malloc(my_strlen(a));
			for(i = 0; a[i] != '\0'; i++)
				newStr[i] = a[i];
			newStr[i] = '\0';
			return newStr;
		}
		else if(!a){
			char* newStr = (char*)malloc(my_strlen(b));
                        for(i = 0; a[i] != '\0'; i++)
                                newStr[i] = b[i];
                        newStr[i] = '\0';
                        return newStr;
		}
		else{
			char* newStr = (char*)malloc(my_strlen(a) + my_strlen(b));
			for(i = 0; a[i] != '\0'; i++)
                                newStr[i] = a[i];
			j = i;
			for(i = 0; b[i] != '\0'; i++)
                                newStr[i + j] = b[i];
                        newStr[i + j] = '\0';
                        return newStr;
		}
	}

	return NULL;
}
