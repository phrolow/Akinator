#include "../akinator.h"

void Define(node *def_node) {
    node *current = def_node;

    printf("%s -", def_node->state);

    while(current->parent) {
        printf(" is ");

        if(current->side == NO) {
            printf("not ");
        }

        current = current->parent;

        printf("%s;", current->state);
        }
}

int Definitor(tree *tree) {
    node *def_node = NULL;

    printf("What d'you want to define?\n");

    def_node = InputNode(tree);

    if(def_node) {
        Define(def_node);
    }
    else {
        return 1;
    }

    printf("\n");

    return ALL_RIGHT;
}