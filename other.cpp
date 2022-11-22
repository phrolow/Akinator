#include "akinator.h"

int ask() {
    int ans = EOF;

    do {
        ans = getchar();

        fflush(stdin);
    } while(!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

    if(ans == 'y' || ans == 'Y')
        return 1;

    return 0;
}

void Start(tree *tree) {
    int choice = 0;

    do {
        printf("Hey, what d'you want? We have:\n");
        printf("1. Akinator\n");
        printf("2. Define\n");
        printf("3. Comparator\n");
        printf("Press number to continue or any other key to exit\n");

        choice = 0;
        scanf("%d", &choice);

        fflush(stdin);

        switch (choice) {
            case 1:
                Akinator(tree);
                break;
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