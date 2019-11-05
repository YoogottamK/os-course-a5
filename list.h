#include "user.h"

typedef struct Node {
    struct Node * next;
    void * data;
} Node;

Node * newNode(void * data);

Node * prepend(Node * rt, Node * n);

Node * append(Node * rt, Node * n);

Node * deleteHead(Node * rt);
