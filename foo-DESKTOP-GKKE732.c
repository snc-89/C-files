#include <stdio.h>

int eax;
int ecx;
int edx;
unsigned int cmp = 0xc362d4aa;

int main(int argc, char const *argv[])
{

for (unsigned int i = 0x21212121; i < 0x7a7a7a7a; i++)
{
    if ((i % 0x100 < ' ' && i % 0x100 > 'z') ||
        ((i / 0x100) % 0x100 < ' ' && (i / 0x100) % 0x100 > 'z') ||
        ((i / 0x10000) % 0x100 < ' ' && (i / 0x10000) % 0x100 > 'z') ||
        ((i / 0x1000000) % 0x100 < ' ' && (i / 0x1000000) % 0x100 > 'z') ||)
    {
        continue;
    }
    if (i % 0x2222)
    {
        printf("%x", i)
    }
    for (int k = 0x2121; k < 0x7a7a; k++)
    {
        edx = k;
        eax = i;
        ecx = eax * 8;
        eax = edx;
        ecx ^= eax;
        if (ecx == cmp)
        {
            printf("\nRESULT: %x\n", i);
        }
    }
}
    
    return 0;
}

