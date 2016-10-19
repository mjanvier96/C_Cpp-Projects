#include "my.h"
#include "list.h"

void add_node_at(struct s_node* node, struct s_node** head, int n){
	if(node && node->elem && head && *head){
                if(n <= 0){
                        add_node(node, head);
                        return;
                }
                else{
                        int i = 0;
                        struct s_node* tmp = *head;
                        while(tmp->next && i < n){
                                tmp = tmp->next;
                                i++;
                        }
                        if(tmp->next){
                                node->prev = tmp->prev;
                                node->next = tmp;
                                tmp->prev->next = node;
                                tmp->prev = node;
                        }
                        else{
                                tmp->next = node;
                                node->prev = tmp;
                        }
                }
        }
}
