#include <stdio.h>

main()
{
    int age;

    printf("Hello World\n");
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("The age you entered is %d\n", age);

    fflush(stdin);
    getchar();
}
