#include "my.h"

int my_strindex(char *str, char c){
	if(str){
		int i;
		for(i = 0; str[i]; i++)/* finds first instance and returns index */
			if(str[i] == c) return i;
	}
	return -1;/* if loops through whole string or str isn't valid return -1 */
}
