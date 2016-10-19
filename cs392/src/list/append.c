#include "list.h"

void append(struct s_node* node, struct s_node** head){
        if(node && node->elem && head && *head){
                struct s_node* tmp = *head;
                while(tmp->next){
                        tmp = tmp->next;
                }
                tmp->next = node;
                node->prev = tmp;
        }
        else if(node && node->elem && head){
                add_node(node, head);
        }
        return;
}
