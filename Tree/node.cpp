#include "../akinator.h"

int NodeCtor(node *parent, node *node, char *state, int side) {
    node->parent = parent;
    node->state = (char*) calloc(BUFSIZE, sizeof(char));

    if(state)
        strcpy(node->state, state);
    else
        strcpy(node->state, "WTF");
    node->children[0] = NULL;
    node->children[1] = NULL;
    node->side = side;

    return 0;
}

void NodeDtor(node *node) {
    assert(node);

    node->parent->children[node->side] = NULL;

    node->parent = NULL;
    node->state = NULL;
    node->children[0] = NULL;
    node->children[1] = NULL;
    node->side = NOT_DEFINED;
}