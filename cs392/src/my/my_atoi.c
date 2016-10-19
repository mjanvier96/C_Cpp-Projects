#include "my.h"

int my_atoi(char* str){
	if(str){
		const int neg = 45;
		const int low = 48;
		const int high = 57;
		int sign = 1;
		int i;
		int n = 0;
		for(i = 0; str[i] != '\0'; i++){
			if((int)str[i] == neg)
				sign = -sign;
			else if((int)str[i] >= low && (int)str[i] <= high){
				n += (int)str[i] - low;
				n *= 10;
			}
			else if(n){
				return ((n / 10) * sign);
			}
		}
		return ((n / 10) * sign);
	}
	return 0;
}
