/* file list.c */
#include <stdio.h>
#include <stdlib.h>

#include "assignment3.h"

/*  reverseList  reverses a linked  list  and  returns a pointer  to the
    reversed  list. head  points  to the  beginning  of the  list. */
ListNodePtr  reverseList(ListNodePtr  head){
	ListNodePtr prev = malloc(sizeof(struct ListNode)); 
	ListNodePtr present = malloc(sizeof(struct ListNode)); 
	ListNodePtr post = malloc(sizeof(struct ListNode)); 
	prev = NULL;
	present = head;
	post = NULL;

	while (present != NULL){
		post = present->next;
		present->next = prev;
		prev = present;
		present = post;
	}
	head = prev;
	return head;
}

/*  deallocateList  fees  all  the  nodes of a linked  list. head is a
    pointer  to the  beginning  of the  list. */
void deallocateList(ListNodePtr  head){
	ListNodePtr temp = malloc(sizeof(struct ListNode)); 
	while (head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
}
