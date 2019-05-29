#ifndef MY_TREE_H
#define MY_TREE_H

struct node
{
	int data; //node will store an integer
	struct node *right_child; // right child
	struct node *left_child; // left child
};


extern struct node* search(struct node *root, int x);

//function to find the minimum value in a node
extern struct node* find_minimum(struct node *root);

//function to create a node
struct node* new_node(int x);

struct node* insert(struct node *root, int x);

// funnction to delete a node
struct node* delete(struct node *root, int x);

void inorder(struct node *root);

#endif
