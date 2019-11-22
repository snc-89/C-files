#include <stdio.h>

int foo(char *s){
    int n;
    for(n=0;*s;s++){
        if((*s >= 'a') && (*s <='z')){
            *s = 'A' + (*s - 'a');
            n++;
        }
    }
    return n;
}

int main(int argc, char const *argv[])
{
    //char bar[] = "Comp202@MQ-S1";
    //int foobar = foo(bar);
    //printf("%d\n%s",foobar,bar);

    long int j = 2, k = 74, n[3];
    long int *p;

    p = &j;
    k = *p;
    p = &n[1];
    *p = k;
    n[k] = ++*p;

    //printf("%d %d %d %d",j,*p,n[k],k);
    int arr[5] = {1,19,30,4,5};
    int arr2[5] = {15,0,0,0,0};
    int *pointer = arr;
    printf("%d",*(pointer+3));
    return 0;
}