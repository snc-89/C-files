#include <stdio.h>


//simple program to illustrate the difference between *p++, *++p, ++*p
int main(int argc, char const *argv[])
{
    int one[3] = {10, 20, 30};
    int two[3] = {10, 20, 30};
    int three[3] = {10, 20, 30};
    int *p;
    p = one;
    printf("effect of *p++ before: %d", *p);
    printf("    during: %d", *p++);
    printf("    after: %d\n", *p);

    p = two;
    printf("effect of *++p before: %d", *p);
    printf("    during: %d", *++p);
    printf("    after: %d\n", *p);
    
    p = three;
    printf("effect of ++*p before: %d", *p);
    printf("    during: %d", ++*p);
    printf("    after: %d\n", *p);
    return 0;
}