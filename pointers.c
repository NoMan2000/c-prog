#include <stdio.h>

struct employee {
    int id;
    const char * name;
    const char * role;

};
int main(){
    int x = 1, y=2, z[10];
    
    int *ip; /* A pointer to an int */
    ip = &x; /* Address OF x */
    y = *ip; /* Contents OF ip */
    *ip = 0; /* Clear where ip points */
    ip = &z[0]; /* Addr of 1st element of z array */
    
    struct employee joe = {42, "Joe", "Boss"};
    struct employee *ep = &joe;
    printf("%s is the %s and has an id of %d\n", joe.name, joe.role, joe.id);
    printf("%s is the %s and has an id of %d\n", ep->name, ep->role, ep->id);
    
}

