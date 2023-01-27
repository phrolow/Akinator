#include "../akinator.h"

int Akinator(tree *tree) {
    node *current = NULL;
    char answer = 0;

    current = tree->root;

    do {
        printf("%s? [Y/N]\n", current->state);

        if(ask()) {
            if (!current->children[YES])
                printf("delo raskryto...\n");

            current = current->children[YES];
        }
        else {
            if (!current->children[NO]) {
                AkinatorExtend(current);

                break;
            }

            current = current->children[NO];
        }
    } while(current);

    return ALL_RIGHT;
}

void AkinatorExtend(node *replaced_node) {
    replaced_node->children[NO] = (node*) calloc(2, sizeof(node));
    replaced_node->children[YES] = replaced_node->children[NO] + 1;

    NodeCtor(replaced_node, replaced_node->children[NO], NULL, NO);
    NodeCtor(replaced_node, replaced_node->children[YES], replaced_node->state, YES);

    printf("What exactly was it?\n");
    scanf("%s", replaced_node->children[NO]->state);

    printf("What is difference between %s and %s?\n", replaced_node->state, replaced_node->children[NO]->state);
    scanf("%s", replaced_node->state);
}

void AkinatorCompare(tree *tree, node *node1, node *node2) {

}
