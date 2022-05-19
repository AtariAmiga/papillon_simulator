#include "NEW.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    void* data;
    struct ListNode *next;
};

struct List {
    struct ListNode *head;
};

struct List* List_new();
void List_printf(struct List* this, char* printer());
void List_insertFirst(struct List* this, void* data);
void* List_removeFirst(struct List* this);
bool List_isEmpty(struct List* this);
int List_length(struct List* this);
