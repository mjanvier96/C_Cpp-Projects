#ifndef _MY_H_ 
#define _MY_H_

#ifndef NULL 
#define NULL ((void*)0) 
#endif

#include <unistd.h> 
#include <stdlib.h>

void my_char(char); 
void my_str(char*); 
void my_int(int); 
void my_num_base(int, char* base); 
void my_alpha(); 
void my_digits();
int my_strlen(char*); 
int my_revstr(char*); 
int my_strindex(char*, char); 
int my_strrindex(char*, char);

char* my_strfind(char*, char);
/*Returns a pointer to the first char in the string which matches.
Return NULL if the letter is not found.*/

char* my_strrfind(char*, char);
/*Returns a pointer to the last char in the string which matches.
Return NULL if the letter is not found.*/

int my_strcmp(char *a, char *b); 
/* Compares strings by ascii value
 If a and b are identical, return 0. 
 if a < b, return negative number 
 if a > b, return positive number
 Two NULL are equal.
 NULL is always less than a normal string*/

int my_strncmp(char*a, char *b, int n); 
/* Same as my_strcmp except:
 Only compares n chars or until the end of a string*/

char *my_strcpy(char *dst, char *src); 
/* Copies the characters from src into dst overwriting what's already in there.
 Always copies a '\0'
 Assumes dst has enough memory allocated for the new string if it is longer.
 Does not allocate memory*/

char *my_strncpy(char *dst, char *src, int n);
/* Same as my_strcpy except:
 Only copies n chars or until the end of src*/

char *my_strcat(char *dst, char *src); 
/* Copies src onto the end of dst and returns dst
 Does not allocate memory
 Assumes there is enough memory allocated in dst to hold both strings
 Overwrites src's original '\0' and places a new '\0' onto the end*/
 
char *my_strdup(char *str); 
/* Allocates new memory 
 Copies str into that new memory 
 returns pointer to new string*/

char *my_strconcat(char *a, char *b); 
/* Allocates new memory 
 Copies concatenated strings in that new memory 
 Returns pointer to it
 If both NULL return NULL*/

char *my_strnconcat(char *a, char *b, int n); 
/* Same as my_strconcat except:
 Copies all of a and then n chars or length of b*/

int my_atoi(char*); 
/* Returns the int represented by the ascii string
 Handles negatives.
 Ignores preceding characters and trailing numbers and chars
 Examples:
 "5" => 5
 "-5" => -5
 "--5" => 5
 "a-b54sc7-d" => -54
 "abcd" => 0 */

#endif
