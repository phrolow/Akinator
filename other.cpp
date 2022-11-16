#include "akinator.h"

int ask() {
    int ans;

    do {
        ans = getchar();

        fflush(stdin);
    } while(!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

    if(ans == 'y' || ans == 'Y')
        return 1;

    return 0;
}

void Start(tree *tree) {
    do {
        printf("Hey, what d'you want? We have:\n");
        printf("1. Akinator\n");
        printf("2. Define\n");
        printf("3. Comparator\n");
        printf("Press number to continue or any other key to exit\n");

        switch (getchar()) {
            case 1:
                Akinator(tree);
                breal;
            case 2:
                Definitor(tree);
                break;
            case 3:
                Comparator(tree);
                break;
            default:
                return;
        }

        printf("Do you want to continue? [Y/N]\n");
    } while (ask());
}