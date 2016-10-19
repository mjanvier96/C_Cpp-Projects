#include "list.h"

void debug_string(struct s_node* head){
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
                                my_str((char*)(head->prev->elem));
                        else
                                my_str(nilStr);
                        my_str(pre);
                        if(head->elem)
                                my_str((char*)(head->elem));
                        else
                                my_str(nilStr);
                        my_str(nxt);
                        if(head->next && head->next->elem)
                                my_str((char*)(head->next->elem));
                        else
                                my_str(nilStr);
                        my_str(elemEnd);
                        head = head->next;
                }
        }
}
