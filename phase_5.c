#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[] = "zapper";
    char foo[6];
    for(int i = 0; i < 6; i++){
        foo[i] = string[i] - 0x5d;
        foo[i] &= 0x1f;
        foo[i] ^= 0x1e;
        foo[i] += 0x5d;
    }
    foo[6] = '\0';
    printf("%s",foo);
    return 0;
}
