//Michael V Janvier

//I swewar that I have abided by the Stevens Honor System
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SIdict.h"

struct si_dict{
        int val;
        SIdict next;
        char* key;
};

SIdict makeSIdict(){
	SIdict d = (SIdict) malloc(sizeof(struct si_dict));
	d->next = NULL;
	return d;
}

int hasKey(SIdict d, char* key){
	while(d){
		if(strcmp(d->key, key) == 0){
			return 1;
		}
		else{ d = d->next; }
	}
	return 0;
}

int addOrUpdate(SIdict d, char* key, int val){
	assert(d != NULL);
	if(hasKey(d, key)){
		while(d){
                	if(strcmp(d->key, key) == 0){
                        	d->val = val;
				return 1;
                	}
			else{ d = d->next; }
		}
	}
	while(d->next){ d = d->next; }
	d->next = makeSIdict();
	d = d->next;
	d->key = key;
	d->val = val;
	return 0;
}

int lookup(SIdict d, char* key){
	while(d){
                if(strcmp(d->key, key) == 0){ return d->val; }
		d = d->next;
	}
}

int remKey(SIdict d, char* key){
	if(!hasKey(d, key)) { return 0; }
	
	SIdict temp = NULL;
	
	if(strcmp(d->key, key) == 0){ 
		temp = d->next;
		d->val = temp->val;
		d->key = temp->key;
		d->next = temp->next; 
	}
	else{
		while(d->next && !temp){
			if(strcmp(d->next->key, key) == 0){
				temp = d->next;
				d->next = d->next->next;
               		}
			else { d = d->next; }
		}
	}
        free(temp);
	return 1;
}

int main(){
	SIdict d;
	d = makeSIdict();
	d->key = "Mike";
	addOrUpdate(d, "Mike", 1);
	printf("ID for %s is %d \n", d->key, lookup(d, d->key));
	addOrUpdate(d, "Jack", 2);
	addOrUpdate(d, "Kevin", 3);
	addOrUpdate(d, "Max", 4);
	printf("Added Jack, Kevin and Max \n");
	printf("ID for Jack is %d \n", lookup(d, "Jack"));
	printf("ID for Kevin is %d \n", lookup(d, "Kevin"));
	printf("ID for Max is %d \n", lookup(d, "Max"));
	printf("Jack is %d in the dictionary \n",  hasKey(d, "Jack"));
	printf("Removing Jack... \n");
	printf("%d \n", remKey(d, "Jack"));
	printf("Jack is %d the dictionary\n",  hasKey(d, "Jack"));
	printf("Removing first entry Mike.. \n");
	remKey(d, "Mike");
	printf("Mike is %d in the dictionary \n", hasKey(d, "Mike"));	
	printf("Removing last from list Max \n");
	remKey(d, "Max");
	printf("Max is %d in the dictionary \n",  hasKey(d, "Max"));
	printf("Kevin is only one in the dictionary with id %d the dictionary \n",  lookup(d, "Kevin"));
	printf("Updating kevin with new id of 1... \n");
	addOrUpdate(d, "Kevin", 1);
	printf("ID for Kevin is %d \n", lookup(d, "Kevin"));
	printf("Adding Mike back into list with ID 42\n");
	addOrUpdate(d, "Mike", 42);
	printf("ID for Mike is %d \n", lookup(d, "Mike"));
	printf("Removing first entry Jack.. \n");
	remKey(d, "Jack");
	printf("Jack is %d the dictionary\n",  hasKey(d, "Jack"));
	return 0;
}



