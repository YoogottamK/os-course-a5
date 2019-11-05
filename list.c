#include "user.h"
#include "list.h"

Node * newNode(void * data) {
    Node * n = (Node *) malloc(sizeof(Node));

    n->next = 0;
    n->data = data;

    return n;
}

Node * prepend(Node * rt, Node * n) {
    if(!rt)
        return n;

    n->next = rt;
    return n;
} 

Node * append(Node * rt, Node * n) {
    if(!rt)
        return n;

    Node * curr = rt;
    while(curr->next) curr = curr->next;

    curr->next = n;

    return rt;
}

Node * deleteHead(Node * rt) {
    if(!rt)
        return 0;

    return rt->next;
}
