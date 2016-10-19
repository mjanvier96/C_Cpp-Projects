#include "list.h"

void traverse_int(struct s_node* head){
        while(head){
                my_int(*((int*)(head->elem)));
                my_char(' ');
                head = head->next;
        }
}

