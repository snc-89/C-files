#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main();
int cannotcall();

void my_strcpy(char *dest, char *src){
    for( ; *src; src++, dest++)
        *dest = *src;
    *dest = 0;
    return;
}

void printchar(char c){
    if(c <  ' ' || c > '~')
        fprintf(stderr, "   ");
    else
        fprintf(stderr, " %c", c);
    return;
}

void stackdump(long *p){
    int i, j;
    char *b = (char *) p;
    fprintf(stderr, "   %16p:   main\n", main);
    fprintf(stderr, "   %16p:   cannotcall\n", cannotcall);
    fprintf(stderr, "   %16p:   stack dump address\n", p);
    for(i = 0; i < 2; i++){
        fprintf(stderr, "   %0161x %0161x\n", p[i*2],
            p[i*2+1]);
        fprintf(stderr, "   ");
        for(j = 0; j < 8; j++)
            printchar(b[i*16+7-j]);
        fprintf(stderr, "   ");
        for(j = 0; j < 8; j++)
            printchar(b[i*16+8+7-j]);
        fprintf(stderr, "   \n");
    }
}

int cannotcall(){
    fprintf(stderr, "How did you get here?\n");
    exit(0);
}

void overreturn(char *str){
    int i;
    char lower[] = "Lower string";
    stackdump((long *) lower);
    //strcpy(lower, str); //gcc detects bufferoverflow here
    my_strcpy(lower, str);
    stackdump((long *) lower);
    return;
}

int main(){
    overreturn("Rain in Spain");
    //overreturn("the rain in spain is a pain");
    //overreturn("123456781234567812345678\x66\x06\x40\x00");
    fprintf(stderr, "back to main...\n");
    return 0;
}
