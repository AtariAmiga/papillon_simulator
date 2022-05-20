#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "NEW.h"

struct ListNode {
    void* data;
    struct ListNode *next;
};

struct List {
    struct ListNode *head;
};

struct List* List_new();
void List_printf(struct List* self, char* printer());
void List_insertFirst(struct List* self, void* data);
void* List_removeFirst(struct List* self);
bool List_isEmpty(struct List* self);
int List_length(struct List* self);

#endif