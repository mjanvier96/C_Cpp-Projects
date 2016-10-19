#include "list.h"

void traverse_string(struct s_node* head){
        while(head){
                my_str((char*)(head->elem));
                my_char(' ');
                head = head->next;
        }
}
