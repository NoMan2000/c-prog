#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char    name[21];
    char    string2[40];
    int     length ;

    strcpy(name, "Mark");
    strcpy(string2, "My name is ");
    strcat(string2, name);
    strcat(string2, "\n");

    printf(string2);
    length = strlen(string2);
    printf("The length of the string >>%s<< is %d characters\n",
                                            string2, length);

    return 0;
}
