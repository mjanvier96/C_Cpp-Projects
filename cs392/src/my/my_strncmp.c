#include "my.h"

int my_strncmp(char* a, char* b, int n){
	int i;
		
	if(0 >= n)
		return 0;

        if(!a && !b)
                return 0;

        if(!a)
                return (0 - (int)a[0]);

        if(!b)
                return b[0];

        for(i = 0; a[i] && a[i] == b[i]; i++){}
        return a[i] - b[i];
}

