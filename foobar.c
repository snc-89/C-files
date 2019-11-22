#include <stdio.h>


int main(int argc, char const *argv[])
{

    int foo[4][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8}};

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 5; k++){
            foo[i][k] = foo[0][k];
        }
    }

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 5; k++){
            printf("%d ",foo[i][k]);
        }
        printf("\n");
    }
    return 0;
}
