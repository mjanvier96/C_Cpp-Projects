#include "my.h"

/*
int b - the base to be converted to
int tmp - copy of n that is used for calculations
int low - starts at the base and is multiplied by base and the most recent value calculated (see code for more)
*/

void my_num_base(int n, char* c){
	const char err[] = "Invalid Base";
	if(c && *c){/* checks that pointer is valid and that data is not empty */
		int b, tmp, low;
        	char print;
        	const char neg = '-';
		b = 0;
		while(c[b]) b++;/* get the base by finding char array length */
		low = b;
		if(!n){/* checks for zero */ 
                	write(1, &(c[0]), 1);
        	}
        	else if(n < 0){/*checks for neg */
                	n = -n;
                	write(1, &neg, 1);
        	}
        	while(n){
			if(1 == b){/* incase of base 1 uses simple method to write only char n times */
				write(1, &(c[0]), 1);
				n--;
			}
			else{
				tmp = n;
                		while(tmp >= low){/* low is the line that tells when to stop since the digits have to be calculated backwards to be printed correctly */
                        		tmp /= b;
                		}
				low = b + (tmp * b);/* new low is just above previous low * base */
                		print = c[tmp % b];
                		write(1, &print, 1);
				if((low - b) > n) return; /* checks for completion via low being greater than n by atleast b */
			}
		}
	} else {
		int i;
		for(i = 0; err[i]; i++)
			write(1, &err[i] ,1);/* writes error message */
	}
	return;
}
