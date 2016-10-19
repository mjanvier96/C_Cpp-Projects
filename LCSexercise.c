#include <stdio.h>
#include <string.h>

int max(int x, int y){
	if (x >= y) return x;
    	else return y;
}

int lcs(char* X, char* Y, int m, int n){
	int L[m + 1][n + 1]; 
   	for(int i = 0; i <= m; i++){
    		for(int j = 0; j <= n; j++){
       			if(i == 0 || j == 0)
         			L[i][j] = 0;
       			else if (X[i - 1] == Y[j - 1])
         			L[i][j] = L[i - 1][j - 1] + 1;
       			else
         			L[i][j] = max(L[i - 1][j], L[i][j - 1]);
     		}
   	}	

	int index = L[m][n];
 
	char lcs[index + 1];
   	lcs[index] = '\0'; // Set the terminating character
 
   	// Start from the right-most-bottom-most corner and
   	// one by one store characters in lcs[]
   	int i = m, j = n;
   	while (i > 0 && j > 0){
      	// If current character in X[] and Y are same, then
      	// current character is part of LCS
      	if (X[i - 1] == Y[j - 1]){
          	lcs[index - 1] = X[i - 1]; // Put current character in result
          	i--; j--; index--;     // reduce values of i, j and index
      	}
 
      	// If not same, then find the larger of two and
     	// go in the direction of larger value
      	else if (L[i - 1][j] > L[i][j - 1])
         	i--;
      	else
         	j--;
   	}
	return strlen(lcs);
}

int LCS(char* a, char* b){
	return lcs(a, b, strlen(a), strlen(b));
}

int main(){
	char* a = "AGGACAT";
    char* b = "ATTACGAT";
    printf("first test returns %i, should be 5 \n", LCS(a,b));

    a = "AAGCTTAAGAAGCCTTCAACAGG";
    b = "GGGTTTGGCATGTCCTTGACCAT";
    printf("second test returns %i, should be 14 \n", LCS(a,b));

    a = "ATCTGTGGTGGAAAGGCTAACATACC";
    b = "CAAGAAATGTTAACTCAGAGTTGT";
    printf("third test returns %i, should be 12 \n", LCS(a,b));
	}
