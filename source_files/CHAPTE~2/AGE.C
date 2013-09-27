#include <stdio.h>

main()
{
    int age;
    int half;
    int years;

    printf("Hello World\n");
    printf("Please enter your age: ");
    scanf("%d", &age);
    half = age / 2;
    years = age - 5;
    printf("A person half your age would be %d\n", half);
    printf("It has been %d years since you were 5\n", years);

    fflush(stdin);
    getchar();
}
