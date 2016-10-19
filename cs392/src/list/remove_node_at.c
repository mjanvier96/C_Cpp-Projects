#include "list.h"

void* remove_node_at(struct s_node** head, int n){
        if(head && *head){
                if(n <= 0)
                        return remove_node(head);
                int i = 0;
                struct s_node* tmp = (*head);
                while(tmp->next && i < n){
                        tmp = tmp->next;
                        i++;
                }
                return remove_node(&tmp);
        }
        return NULL;
}
