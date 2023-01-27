#ifndef AKINATOR_AKINATOR_DEBUG_H
#define AKINATOR_AKINATOR_DEBUG_H

const char* const    PNGPATH = "tree.png";
const char* const    HTMLPATH = "log.html";
const char* const    DOTPATH = "tree";

const size_t COLORLEN = 8;

const char  ROOT_COLOR[COLORLEN] = "#DAA520",
            TERMINAL_COLOR[COLORLEN] = "#368A8A",
            NODE_COLOR[COLORLEN] = "#90EE90",
            YES_COLOR[COLORLEN] = "#3CB371",
            NO_COLOR[COLORLEN] = "#CD5C5C";

void TreeDump(tree *tree);

void TreeVerify(tree *tree);

#endif //AKINATOR_AKINATOR_DEBUG_H
