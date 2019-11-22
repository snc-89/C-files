#include <stdio.h>


int main(int argc, char const *argv[])
{
    int *a, *b, c, d;

    a = b;
    b = a;

    c = &d;
    d = &c;

    printf("%p\n%p\n%p\n%p\n", a,d,c,d);

    return 0;
}

