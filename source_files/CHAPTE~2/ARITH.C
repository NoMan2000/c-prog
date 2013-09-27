#include <stdio.h>

main()
{
    int    x, y, z;

    x = 9;
    y=(x+6)/3;
    z = x * y + 1 + 2 - 3 * 4;
    x = (10 + 35) % 12;
    printf("x = %d, y = %d, z = %d\n", x, y, z);

    printf("Answer is %d\n", 3 * 17);

    fflush(stdin);
    getchar();
}
