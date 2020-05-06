#include <stdlib.h>
#include "node.h"

Node *create_node(int value){
    Node *node = malloc(sizeof(Node));
    node->item = value;
    node->next = NULL;
    return node;
}

void node_free(Node *n){
    free(n);
}