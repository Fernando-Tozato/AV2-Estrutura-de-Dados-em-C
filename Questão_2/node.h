#ifndef NODE_H
#define NODE_H

// struct Node utilizada na pilha e na fila
struct Node {
    int item;
    struct Node *prox;
};

typedef struct Node node;

#endif
