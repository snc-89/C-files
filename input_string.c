#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcpy(char *dest, char *src){
    while((*dest = *src) != 0){
        if(*dest >= 'a' && *dest <= 'z'){
            *dest = *dest - ('a' - 'A');
        }
        src++;
        dest++;
    }
}

int main(int argc, char const *argv[])
{
    if(argc != 2){
        fprintf(stderr,"no string b");
        exit(1);
    }

    char *source = argv[1];
    char *destination = (char *) malloc(strlen(source)+1); 

    if(source == NULL || strlen(source) == 0){
        fprintf(stderr,"string's fucked");
        exit(1);
    }

    my_strcpy(destination, source);

    printf("%s\n", destination);
    free(destination);
    return 0;
}
