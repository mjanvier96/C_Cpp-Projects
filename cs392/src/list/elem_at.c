#include "list.h"

void* elem_at(struct s_node* head, int n){
        if(!head){
                return NULL;
        }
        if(n <= 0)
                return head->elem;
        int i = 0;
        while(head->next && i < n){
                head = head->next;
                i++;
        }
        return head->elem;
}
