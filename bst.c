/* file bst.c */
#include <stdio.h>
#include <stdlib.h>

#include "assignment3.h"

/*  createBSTnode  allocates a node of type  TreeNode  and  initializes  it
    with  key  and  left=right=NULL. createBSTnode  returns a pointer  to
    this  node.   If  memory  cannot  be allocated , NULL is  returned. */
TreeNodePtr  createBSTnode (int key){
	TreeNodePtr node = malloc(sizeof(struct TreeNode));
	node->key = key;
	node->left=node->right=NULL;
	return node;
}

/*  insertNodeIntoBST  inserts a node  into a BST. root  points  to the
    root of the  tree  and z points  to a node to be
    inserted. insertNodeIntoBST  returns a pointer  to the  root of the
    tree (with z inserted). */
TreeNodePtr  insertNodeIntoBST(TreeNodePtr root , const TreeNodePtr z){
	if (!root)
		return createBSTnode (z->key);
	else if (z->key > root->key)
		root->right = insertNodeIntoBST(root->right, z);
	else
		root->left = insertNodeIntoBST(root->left, z);
	return root;
}

/*  insertArrayIntoBST  inserts n elements  of  array A into a BST  and
    returns  the  pointer  to the  root of the  BST. */
TreeNodePtr  insertArrayIntoBST (int n, int *A){
	if (n <= 0)
		return NULL;
	TreeNodePtr root = createBSTnode (*(A+0));
	int i;
	for (i = 1; i < n; i++){
		TreeNodePtr z = createBSTnode (*(A+i));
		insertNodeIntoBST(root , z);
		free(z);
	}
	return root;
}

/*  deallocateBST  frees  all  the  nodes of a BST. root  points  to the  root
    of the  BST. */
void deallocateBST(TreeNodePtr  root){
	if (!root)
		return;
	deallocateBST(root->left);
	deallocateBST(root->right);
	free(root);
}


/*  convertBSTtoLinkedList  inserts  the  nodes of a BST  into a linked
    list. The  BST is  processed  in in -order. The  keys  are  inserted  such
    that  the  list is  sorted  in non -decreading  order.   A pointer  to the
    linked  list is  returned.*/
ListNodePtr convertBSTtoLinkedList(TreeNodePtr root){
	ListNodePtr listLess = (root->left) ?  convertBSTtoLinkedList(root->left) : NULL;
	ListNodePtr listMore = (root->right) ?  convertBSTtoLinkedList(root->right) : NULL;
	ListNodePtr listMid = malloc(sizeof(struct ListNode));

	listMid->key = root->key;
	listMid->next = listMore;
	
	if (!listLess)
		return listMid;
 
	ListNodePtr end = listLess;

	while (end->next != NULL)
		end = end->next;

	end->next = listMid;
	return listLess;
}
