#ifndef NODE_H
#define NODE_H

typedef struct Node Node;

struct Node{
    int item;
    Node *next;
    Node *prev;
};

Node *create_node(int value);
void node_free(Node *n);

#endif