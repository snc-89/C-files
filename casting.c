#include <stdio.h>

//little program to illustrate casting between signed and unsigned
int main()
{
    //cast unsigned to signed
    unsigned char a = 153;
    signed char b = (signed char)a;
    printf("%d      %d\n",a, b);

    //cast signed to unsigned
    signed int c = -1;
    unsigned int d = (unsigned int)c;
    printf("%d      %d\n", c, d);

    return 0;
}