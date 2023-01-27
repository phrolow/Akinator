#include "../akinator.h"

void TreeCtor(tree *tree, node *root) {
    tree->root = root;
}

void TreeDtor(tree *tree) {
    tree->root = NULL;
}

void nodedtor_(node *node) {
    if(node->children[0]) {
        nodedtor_(node->children[0]);
        nodedtor_(node->children[1]);
    }

    NodeDtor(node);
}

void LoadTree(tree *tree, struct text *txt) {
    char *ptr = txt->content;
    node *root = loadnode_(NULL, &ptr, NOT_DEFINED);

    TreeCtor(tree, root);
}

node *loadnode_(node *parent, char **ptr, int side) {
    node *newnode = (node*) calloc(1, sizeof(node));

    char *nextopen = NULL;
    char *nextclose = NULL;

    int len = 0;

    *ptr = strchr(*ptr, '\"');

    NodeCtor(parent, newnode, NULL, side);

    sscanf(*ptr, "\"%s%n\"", newnode->state, &len);

    newnode->state[len - 2] = '\0';

    nextopen = strchr(*ptr, '{');
    nextclose = strchr(*ptr, '}');

    *ptr = (nextopen && nextopen < nextclose) ? nextopen : nextclose;

    if(**ptr == '{') {
        newnode->children[YES] = loadnode_(newnode, ptr, YES);
        newnode->children[NO] = loadnode_(newnode, ptr, NO);
    }

    return newnode;
}

static void savenode_(node *node, FILE *fp, int level) {
    for(int i = 0; i < level; i++) {
        fputc('\t', fp);
    }

    fprintf(fp, "{ \"%s\" ", node->state);

    if(node->children[0]) {
        fputc('\n', fp);

        savenode_(node->children[YES], fp, level + 1);
        savenode_(node->children[NO], fp, level + 1);

        fputc('\n', fp);

        for(int i = 0; i < level; i++) {
            fputc('\t', fp);
        }
    }

    fprintf(fp, "}\n");
}

void SaveTree(tree *tree, const char *path) {
    printf("Save tree? [Y/N]\n");

    if(!ask())
        return;

    FILE *fp = NULL;

    fp = fopen(path, "w");

    savenode_(tree->root, fp, 0);

    fclose(fp);
}

static node* findnode_(node *current, const char *state) {
    if(current->children[0]) {
        node *no = findnode_(current->children[0], state);

        return no ? no : findnode_(current->children[1], state);
    }

    if(!strcmp(current->state, state)) {
        return current;
    }

    return NULL;
}

node *FindNode(tree *tree, const char *state) {
    return findnode_(tree->root, state);
}

node* InputNode(tree *tree) {
    char *buf;
    node *nod;

    buf = (char*) calloc(BUFSIZE, sizeof(char));

    gets(buf);

    nod = FindNode(tree, buf);

    if(!nod) {
        printf("Node \"%s\" not found\n", buf);
    }

    return nod;
}