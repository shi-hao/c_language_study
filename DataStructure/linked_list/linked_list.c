#include"linked_list.h"
#include<stdlib.h>
#include<stdio.h>


int list_insert(linked_list_p list, list_elem_p node){
	list->elem_sum++;

	if(list->head == 0){
		list->head = node;
		list->tail = node;
	}else{
		list->tail->next = node;
		list->tail = node;
	}
}

int list_init(linked_list_p list){

	list->elem_sum = 0;
	list->tail = 0;
	list->head = 0;
}

list_elem_p  create_list_elem(){
	list_elem_p tmp;
	unsigned char* data;

	if(((tmp = (list_elem_p)malloc(sizeof(list_elem))) == 0))
		return 0;

	if(((data = (unsigned char*)malloc(elem_capacity)) == 0)){
		free(tmp);
		return 0;
	}

	tmp->pri = 1;
	tmp->capacity = elem_capacity;
	tmp->len = 0;
	tmp->data = data;
	tmp->next = 0;
}

int free_list_elem(list_elem_p node){
	free(node->data);
	free(node);
}

int mprint_linked_list(linked_list_p list){

	list_elem_p node = list->head;
	for(int i=0; i<list->elem_sum; i++){
		printf("\n the %d node->pri=%d \n ", i, node->pri);
		printf("\n the %d node->data=%s \n ",i,  node->data);
		node = node->next;
	}
}
