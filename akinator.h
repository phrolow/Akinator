#ifndef AKINATOR_AKINATOR_H
#define AKINATOR_AKINATOR_H

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys\stat.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

enum SIDE {
    YES = 1,
    NO = 0,
    NOT_DEFINED = -1
};

enum TREE_ERROR {
    ALL_RIGHT = 0,
    INVALID_SIDE,
    NULL_STATE,
    INVALID_LINK,
};

const size_t BUFSIZE = 0x100;

typedef struct Node {
    struct Node *parent;
    struct Node *children[2];
    char *state;
    int side;
} node;

typedef struct Tree {
    node *root;
} tree;

struct text {
    char *content;
    char **ptrs;
    size_t  nChar,
            nLine,
            maxLine;
};

struct text maketext(char *content, char** ptrs, size_t nChar, size_t nLine, size_t maxLine);

struct text textFromFile(const char *path);

void TreeCtor(tree *tree, node *node);

void TreeDtor(tree *tree);

int NodeCtor(node *parent, node *node, char *state, int side);

void NodeDtor(node *node);

void LoadTree(tree *tree, struct text *text);

node *loadnode_(node *node, char **ptr, int side);

void SaveTree(tree *tree, const char *path);

node *FindNode(tree *tree, const char *state);

int Akinator(tree *tree);

void AkinatorExtend(node *replaced_node);

node* InputNode(tree *tree);

void Define(node *def_node);

int Definitor(tree *tree);

int Comparator(tree *tree);

void Start(tree *tree);

int checkfile(char *path);

int ask();

#endif //AKINATOR_AKINATOR_H
