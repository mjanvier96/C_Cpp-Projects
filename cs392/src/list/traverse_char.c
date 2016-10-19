#include "list.h"

void traverse_char(struct s_node* head){
        while(head){
                my_char(*((char*)(head->elem)));
                my_char(' ');
                head = head->next;
        }
}
