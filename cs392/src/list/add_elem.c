#include "my.h"
#include "list.h"

void add_elem(void* elem, struct s_node** head){
	if(elem && head && *head){
		struct s_node* node = new_node(elem, (*head), NULL);
		node->prev = NULL;
		(*head)->prev = node;
		(*head) = node;
	}
	else if(elem && head){
		*head = new_node(elem, NULL, NULL);
	}
	return;
}
