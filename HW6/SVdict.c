#include "SVdict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode* Tnode;
struct tnode { char key[MAXKEYLEN];
               void* val;
	       int height;
               Tnode left;
               Tnode right; };

struct sv_dict { Tnode root; };

Tnode makeTnode();
Tnode leftRotate(Tnode root);
Tnode rightRotate(Tnode root);

SVdict makeSVdict(){
        SVdict d = (SVdict) malloc(sizeof(struct sv_dict));
        Tnode n = (Tnode) malloc(sizeof(struct tnode));
        n->left = n->right = NULL;
        d->root = n;
        return d;
}

Tnode makeTnode(){
        Tnode n = (Tnode) malloc(sizeof(struct tnode));
        n->left = n->right = NULL;
        return n;
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}
 

void printTree(Tnode root){
	if(!root){ return; }
    	printTree(root->right);
        printf("%s has the key %p\n", root->key, root->val);
        printTree(root->left);
}

int height(Tnode root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(Tnode root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

Tnode minValue(Tnode root){
	if (!root->left){ return root; }
        else{ return minValue(root->left); }
}

Tnode insert(Tnode root, char* key, void* val){
	if(root == NULL){
        	Tnode newNode = makeTnode();
		strncpy(newNode->key, key, MAXKEYLEN);
		newNode->val = val;
		return newNode;
 	}
    if(strcmp(root->key, key) < 0)
        root->left  = insert(root->left, key, val);
    else
        root->right = insert(root->right, key, val);
 
    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);
  
    if (balance > 1 && strcmp(root->left->key, key) < 0)
        return rightRotate(root);
 
    if(balance < -1 && strcmp(root->right->key, key) > 0)
        return leftRotate(root);
 
    if(balance > 1 && strcmp(root->left->key, key) > 0){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    if(balance < -1 && strcmp(root->right->key, key) < 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}

void update(Tnode root, char* key, void* val){
        if(strcmp(root->key, key) < 0){ update(root->left, key, val); }

        else if(strcmp(root->key, key) > 0){ update(root->right, key, val); }

        else{ root->val = val; }
}

void* find(Tnode root, char* key){
	
	if(!root)
		return NULL;

        if(strcmp(root->key, key) < 0){ return find(root->left, key); }

        else if(strcmp(root->key, key) > 0){ return find(root->right, key); }

        else{ return root->val; }
}

int keyCheck(Tnode root, char* key){
        if(!root){
                printf("%s Not here\n", key);
                return 0;
        }

        else if(strcmp(root->key, key) < 0){
                return keyCheck(root->left, key);
        }

        else if(strcmp(root->key, key) > 0){
                return keyCheck(root->right, key);
        }

        else{
                return 1;
        }
}

void dispose(Tnode root){
	if(root){
		dispose(root->left);
		dispose(root->right);
		free(root);
	}
}

void disposeSVdict(SVdict d){
	dispose(d->root);
	free(d);
}

int hasKey(SVdict d, char* key){
        return keyCheck(d->root, key);
}

void* lookup(SVdict d, char* key){
	if(!hasKey(d, key))
		printf("%s Key not present", key);
        void* val = find(d->root, key);
        printf("%s has the key %p \n", key, val);
        return val;
}

Tnode rightRotate(Tnode root){
	Tnode temp = root->left;
	Tnode temp2 = temp->right;
	
	temp->height = max(height(root->left), height(root->right))+1;
    	root->height = max(height(temp->left), height(temp->right))+1;

	temp->right = root;
	root->left = temp2;
	
	return temp;
}

Tnode leftRotate(Tnode root){
	Tnode temp = root->right;
	Tnode temp2 = temp->left;

	root->height = max(height(temp->left), height(temp->right))+1;
    	temp->height = max(height(root->left), height(root->right))+1;

	temp->left = root;
	root->right = temp2;

	return temp;
}



int addOrUpdate(SVdict d, char* key, void* val){
	if(!hasKey(d, key)){ 
		printf("Adding %s\n", key);
		d->root = insert(d->root, key, val); 
		return 0;
	}
	else{
		printf("Updating %s \n", key);
		update(d->root, key, val);
		return 1;
	}
}

Tnode rm(Tnode root, char* key){
	if (root == NULL)
        	return root;
    	if(strcmp(root->key, key) < 0)
        	root->left = rm(root->left, key);
 
   	else if(strcmp(root->key, key) > 0)
        	root->right = rm(root->right, key);
    	else
    	{
        	if((root->left == NULL) || (root->right == NULL)){
            		Tnode temp = root->left ? root->left : root->right;
 
		if(temp == NULL){
                	temp = root;
                	root = NULL;
            	}
            	else
             		root = temp;
 
            	free(temp);
        	}
        	else{
            		Tnode temp = minValue(root->right);
 
            		strncpy(root->key, temp->key, MAXKEYLEN);

            		root->right = rm(root->right, temp->key);
        	}
    	}
 
    	if(root == NULL)
      		return root;
 
        root->height = max(height(root->left), height(root->right)) + 1;
	
	int balance = getBalance(root);
	
	if(balance > 1 && getBalance(root->left) >= 0)
        	return rightRotate(root);
 
	if(balance > 1 && getBalance(root->left) < 0){
        	root->left =  leftRotate(root->left);
        	return rightRotate(root);
    	}
 
    	if (balance < -1 && getBalance(root->right) <= 0)
        	return leftRotate(root);
 
    	if (balance < -1 && getBalance(root->right) > 0){
        	root->right = rightRotate(root->right);
        	return leftRotate(root);
   	 }

    return root;
}


int remKey(SVdict d, char* key){
	if(!hasKey(d, key)){ return 0; }
	
	else{ 
		rm(d->root, key);
		return 1;
	}
}

void preorderK(Tnode t, int indent) {
    for (int i = 0; i < indent; i++)
        printf(" "); /* print a blank of indentation */
    if (t != NULL) {
        printf("%s\n", t->key);
        preorderK(t->left, indent+1);
        preorderK(t->right, indent+1);
    } else 
        printf("*\n");
}

/* see SVdict.h */
void preorderKeys(SVdict d) {
    preorderK(d->root, 0);
	printf("\n %d \n", getBalance(d->root));
}

int main(){
	SVdict d = makeSVdict();
	addOrUpdate(d, "w", NULL);
	addOrUpdate(d, "c", NULL);
	addOrUpdate(d, "b", NULL);
	addOrUpdate(d, "p", NULL);
	addOrUpdate(d, "u", NULL);
	addOrUpdate(d, "v", NULL);
	addOrUpdate(d, "m", NULL);
	addOrUpdate(d, "i", NULL);
	addOrUpdate(d, "x", NULL);
	addOrUpdate(d, "n", NULL);
        addOrUpdate(d, "j", NULL);
        addOrUpdate(d, "k", NULL);
        addOrUpdate(d, "a", NULL);
        addOrUpdate(d, "t", NULL);
        addOrUpdate(d, "h", NULL);
        addOrUpdate(d, "s", NULL);
        addOrUpdate(d, "d", NULL);
	preorderKeys(d);
	remKey(d, "b");
	preorderKeys(d);
	remKey(d,"i");
	preorderKeys(d);
	disposeSVdict(d);
        return 0;
}
