#include "List.h"

#include "NEW.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// todo: replace linked list by static array
struct List* List_new() {
    struct List* this = NEW(List);
    this->head = NULL;
    return this;
}

void List_printf(struct List* this, char* printer() ) {
    struct ListNode* p = this->head;
    printf("\n[ ");

    while(p != NULL ) {
        printf("%s", (*printer)(p->data));
        p = p->next;
    }

    printf(" ]");
}

void List_insertFirst(struct List* this, void* data) {
    struct ListNode *link = NEW(ListNode);

    link->data = data;

    link->next = this->head;
    this->head = link;
}

void* List_removeFirst(struct List* this) {
    struct ListNode *first = this->head;

    this->head = this->head->next;
    void* data = first->data;

    free(first);

    return data;
}

bool List_isEmpty(struct List* this) {
    return this->head == NULL;
}

int List_length(struct List* this) {
    int length = 0;
    struct ListNode *current;

    for( current = this->head; current != NULL; current = current->next)
        length++;

    return length;
}