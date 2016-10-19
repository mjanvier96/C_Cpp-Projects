#include "list.h"

struct s_node* node_at(struct s_node* head, int n){
        if(!head){
                return NULL;
        }
        if(n <= 0)
                return head;
        int i = 0;
        while(head->next && i < n){
                head = head->next;
                i++;
        }
        return head;
}
