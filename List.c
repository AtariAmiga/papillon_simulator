#include "List.h"

#include "NEW.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// todo: replace linked list by static array
struct List* List_new() {
    struct List* self = NEW(List);
    self->head = NULL;
    return self;
}

void List_printf(struct List* self, char* printer() ) {
    struct ListNode* p = self->head;
    printf("\n[ ");

    while(p != NULL ) {
        printf("%s", (*printer)(p->data));
        p = p->next;
    }

    printf(" ]");
}

void List_insertFirst(struct List* self, void* data) {
    struct ListNode *link = NEW(ListNode);

    link->data = data;

    link->next = self->head;
    self->head = link;
}

void* List_removeFirst(struct List* self) {
    if( self->head == NULL )
        return NULL;

    struct ListNode *first = self->head;

    self->head = self->head->next;
    void* data = first->data;

    free(first);

    return data;
}

bool List_isEmpty(struct List* self) {
    return self->head == NULL;
}

int List_length(struct List* self) {
    int length = 0;
    struct ListNode *current;

    for( current = self->head; current != NULL; current = current->next)
        length++;

    return length;
}