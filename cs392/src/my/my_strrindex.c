#include "my.h"

int my_strrindex(char *str, char c){
	int i, index = 0;
        if(str){/* iterates through array keeping index of last matching char */
                for(i = 0; str[i]; i++)
                        if(str[i] == c) index = i + 1;/* offsets by 1 to make returning -1 for errors simple */
        }
        return (index - 1);/* correct offset */
}

