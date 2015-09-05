#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list* list_create() {
	list* new_list = (list *) malloc(sizeof(list));
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->length = 0;

	return new_list;
}

void list_destroy(list* lst) {
	while (lst->head != NULL) {
		list_delete_last(lst);
	}

	free(lst);
}

void list_print(const list* lst) {
	node* curnode = lst->head;

	while (curnode != NULL) {
		printf("%d ", curnode->val);
		curnode = curnode->next;
	}

	printf("\n");
}

void list_insert(list* lst, int item) {
	node *prevhead, *newhead;

	newhead = (node*) malloc(sizeof(node));
	prevhead = lst->head;

	newhead->val = item;
	newhead->next = prevhead;
	lst->head = newhead;
	lst->length++;

	if (prevhead == NULL)
		lst->tail = newhead;

	lst->length++;
}

void list_append(list* lst, int item) {
	node *prevnode, *curnode, *newnode;

	prevnode = NULL;
	curnode = lst->head;

	while (curnode != NULL) {
		prevnode = curnode;
		curnode = curnode->next;
	}

	newnode = (node*) malloc(sizeof(node));
	newnode->val = item;

	newnode->next = NULL;

	if (prevnode != NULL) {
		prevnode->next = newnode;
		lst->tail = newnode;
	} else {
		lst->head = lst->tail = newnode;
	}

	lst->length++;
}

void list_insert_after(list* lst, int item, int loc) {
	node *curnode, *prevnode, *newnode;

	prevnode = NULL;
	curnode = lst->head;

	int curpos = 0;

	while (curnode != NULL) {
		curpos++;

		if (curpos > loc)
			break;

		prevnode = curnode;
		curnode = curnode->next;
	}

	newnode = (node *) malloc(sizeof(node));
	newnode->val = item;

	if (curpos < loc) { //insert at the end
		prevnode->next = newnode;
		newnode->next = NULL;

		lst->tail = newnode;

		if (prevnode == NULL) { //previously empty
			lst->head = newnode;
		}
	}

	//insert at between head and tail
	prevnode->next = newnode;
	newnode->next = curnode;

	lst->length++;
}

bool list_delete(list* lst, int data) { //!!! WHY DO I FAIL TO SEE THIS
	node *prevnode, *curnode;
	bool deleted = false;

	prevnode = NULL;
	curnode = lst->head;

	while (curnode != NULL) {
		if (curnode->val == data) {
			if (prevnode == NULL) { //deleted the 1st item
				lst->head = curnode->next;
			} else
				prevnode->next = curnode->next;

			if (curnode->next == NULL) //just deleted the last item
				lst->tail = prevnode;

			free(curnode);
			deleted = true;

			if (prevnode == NULL)
				curnode = lst->head;
			else
				curnode = prevnode->next;
			continue;

		}

		prevnode = curnode;
		curnode = curnode->next;
	}

	lst->length--;

	return deleted;
}

void list_delete_last(list* lst) {
	node *prevnode, *curnode;

	prevnode = NULL;
	curnode = lst->head;

	while (curnode->next != NULL) {
		prevnode = curnode;
		curnode = curnode->next;
	}

	if (curnode != NULL)
		free(curnode);

	if (prevnode == NULL) { //previously an only item list
		lst->head = lst->tail = NULL;
	} else {
		prevnode->next = NULL;
		lst->tail = prevnode;
	}

	lst->length--;
}
