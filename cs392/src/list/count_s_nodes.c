#include "list.h"

int count_s_nodes(struct s_node* head){
	int i = 0;
        while(head){
                head = head->next;
                i++;
        }
        return i;
}
