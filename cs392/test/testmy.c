#include "my.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>


int main(int argc, char **argv){
	/*int i = 0;
	char str[] = "abcdef";
	char str2[] = "";
	char str3[] = "ABABABAB";
	char str4[] = "s";
	while(i < 101){
		i++;
		if(!(i % 3) && !(i % 5)){
			my_char('F');
			my_char('B');
			my_char('\n');
		}
		else if(!(i % 3)){
			my_char('F');
			my_char('\n');
		}
		else if(!(i % 5)){
			my_char('B');
			my_char('\n');
		}
		else{ printf("%d\n", i); } 
	}
	my_str(str);
	my_char('\n');
	my_str(NULL);
	my_str(str2);
	my_char('\n');
	my_int(1234 - 100000);
	my_char('\n');
	my_int(124334);
	my_char('\n');
	my_int(0);
	my_char('\n');
	my_num_base(9, "RTFM");
	my_char('\n');
	my_num_base(910, "RTFM");
        my_char('\n');
	my_num_base(5, "K");
        my_char('\n');
	my_num_base(1111111, "0123456789ABC");
        my_char('\n');
        my_num_base(0, "RTFM");
        my_char('\n');
        my_num_base(64, "01234567");
        my_char('\n');
	my_num_base(64, NULL);
        my_char('\n');
	my_alpha();
	my_char('\n');
	my_digits();
	my_char('\n');
	my_int(my_strindex(str, 'e'));
	my_char('\n');
	my_int(my_strindex(str, 'z'));
        my_char('\n');
	my_int(my_strindex(NULL, 'a'));
        my_char('\n');
	my_int(my_strrindex(str, 'a'));
        my_char('\n');
        my_int(my_strrindex(str3, 'Z'));
        my_char('\n');
        my_int(my_strrindex(NULL, 'A'));
        my_char('\n');
	my_int(my_strlen(str));
	my_char('\n');
	my_int(my_strlen(str2));
        my_char('\n');
	my_int(my_strlen(str3));
        my_char('\n');
	my_revstr(str);
	my_str(str);
        my_char('\n');
        my_int(my_revstr(NULL));
	my_char('\n');
        my_int(my_revstr(str2));
	my_char('\n');
	my_revstr(str3);
	my_revstr(str4);
	my_str(str3);
	my_char('\n');
	my_str(str4);
        my_char('\n');
	*/
	
	printf("Testing my_str()\n");
  my_str(NULL); printf("\n");
  my_str(""); printf("\n");
  my_str("test"); printf("\n");
  printf("\nTesting my_int()\n");
  my_int(0); printf("\n");
  my_int(-1); printf("\n");
  my_int(1); printf("\n");
  my_int(10); printf("\n");
  my_int(-10); printf("\n");
  my_int(INT_MAX); printf("\n");
  my_int(INT_MIN); printf("\n");
  my_int(-0); printf("\n");
  printf("\nTesting my_num_base()\n");
  my_num_base(1, NULL); printf("\n");
  my_num_base(1, ""); printf("\n");
  my_num_base(1, "A"); printf("\n");
  my_num_base(-1, "A"); printf("\n");
  my_num_base(9, "RTFM"); printf("\n");
  my_num_base(32, "HELLO WORLD"); printf("\n");
  printf("\nTesting my_alpha()\n");
  my_alpha(); printf("\n");
  printf("\nTesting my_digits()\n");
  my_digits(); printf("\n");
  printf("\nTesting my_strlen()\n");
  assert(my_strlen("") == my_strlen(""));
  assert(my_strlen("Andrew") == my_strlen("Andrew"));
  assert(my_strlen("Andrew O'Brien") == my_strlen("Andrew O'Brien"));
  assert(my_strlen("the quick brown fox jumps over the lazy dog") == my_strlen("the quick brown fox jumps over the lazy dog"));
  printf("\nTesting my_revstr()\n");
  char str1[] = "Andrew";
  my_revstr(str1);
  printf("%s\n", str1);
  char str2[] = "the quick brown fox jumps over the lazy dog";
  my_revstr(str2);
  printf("%s\n", str2);
  char str3[] = "";
  my_revstr(str3);
  printf("%s\n", str3);
  char str4[] = "aaaabbbb";
  my_revstr(str4);
  printf("%s\n", str4);
  printf("\nTesting my_strindex()\n");
  printf("%d\n", my_strindex("O'Brien Andrew", 'A'));
  printf("%d\n", my_strindex("the quick brown fox jumps over the lazy dog", 'g'));
  printf("%d\n", my_strindex("the quick brown fox jumps over the lazy do", 'g'));
  printf("\nTesting my_strrindex()\n");
  printf("%d\n", my_strrindex("O'Brien Andrew A", 'A'));
  printf("%d\n", my_strrindex("the quick brown fox jumps over the lazy dog", 'g'));
  printf("%d\n", my_strrindex("the quick brown fox jumps over the lazy do       g", 'g'));
  printf("%d\n", my_strrindex("the quick brown fox jumps over the lazy do", 'g')); 

  printf("\nTesting my_strfind()\n");
  assert(my_strfind(NULL, 'a') == NULL);
  assert(my_strfind("Andrew", '\0') == NULL);
  assert(my_strcmp(my_strfind("Andrew", 'd'), "drew") == 0);
  assert(my_strcmp(my_strfind("the quick brown fox jumps over the lazy dog", 'd'), "dog") == 0);
  printf("\nTesting my_strrfind()\n");
  assert(my_strrfind(NULL, 'a') == NULL);
  assert(my_strrfind("Andrew", '\0') == NULL);
  assert(my_strcmp(my_strrfind("Andrew", 'd'), "drew") == 0);
  assert(my_strcmp(my_strrfind("i like to make funny noises", 'i'), "ises") == 0);
  printf("\nTesting my_strcmp()\n");
  assert(my_strcmp(NULL, NULL) == 0);
  assert(my_strcmp("", "") == 0);
  assert(my_strcmp("a","b") < 0);
  assert(my_strcmp("b","a") > 0);
  printf("\nTesting my_strncmp()\n");
  assert(my_strncmp(NULL, NULL, 1) == 0);
  assert(my_strncmp("", "", 1) == 0);
  assert(my_strncmp("a","b", 1) < 0);
  assert(my_strncmp("b","a", 1) > 0);
  assert(my_strncmp("hUSTQTsHZC", "woitYJLCcJ", -1) == 0);
  assert(my_strncmp("hUSTQTsHZC", "woitYJLCcJ", 1) < 0);
  printf("\nTesting my_strcpy()\n");
  char str5[]="Sample string";
  char str6[40];
  my_strcpy(str6,str5);
printf("%s%s", str5, str6);
  assert(strcmp(str5, str6) == 0);
  char str7[]="";
  char str8[] = "Sample string";
  my_strcpy(str8,str7);
  assert(strcmp(str7, str8) == 0);
  char str9[]="Andrew O'Brien";
  char str10[] = "werdnA neirB'O";
  my_strcpy(str10,str9);
  assert(strcmp(str9, str10) == 0);
  my_strcpy(NULL, NULL);
  printf("\nTesting my_strncpy()\n");
  char str11[]="Sample string";
  char str12[40];
  int n1 = 0;
  my_strncpy(str12,str11, n1);
  assert(my_strncmp(str12, str11, n1) == 0);
  char str13[]="";
  char str14[40] = "Sample string";
  int n2 = 10;
  my_strncpy(str14,str13, n2);
  assert(my_strncmp(str14, str13, n2) == 0);
  char str15[]="Andrew O'Brien";
  char str16[] = "werdnA neirB'O";
  int n3 = 14;
  my_strncpy(str15,str16, n3);
  assert(my_strncmp(str15, str16, n2) == 0);
  my_strncpy(NULL, NULL, 0);
  printf("\nTesting my_strcat()\n");
  char str17[60];
  strcpy(str17, "Andrew");
  char str18[] = " O'Brien";
  char *str19 = my_strcat(str17, str18);
  assert(my_strcmp(str19, "Andrew O'Brien") == 0);
  char *str31 = NULL;
  char str32[] = " O'Brien";
  char *str33 = my_strcat(str31, str32);
  assert(str33 == NULL);
  my_strcat(NULL, NULL);
  printf("\nTesting my_strdup()\n");
  char *str30 = my_strdup(NULL);
  assert(my_strcmp(str30, NULL) == 0);
  char str20[] = "Andrew O'Brien";
  char *str21 = my_strdup(str20);
  assert(strcmp(str20, str21) == 0);
  char str22[] = "";
  char *str23 = my_strdup(str22);
  assert(strcmp(str22, str23) == 0);
  printf("\nTesting my_strconcat()\n");
  char *str28 = my_strconcat(NULL, NULL);
  assert(str28 == NULL);
  char *str24 = my_strconcat("Andrew", " O'Brien");
  assert(my_strcmp(str24, "Andrew O'Brien") == 0);
  char *str25 = my_strconcat("", "");
  assert(my_strcmp(str25, "") == 0);
  printf("\nTesting my_strnconcat()\n");
  char *str26 = my_strnconcat(NULL, NULL, 10);
  assert(str26 == NULL);
  char *str27 = my_strnconcat("Andrew", " O'Brien", 10);
  assert(my_strcmp(str27, "Andrew O'Brien") == 0);
  printf("\nTesting my_atoi()\n");
  printf("%d", my_atoi(NULL)); printf("\t| Should be 0\n");
  printf("%d", my_atoi("5")); printf("\t| Should be 5\n");
  printf("%d", my_atoi("-5")); printf("\t| Should be -5\n");
  printf("%d", my_atoi("--5")); printf("\t| Should be 5\n");
  printf("%d", my_atoi("a-b54sc7-d")); printf("\t| Should be -54\n");
  printf("%d", my_atoi("abcd")); printf("\t| Should be 0\n");



	return 0;
}
