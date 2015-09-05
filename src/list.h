#include <stdbool.h>

#ifndef LIST_H_
#define LIST_H_

typedef struct node_ {
	int val;
	struct node_* next;
} node;

typedef struct list_ {
	node* head;
	node* tail;
	int length;
} list;

list* list_create();
void list_print(const list*);
void list_destroy(list*);
void list_append(list*,int);
void list_insert(list*,int);
void list_insert_after(list*,int,int);
void list_delete_last(list*);
bool list_delete(list*,int);

#endif





