#include "akinator.h"
#include "akinator_debug.h"

int main(int argc, char **argv) {
    if(!argc) {
        printf("Too few arguments!");
        exit(1);
    }

    if(!checkfile(argv[1])) {
        printf("Invalid file");
        exit(2);
    }

    tree tree = {};

    struct text txt = textFromFile(argv[1]);
    LoadTree(&tree, &txt);

    Start(&tree);

    TreeDump(&tree);

    SaveTree(&tree, argv[1]);

    TreeDtor(&tree);

    return 0;
}
