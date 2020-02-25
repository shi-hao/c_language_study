#include"linked_list.h"
#include<stdlib.h>
#include<stdio.h>

int list_insert(linked_list* list, list_node* node){
	list->sum++;

	if(list->head == 0){
		list->head = node;
		list->tail = node;
	}else{
		list->tail->next = node;
		list->tail = node;
	}
}

int list_init(linked_list* list){
	list->sum = 0;
	list->head = 0;
	list->tail = 0;
}

list_node* create_list_node(){
	list_node* tmp;
	unsigned char* data;

	if(((tmp = (list_node*)malloc(sizeof(list_node))) == 0))
		return 0;

	if(((data = (unsigned char*)malloc(node_capacity)) == 0)){
		free(tmp);
		return 0;
	}

	tmp->pri = 1;
	tmp->capacity = node_capacity;
	tmp->len = 0;
	tmp->data = data;
	tmp->next = 0;
}

int free_list_node(list_node* node){
	free(node->data);
	free(node);
}

int mprint_linked_list(linked_list* list){

	list_node* node = list->head;
	for(int i=0; i<list->sum; i++){
		printf("\n the %d node->pri=%d \n ", i, node->pri);
		printf("\n the %d node->data=%s \n ",i,  node->data);
		node = node->next;
	}
}
