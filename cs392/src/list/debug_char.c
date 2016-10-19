#include "list.h"

	
void debug_char(struct s_node* head){
        char* nilStr = "NULL";
	if(!head){
                my_str(nilStr);
                return;
        }
        else{
                char* nxt = " -> ";
                char* pre = " <- ";
                char* elemStart = "(";
                char* elemEnd = ")";

                while(head){
                        my_str(elemStart);
                        if(head->prev && head->prev->elem)
                                print_char(head->prev);
                        else
                                my_str(nilStr);
                        my_str(pre);
                        if(head->elem)
                                print_char(head);
                        else
                                my_str(nilStr);
                        my_str(nxt);
                        if(head->next && head->next->elem)
                                print_char(head->next);
                        else
                                my_str(nilStr);
                        my_str(elemEnd);
                        head = head->next;
                }
        }
}
