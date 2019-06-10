# binary tree  
二叉树是树形分支结构的一种，二叉树最多有两个子节点。    
  
## full tree  
二叉树的每个节点有两个子节点或者没有子节点。    
  
## complete tree   
安全树首先是full tree，然后所有的叶子节点在同一层，并且，叶子节点自左向右边分布。    
  
  
# advantage of trees  
树能呈现数据的结构化和层级化的关系。    
树能提供高效的插入和搜索。    
树有很高的灵活性，删除子树非常方便。    
  
  
# traversal    
  
## depth-first traversal  
PreOrder traversal    
InOrder traversal    
PostOrder traversal    
  
用一段伪代码来说明先序中序后序：  
struct bin_tree_node{  
	int value;  
	struct bin_tree_node * left;  
	struct bin_tree_node * right;  
}  
  
pre_order(bin_tree_node node){  
	if(node != NULL){  
		node.value;  
		pre_order(node->left);  
		pre_order(node->right);  
	}else{  
		return 0;  
	}  
}  
  
in_order(bin_tree_node node){  
	if(node != NULL){  
		in_order(node->left);  
		node.value;  
		in_order(node->right);  
	}else{  
		return 0;  
	}  
}  
  
post_order(bin_tree_node node){  
	if(node != NULL){  
		post_order(node->left);  
		post_order(node->right);  
		node.value;  
	}else{  
		return 0;  
	}  
}  
  
## breadth-first traversal  
level order traversal    
  
  
# binary search tree   
二叉搜索树，对于每个节点而言，其左子树所有节点的值都要小于其右子树的所有节点的值。    
以树的根节点为中间值，大于根的，插入根的右边，小于根的，插入根的左边。    
  
