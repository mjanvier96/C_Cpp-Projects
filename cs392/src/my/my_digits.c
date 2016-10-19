#include "my.h"

void my_digits(){
	short i;/*stores ascii value of decimal based digits*/
        for(i = 48; i < 58; i++){/*iterates through digits according to ascii standard*/
                char c = i;/* explicit conversion to char*/
                my_char(c);
        }

}
