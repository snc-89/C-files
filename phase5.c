#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[] = "topaz";
    char foo[5];
    char bar[5];
    char eax;
    char edx;
    char r9d;
    for(int i = 0; i < 5; i++){
        eax = string[i] - 0x52;
        edx = eax;
        edx = edx >> 1;
        eax &= 1;
        //printf("%d\n",eax);
        r9d = edx + 0x52;
        edx += 0x67;
        if(eax == 0){
            edx = r9d;
        }
        foo[i] = edx;
        bar[i] = eax;
    }

    int a = 10;
    int b = 11;
    a = a >> 1;
    b = b >> 1;
    printf("a shifted: %d\nb shifted: %d\n",a,b);

    foo[5] = '\0';
    bar[5] = '\0';
    printf("%s\n",string);
    printf("%s",foo);
    return 0;
}
    