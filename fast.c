#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if(argc != 2){
        fprintf(stderr,"put a number in b");
        exit(1);
    }

    if(!argv[1]){
        fprintf(stderr,"yeah nah");
        exit(1);
    }

    for(int i = 0; i < strlen(argv[1]); i++){
        if(argv[1][i] < '0' || argv[1][i] > '9'){
            fprintf(stderr,"not a digit mate");
            exit(1);
        }
    }

    int M = strtol(argv[1],NULL,10);

    int **arr = (int **) malloc(sizeof(int *)*M);
    for(int i = 0; i < M; i++){
        arr[i] = (int *) malloc(sizeof(int)*M);
    }

    for(int i = 0; i < M; i++){
        for(int k = 0; k < M; k++){
            arr[i][k] = i;
        }
    }

    for(int i = 0; i < M; i++){
        free(arr[i]);
    }
    free(arr);
    printf("done\n");
    return 0;
}