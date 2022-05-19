#include "NEW.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int data;
    int key;
    struct ListNode *next;
};

struct List {
    struct ListNode *head;
    struct ListNode *current;
};

struct List* List_new();
void List_printf(struct List* this);
void List_insertFirst(struct List* this, int key, int data);
struct ListNode* List_removeFirst(struct List* this);
bool List_isEmpty(struct List* this);
int List_length(struct List* this);
struct ListNode* List_find(struct List* this, int key);
struct ListNode* List_remove(struct List* this, int key);
