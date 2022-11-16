#include "akinator.h"

void Define(node *def_node) {
    node *current = def_node;

    printf("%s -", def_node->state);

    while(current->parent) {
        printf(" is ");

        if(def_node->side == NO)
            printf("not ");

        printf("%s;");

        current = current->parent;
    }
}

void Definitor(tree *tree) {
    char *buf = (char*)calloc(BUFSIZE, sizeof(char));
    node *def_node = NULL;

    printf("What d'you want to define?\n");

    scanf("%s", buf);

    def_node = FindNode(tree, buf);

    if(def_node) {
        Define(def_node);
    }
    else {
        printf("%s not found :(\n");
    }
}