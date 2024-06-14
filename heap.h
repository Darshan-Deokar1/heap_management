#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct Node
{
    void *address;
    struct Node *prev;
    struct Node *next;
    int memorySize;
    int isAllocated;
} Node;

void DeleteNode(Node *ptr);

Node *createNode();

void setNodeValues(Node *, void *, Node *, Node *, int, int);

void *Allocate(Node *, int);

void Deallocate(Node *hptr, void **dptr);
