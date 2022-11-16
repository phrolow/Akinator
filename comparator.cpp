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
        path[i] = current->parent;

        current = current->parent;
    }

    *pathlen = level;

    return path;
}

static void printfirstn(node **path, int n) {
    printf("%s ", path[0]);

    for(int i = 1; i < n; i++) {
        printf(" is ");

        if(path[i]->side == NO) {
            printf("not ");
        }

        printf("%s;", path[i]->state);
    }
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

    i1 = len1--;
    i2 = len2--;

    //дальше будешь долго дебажить пизда

    while(i1-- && i2--) {
        if(path1[i1] != path2[i2]) {
            break;
        }
    }

    printf("The differences between %s and %s are:\n", node1->state, node2->state);

    printfirstn(path1, i1);
    printfirstn(path2, i2);
}

void Comparator(tree *tree) {
    node *node1 = InputNode();
    node *node2 = InputNode();
}