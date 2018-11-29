/*
 * 在编程时，如何存储数据呢，一般情况下，如果是一组字符数据，使用数组就可以满足要求，
 * 但是，如果数据之间有一定的联系，如何存储呢，一般会考虑使用结构体来存储，但是有多个结构体的数据
 * 如何来存储呢，可以考虑使用链表结构。
 * 
 * 数组的搜索比较方便，可以直接使用下标，但删除或者插入就比较麻烦了，而链表与之相反，删除和插入都比较简单，
 * 但是查找很慢，这自然也与这两种数据结构的存储方式有关，数组是取一段相连的空间，而链表是每创建一个节点便
 * 取一个节点所需的空间，只是使用指针进行连接，空间上并不是连续的。
 */
#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
#include<string.h>


int main(){

	linked_list mlist;
	list_elem_p node;

	list_init(&mlist);

	node = create_list_elem();
	if(node != 0){
		node->pri = 10;
		memcpy(node->data, "i am node 1", strlen("i am node 1"));
		list_insert(&mlist, node);
	}

	node = create_list_elem();
	if(node != 0){
		node->pri = 11;
		memcpy(node->data, "i am node 2", strlen("i am node 2"));
		list_insert(&mlist, node);
	}

	mprint_linked_list(&mlist);
}
