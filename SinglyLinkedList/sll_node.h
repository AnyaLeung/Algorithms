#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    struct Node *link;
    int          value;
} Node;

void Iterate(const Node *linkp);
int Insert(Node **linkp, int new_value);

