#ifndef _LINKED_LIST_ 
#define _LINKED_LIST_ 

#define node_capacity  256

typedef struct list_node{
	int pri;
	int capacity;
	int len;
	unsigned char* data;

	struct list_node* next;
}list_node;


typedef struct linked_list{
	int sum;

	list_node* head;
	list_node* tail;
}linked_list;

extern int list_insert(linked_list* list, list_node* node);
extern int list_init(linked_list* list);
extern list_node*  create_list_node();
extern int mprint_linked_list();
#endif
