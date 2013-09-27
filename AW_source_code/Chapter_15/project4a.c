#include <stdio.h>

int
main(void)
{
    char text[12];

    fgets(text, 12, stdin);
    printf("%s\n", text);

    return 0;
}
