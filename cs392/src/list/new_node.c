#include "my.h"
#include "list.h"

typedef struct s_node* S_node;

struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous){
	S_node node = (S_node)malloc(sizeof(struct s_node));
	node->elem = elem;
	node->next = next;
	node->prev = previous;
	return node;
}
