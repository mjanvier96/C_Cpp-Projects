#include "my.h"

int my_revstr(char *str){
	int low = 0;/*starts at index 0 of char array*/
	int l = my_strlen(str);/*length of char array to get last index */
	int high = l - 1;/* last index */
	if(l > 1){
		while(high > low){/* simple swap */
			char tmp = str[low];
			str[low] = str[high];
			str[high] = tmp;
			low++;
			high--;
		}
	}
	return l;


}
