#include <stdio.h>

int main(int argc, char const *argv[])
{   
    char foo = 100+1;
    printf("100+1   %d\n",foo);
    foo = 10+-11;
    printf("10+-11  %d\n",foo);
    foo = 126+1;
    printf("126+1   %d\n",foo);
    foo = 127+1;
    printf("127+1   %d\n",foo);
    foo = 127+127;
    printf("127+127   %d\n",foo);
    foo = -128+-1;
    printf("-128+-1   %d\n",foo);

    return 0;
}