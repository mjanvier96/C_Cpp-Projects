#include <stdlib.h>
#include <stdio.h>


void my_char(char c){
        write(1, &c, 1);
}

void my_str(char* c){
        if(c)
                while(*c){/* iterates through string while pointer is valid */
                        write(1, c, 1);
                        c++;
                }
        return;
}

void my_int(int n){
        int tmp, count;
        char c;
        const char neg = '-';
        if(!n){/* checks if original integer is zero */
                c = '0' + 0;
                write(1, &c, 1);/* writes 0 */
        }
        else if(n < 0){/* checks for neg value and always makes number positive */
                n = -n;
                write(1, &neg, 1);/* prints neg sign */
        }
        while(n){
                count = 1;/* offset starts at first digit */
                tmp = n;
                while(tmp > 10){ /* divides by ten until down to first digit*/
                        tmp /= 10;
                        count *= 10;
                }

                c = '0' + tmp;
                write(1, &c, 1);
                n = n % (tmp * count); /* chops off first digit using the offset */
        }
        return;
}

struct s_node {
 void* elem;
 struct s_node* next;
 struct s_node* prev;
};

struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous){
        struct s_node* node = malloc(sizeof(struct s_node));
        node->elem = elem;
        node->next = next;
        node->prev = previous;
        return node;
}


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

void* remove_node(struct s_node** node){
	if(node && *node){
		void* ptr;
		struct s_node* tmp = (*node);

		if(tmp->prev && tmp->next){
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			
		}
		else if(!tmp->prev && !tmp->next){
			(*node) = NULL;
		}
		else if(!tmp->prev){
			tmp->next->prev = NULL;
			(*node) = tmp->next;
		}
		else{
			tmp->prev->next = NULL;
		}
		ptr = tmp->elem;
		free(tmp);
		return ptr;
	}
	return NULL;
}

void* remove_last(struct s_node** head){
	if(head && *head){
		struct s_node* tmp = (*head);
		while(tmp->next)
			tmp = tmp->next;
		return remove_node(&tmp);
	}
	return NULL;
}

void* remove_node_at(struct s_node** head, int n){
	if(head && *head){
		if(n <= 0)
			return remove_node(head);
                int i = 0;
		struct s_node* tmp = (*head);
                while(tmp->next && i < n){
                        tmp = tmp->next;
			i++;
		}
                return remove_node(&tmp);
        }
        return NULL;
}

int count_s_nodes(struct s_node* head){
	int i = 0;
	while(head){
		head = head->next;	
		i++;
	}
	return i;
}

void traverse_int(struct s_node* head){
	while(head){
		my_int(*((int*)(head->elem)));
		my_char(' ');		
		head = head->next;
	}
}

void traverse_char(struct s_node* head){
	while(head){
                my_char(*((char*)(head->elem)));
                my_char(' ');
                head = head->next;
        }
}


void traverse_string(struct s_node* head){
	while(head){
                my_str((char*)(head->elem));
                my_char(' ');
                head = head->next;
        }
}


void print_int(struct s_node* node){
	my_int(*((int*)(node->elem)));
}

void print_char(struct s_node* node){
	my_char(*((char*)(node->elem)));
}

void print_string(struct s_node* node){
	my_str((char*)(node->elem));
}

char* nilStr = "NULL";

void debug_int(struct s_node* head){
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
                                print_int(head->prev);
                        else
                                my_str(nilStr);
                        my_str(pre);
                        if(head->elem)
                                print_int(head);
                        else
                                my_str(nilStr);
                        my_str(nxt);
                        if(head->next && head->next->elem)
                                print_int(head->next);
                        else
                                my_str(nilStr);
                        my_str(elemEnd);
                        head = head->next;
                }
        }
}

void debug_char(struct s_node* head){
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

void debug_string(struct s_node* head){
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
                                print_string(head->prev);
                        else
                                my_str(nilStr);
                        my_str(pre);
                        if(head->elem)
                              	print_string(head);
                        else
                                my_str(nilStr);
                        my_str(nxt);
                        if(head->next && head->next->elem)
                                print_string(head->next);
                        else
                                my_str(nilStr);
                        my_str(elemEnd);
                        head = head->next;
                }
        }
}

void empty_list(struct s_node** head){
        while(*head){
                remove_node(head);
        }
}

struct s_node* node_at(struct s_node* head, int n){
	if(!head){
		return NULL;
	}
	if(n <= 0)
		return head;
	int i = 0;	
	while(head->next && i < n){
		head = head->next;
		i++;
	}
	return head;
}

void* elem_at(struct s_node* head, int n){
	if(!head){
                return NULL;
        }
        if(n <= 0)
                return head->elem;
        int i = 0;
        while(head->next && i < n){
                head = head->next;
                i++;
        }
        return head->elem;
}

int main(){
	
	void* one = malloc(sizeof(int));
	void* two = malloc(sizeof(int));
	*((int*)one) = 1;
	*((int*)two) = 2;
	char* str1 = "Hello";
	char* str2 = "World";
	char* str3 = ", ";
	char* str4 = "!";
	char* str5 = "Well";
	void* a = malloc(sizeof(char));
	void* b = malloc(sizeof(char));
	*((char*)(a)) = 'a';
	*((char*)(b)) = 'b';
	struct s_node* head = new_node(str2, NULL, NULL);
	debug_string(head);
	my_char('\n');
	add_elem(str1, &head);
	debug_string(head);
	my_char('\n');
	append(new_node(str2, NULL, NULL), &head);
	debug_string(head);
        my_char('\n');
	add_node_at(new_node(str3, NULL, NULL), &head, 1); 
        debug_string(head);
        my_char('\n');
	add_node_at(new_node(str4, NULL, NULL), &head, 10);
        debug_string(head);
        my_char('\n');
	add_node_at(new_node(str5, NULL, NULL), &head, -1);
	debug_string(head);
        my_char('\n');
	print_string(node_at(head, 6));
	my_char('\n');
	print_string(node_at(head, -1));
	my_char('\n');
	print_string(node_at(head, 2));
	my_char('\n');
	my_str(elem_at(head, 6));
        my_char('\n');
        my_str(elem_at(head, -1));
        my_char('\n');
        my_str(elem_at(head, 2));
        my_char('\n');
	traverse_string(head);
	my_char('\n');
	my_int(count_s_nodes(head));
	my_char('\n');
	remove_node(&head);
        debug_string(head);
        my_char('\n');
	my_int(count_s_nodes(head));
	my_char('\n');
	remove_last(&head);
        debug_string(head);
        my_char('\n');
	remove_node(&(head->next->next));
        debug_string(head);
        my_char('\n');
	add_node_at(new_node(str4, NULL, NULL), &head, 10);
        debug_string(head);
        my_char('\n');
	remove_node_at(&head, 10);
        debug_string(head);
        my_char('\n');
	remove_node_at(&head, -1);
        debug_string(head);
        my_char('\n');
	add_elem(str1, &head);
        debug_string(head);
        my_char('\n');
	remove_node_at(&head, 1);
        debug_string(head);
        my_char('\n');
	empty_list(&head);
	debug_string(head);
        my_char('\n');
	return 0;	
}
