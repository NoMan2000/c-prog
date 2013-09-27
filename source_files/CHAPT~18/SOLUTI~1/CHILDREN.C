#include <stdio.h>

main()
{
    int brosis;
    int children;

    printf("How many brothers and sisters do you have? ");
    scanf("%d", &brosis);
    printf("How many children do you have? ");
    scanf("%d", &children);
    printf("You have %d brothers and sisters, and %d children\n",
                        brosis, children);

    fflush(stdin);
    getchar();
}
