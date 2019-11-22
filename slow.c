#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int M = 10000;
    int **arr = (int **) malloc(sizeof(int *)*M);
    for(int i = 0; i < M; i++){
        arr[i] = (int *) malloc(sizeof(int)*M);
    }

    for(int i = 0; i < M; i++){
        for(int k = 0; k < M; k++){
            arr[k][i] = i;
        }
    }

    for(int i = 0; i < M; i++){
        if(arr[i]){
            free(arr[i]);
        }
    }
    free(arr);
    arr = NULL;
}