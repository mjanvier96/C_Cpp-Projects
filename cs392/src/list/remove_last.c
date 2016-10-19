#include "list.h"

void* remove_last(struct s_node** head){
	if(head && *head){
                struct s_node* tmp = (*head);
                while(tmp->next)
                        tmp = tmp->next;
                return remove_node(&tmp);
        }
        return NULL;
}
