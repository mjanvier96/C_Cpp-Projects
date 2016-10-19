#include "my.h"

void my_alpha(){
	short i;/*stores ascii value of alphabet*/
	for(i = 65; i < 91; i++){/*iterates through all the letters according to ascii standard*/
		char c = i;/* explicit conversion to char */ 
		my_char(c);
	}
}
