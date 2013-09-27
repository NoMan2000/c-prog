#include <stdio.h>

main()
{
    char    name[21];

    name[0] = 'M';
    name[1] = 'a';
    name[2] = 'r';
    name[3] = 'k';
    name[4] = '\0';

    printf("The contents of name are %s\n", name);

    fflush(stdin);
    getchar();
}
