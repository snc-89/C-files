#include <stdio.h>
#include <string.h>

void evilSolution(char string[], int total, int compareTotal, int compareLength)
{
    for(int i = 0; i < strlen(string); i++){
        total += string[i];
    }

    int totalDifference = compareTotal - total;
    int lengthDifference = compareLength - strlen(string);
    int result = totalDifference/lengthDifference;

    printf("%s",string);
    for(int i = 0;i < lengthDifference;i++){
        printf("%c",result);
    }
}

int main(int argc, char const *argv[])
{
    evilSolution("`wjjsh",0x340,0xae6,0x16);
    return 0;
}