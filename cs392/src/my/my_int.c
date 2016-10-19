#include "my.h"

/*
int count - offset for chopping first digit off
int tmp - holds original n value but used for chopping digits off for printing
int n - integer to be printed
char c - char version of digit to be printed
*/

void my_int(int n){
	int tmp, count;
	char c;
	const char neg = '-';
	if(!n){/* checks if original integer is zero */
		c = '0' + 0;
		write(1, &c, 1);/* writes 0 */
	}
	else if(n < 0){/* checks for neg value and always makes number positive */
		n = -n;
		write(1, &neg, 1);/* prints neg sign */
	}
	while(n){
		count = 1;/* offset starts at first digit */
		tmp = n;
		while(tmp > 10){ /* divides by ten until down to first digit*/
			tmp /= 10;
			count *= 10;
		}

		c = '0' + tmp;
		write(1, &c, 1);
		n = n % (tmp * count); /* chops off first digit using the offset */
	}
	return;	
}
