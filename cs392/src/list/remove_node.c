#include "list.h"

void* remove_node(struct s_node** node){
        if(node && *node){
                void* ptr;
                struct s_node* tmp = (*node);

                if(tmp->prev && tmp->next){
                        tmp->prev->next = tmp->next;
                        tmp->next->prev = tmp->prev;

                }
                else if(!tmp->prev){
                        tmp->next->prev = NULL;
                        (*node) = tmp->next;
                }
                else if(!tmp->next){
                        tmp->prev->next = NULL;
                }
                else{
                        (*node) = NULL;
                }
                ptr = tmp->elem;
                free(tmp);
                return ptr;
        }
        return NULL;
}
