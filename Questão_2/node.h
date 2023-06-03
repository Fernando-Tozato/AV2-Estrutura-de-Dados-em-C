#ifndef NODE_H
#define NODE_H

struct Node {
    int item;
    struct Node *prox;
};

typedef struct Node node;

#endif
