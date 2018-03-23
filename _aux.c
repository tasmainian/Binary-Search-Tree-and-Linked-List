/* file aux.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assignment3.h"

/*  generatRandomIntArray  fills an  array of size N with  random  integers
    between 0 and NMAX -1.*/
void generateRandomIntArray(int N, int *A, int NMAX){
	srand(time(NULL));
	int i;
	for (i=0; i<N; i++){
		*(A+i) = rand() % NMAX;
	}
}


/*  Outputs  the  array A */
void printArray(int n, int *A){
	int i;
	for (i = 0; i<n; i++){
		printf	("%d ", *(A+i));
	}
}

/*  Outputs  the  keys in a BST in in -order. root  points  to the  root of
    the  BST. */
void printBSTinorder(TreeNodePtr  root){
	if (!root)
		return;	
	printBSTinorder(root->left);
	printf("%d ", root->key);
	printBSTinorder(root->right);
}

/*  Outputs  the  keys in a linked  list. head  points  to the  beginning  of
    the  list. */
void printList(ListNodePtr  head){
	while(head != NULL){
		printf("%d ", head->key);
		head = head->next;
	}
	return;
}
