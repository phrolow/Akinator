#include "akinator.h"
#include "akinator_debug.h"

static void PrintNode(const node *node, const size_t *nNode, const char color[COLORLEN], FILE *fp) {
    assert(node && nNode && color && fp);

    fprintf(fp, "\tnode%lu [fillcolor=\"%s\", ", *nNode, color);

    fprintf(fp, "label=\"%s\"", node->state);
    fprintf(fp, "];\n");

    return;
}

static void PrintEdge(const size_t from, const size_t to, const char color[COLORLEN], FILE *fp) {
    assert(color && fp);

    fprintf(fp, "\tedge [color=\"%s\"]; node%lu -> node%lu;\n", color, from, to);

    return;
}

static void nodedump(const node *node, size_t *nNode, FILE *fp) {
    assert(fp && nNode);

    if(node == NULL)
        return;

    if(*nNode == 0) {
        PrintNode(node, nNode, ROOT_COLOR, fp);
    }
    else if(node->children[0] == NULL) {
        PrintNode(node, nNode, TERMINAL_COLOR, fp);
    }
    else {
        PrintNode(node, nNode, NODE_COLOR, fp);
    }

    size_t current_number_of_node = *nNode;

    if (node->children[0]) {
        PrintEdge(current_number_of_node, ++(*nNode), YES_COLOR, fp);
        nodedump(node->children[YES], nNode, fp);

        PrintEdge(current_number_of_node, ++(*nNode), NO_COLOR, fp);
        nodedump(node->children[NO], nNode, fp);
    }
}

void TreeDump(tree *tree) {
    size_t nNode = 0;
    FILE *fp = fopen(DOTPATH, "w");

    fputs("digraph structs {\n", fp);
    fputs("\tnode [color=black, shape=box, style=\"filled\"];\n", fp);

    nodedump(tree->root, &nNode, fp);

    fputs("}\n", fp);

    fclose(fp);

    system("dot tree -T png -o tree.png");
}