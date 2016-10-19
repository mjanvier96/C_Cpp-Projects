#include "my.h"
#include "list.h"

typedef struct s_node* S_node;

void add_node(struct s_node* node, struct s_node** head){
	if(head && *head && node && node->elem){
                (*head)->prev = node;
                node->next = (*head);
                node->prev = NULL;
                *head = (*head)->prev;
        }
        else if(head && node && node->elem){
                (*head) = new_node(node->elem, node->next, node->prev);
        }
	return;
}
