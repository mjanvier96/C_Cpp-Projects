#include "my.h"

int my_strlen(char * str){
	if(str){
		int i = 0;
		while(str[i])/* iterate through string keeping track of index */
			i++;
		return i;
	}
	return -1;/* return -1 if not valid input */
}	
