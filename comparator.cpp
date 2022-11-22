#include "akinator.h"

static node **path(node *term_node, int *pathlen) {
    int     level = 1;
    node    *current = NULL,
            **path = NULL;

    current = term_node;

    while(current->parent) {
        level++;

        current = current->parent;
    }

    path = (node**)calloc(level, sizeof(node*));

    current = term_node;

    for(int i = 0; i < level; i++) {
        path[i] = current;
        current = current->parent;
    }

    *pathlen = level;

    return path;
}

static void printfirstn(node **path, int n) {
    printf("%s", path[0]->state);

    for(int i = 0; i < n; i++) {
        printf(" is ");

        if(path[i]->side == NO) {
            printf("not ");
        }

        printf("%s;", path[i]->parent->state);
    }
    printf("\n");
}

static void compare(node *node1, node *node2) {
    node    *root = NULL,
            *current = NULL,
            **path1 = NULL,
            **path2 = NULL;

    int     len1 = 0,
            len2 = 0,
            i1 = 0,
            i2 = 0;

    path1 = path(node1, &len1);
    path2 = path(node2, &len2);

    i1 = --len1;
    i2 = --len2;

    while(!strcmp(path1[i1]->state, path2[i2]->state) && i1-- && i2--);

    printf("The differences between %s and %s are:\n", node1->state, node2->state);

    printfirstn(path1, i1 + 1);
    printfirstn(path2, i2 + 1);
}

int Comparator(tree *tree) {
    printf("Input first object:\n");
    node *node1 = InputNode(tree);

    printf("Input second object:\n");
    node *node2 = InputNode(tree);

    if(!(node1 && node2)) {
        return 1;
    }

    compare(node1, node2);

    return ALL_RIGHT;
}