#ifndef _LINKED_LIST_ 
#define _LINKED_LIST_ 

#define elem_capacity  256

typedef struct list_elem{
	int pri;
	int capacity;
	int len;
	unsigned char* data;

	struct list_elem* next;

}list_elem, *list_elem_p;


typedef struct linked_list{
	int elem_sum;

	list_elem_p head;
	list_elem_p tail;
}linked_list, *linked_list_p;

extern int list_insert(linked_list_p list, list_elem_p node);
extern int list_init(linked_list_p list);
extern list_elem_p  create_list_elem();
extern int mprint_linked_list();
#endif
