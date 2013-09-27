/* This is a comment. 
    Anything put in there is not read by the compiler.
    This is for humans only.
*/

#include <stdio.h>

void callFunction(){
    printf("This is an executable block of code.\n");    
}


int main(void) 
{ /* Every C program needs a main function */ 
    
    int myVar =5;
    int varNumberTwo = 6; 
    
    callFunction();
    
    printf("Hello World\n");
    printf("This should be a weird number %d \n", myVar);
    printf("This is the second number %d \n", varNumberTwo);
}
