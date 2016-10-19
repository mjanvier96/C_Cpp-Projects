#include "my.h"

void my_str(char* c){
	if(c)
		while(*c){/* iterates through string while pointer is valid */
			write(1, c, 1);
			c++;
		}
	return;
}
