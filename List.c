#include "List.h"

#include "NEW.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct List* List_new() {
    struct List* i = NEW(List);
    i->head = NULL;
    i->current = NULL;
    return i;
}

void List_printf(struct List* this) {
    struct ListNode* ptr = this->head;
    printf("\n[ ");

    while( ptr != NULL ) {
        printf("(%d, %d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}

void List_insertFirst(struct List* this, int key, int data) {
    struct ListNode *link = NEW(ListNode);

    link->key = key;
    link->data = data;

    link->next = this->head;
    this->head = link;
}

struct ListNode* List_removeFirst(struct List* this) {
    struct ListNode *first = this->head;

    this->head = this->head->next;

    return first;
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

struct ListNode* List_find(struct List* this, int key) {
    if( this->head == NULL)
        return NULL;

    struct ListNode* current = this->head;

    while( current->key != key ) {
        if( current->next == NULL) {
            return NULL;
        } else {
            current = current->next;
        }
    }

    return current;
}

struct ListNode* List_remove(struct List* this, int key) {
    if( this->head == NULL)
        return NULL;

    struct ListNode* current = this->head;
    struct ListNode* previous = NULL;

    while( current->key != key ) {
        if( current->next == NULL) {
            return NULL;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if( current == this->head) {
        this->head = this->head->next;
    } else {
        previous->next = current->next;
    }

    return current;
}