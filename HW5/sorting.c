#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int binarySearch(char* arr[], int search, int l, int r){
	int mid;
	while(l <= r){
		mid = (l + r) / 2;	
		if(strcmp(arr[search], arr[mid]) > 0){
			l = mid + 1;
		}
		else if(strcmp(arr[search], arr[mid]) < 0){
			r = mid - 1;
		}
		else{ return mid + 1; }
	}
	return l;
}

void insertionsort(char* arr[], int l, int r){
	int insert, i, j;
	char* temp;
	for(i = l + 1; i < r; i++){
		insert = binarySearch(arr, i, l, i - 1);
		char* val = arr[i];
		for(j = i - 1; j >= insert; j--){
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = val;
	}
}

void quicksortHelp(char* arr[], int l, int r){
	int left, right, pivot;
        char* temp;

        if(l <= r){
                pivot = l;
                left = l;
                right = r;

                while(left < right){
                        while((strcmp(arr[left], arr[pivot]) <= 0) && left < r){
                                left++;
                        }
                        while((strcmp(arr[right], arr[pivot]) > 0)){
                                right--;
                        }
                        if(left < right){
                                temp = arr[left];
                                arr[left] = arr[right];
                                arr[right] = temp;
                        }
                }
                temp = arr[pivot];
                arr[pivot] = arr[right];
                arr[right] = temp;
                quicksortHelp(arr, l, right - 1);
                quicksortHelp(arr, right + 1, r);
        }
}

void quicksort(char* arr[], int l, int r){
	quicksortHelp(arr, l, r - 1);
}

void swap1(char* arr[], int l, int r){
	char* temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

void quicksortPlusHelp(char* arr[], int l, int r){
	if((r - 1) <= 10){
                insertionsort(arr, l, r);
        }
        else{
                int left, right, pivot;
                char* temp;

                if(l <= r){
                        if(strcmp(arr[r], arr[l]) < 0){ swap1(arr, l, r); }
                        if(strcmp(arr[(l + r) / 2], arr[l]) < 0){ swap1(arr, (l + r) / 2, l); }
                        if(strcmp(arr[r], arr[(l + r) / 2]) < 0){ swap1(arr, r, (l + r) / 2); }
                        pivot = (l + r) / 2;
                        left = l;
                        right = r;

                        while(left < right){
                                while((strcmp(arr[left], arr[pivot]) <= 0) && left < r){
                                        left++;
                                }
                                while((strcmp(arr[right], arr[pivot]) > 0)){
                                        right--;
                                }
                                if(left < right){
                                        temp = arr[left];
                                        arr[left] = arr[right];
                                        arr[right] = temp;
                                }
                        }
                temp = arr[pivot];
                arr[pivot] = arr[right];
                arr[right] = temp;
                quicksortPlusHelp(arr, l, right - 1);
                quicksortPlusHelp(arr, right + 1, r);
                }
        }
}

void quicksortPlus(char* arr[], int l, int r){
	quicksortPlusHelp(arr, l, r - 1);
}

void compareSorts(char* arr[], int len){
	clock_t start, end;
	start = clock();
	int q = 1;
	int i;
	for(i = 0; i < 20; i++){
		char** a = (char**) malloc(len * sizeof(char*));
		int j;
		for(j = 0; j < len; j++){
			a[j] = (char*) malloc(sizeof(sizeof(*arr[j])));
			strcpy(a[j], arr[j]);
		}
		insertionsort(a, 0, 25);
	}
	end = clock();
	printf("\nThe total time to sort the array 20 times with Insertion Sort took %f milliseconds\n", ((double)end - (double)start / CLOCKS_PER_SEC));

	start = clock();
	for(i = 0; i < 20; i++){
		char** a = (char**) malloc(len * sizeof(char*));
		int j;
		for(j = 0; j < len; j++){
			a[j] = (char*) malloc(sizeof(sizeof(*arr[j])));
                        strcpy(a[j], arr[j]);
                }
		quicksort(a, 0, 25);
        }
	end = clock();
	printf("\nThe total time to sort the array 20 times with Quicksort took %f milliseconds\n", ((double)end - (double)start / CLOCKS_PER_SEC));
	
	start = clock();
	for(i = 0; i < 20; i++){
		char** a = (char**) malloc(len * sizeof(char*));
		int j;
		for(j = 0; j < len; j++){
			a[j] = (char*) malloc(sizeof(sizeof(*arr[j])));
                        strcpy(a[j], arr[j]);
                }
		quicksortPlus(a, 0, 25);
        }
	end = clock();
	printf("\nThe total time to sort the array 20 times with Quicksort Plus took %f milliseconds\n", ((double)end - (double)start / CLOCKS_PER_SEC));
}
/*
int main(){
	char* alph1[] = {
	"i", "v", "a", "k", "j", "b", "r", "o", "m", "u", "h", "d", "x", "p", 
	"s", "y", "t", "f", "e", "n", "c", "g", "z", "l", "w", "q"};

	insertionsort(alph1, 0, 26);
	printf("\nBinary Insertion Sort\n");	
	int i;
	for(i = 0; i < 26; i++){
		printf("%s\n", alph1[i]);
	}
	char* alph2[] = {
        "i", "v", "a", "k", "j", "b", "r", "o", "m", "u", "h", "d", "x", "p",
        "s", "y", "t", "f", "e", "n", "c", "g", "z", "l", "w", "q"};
	quicksort(alph2, 0, 26);
	printf("QuickSort\n");
	for(i = 0; i < 26; i++){
                printf("%s\n", alph2[i]);
        }
	
	char* alph3[] = {
        "i", "v", "a", "k", "j", "b", "r", "o", "m", "u", "h", "d", "x", "p",
        "s", "y", "t", "f", "e", "n", "c", "g", "z", "l", "w", "q"};
        quicksortPlus(alph3, 0, 26);
        printf("QuickSort Plus\n");
        for(i = 0; i < 26; i++){
                printf("%s\n", alph3[i]);
        }
	
	char* alph4[] = {
        "i", "v", "a", "k", "j", "b", "r", "o", "m", "u", "h", "d", "x", "p",
        "s", "y", "t", "f", "e", "n", "c", "g", "z", "l", "w", "q"};

	compareSorts(alph4, 26);
	
	printf("\n%ld\n", clock());
	return 0;
}*/
