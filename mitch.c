#include <stdio.h>

int main(int argc, char const *argv[])
{
    char memString[] = "mcepy";
    char result[5];
    int esi = 0x323;
    int compareTotal = 0xd29;
    int length = 5;
    int compareLength = 0x33;
    for(int i = 0; i < 5; i++){
        int eax = memString[i];
        int edx = eax;
        esi += edx;
        eax -= 0x52;
        edx = eax;
        edx = edx >> 1;
        eax &= 1;
        int r9d = edx+0x52;
        edx += 0x67;
        if(eax == 0){
            edx = r9d;
        }
        result[i] = edx;
        
    }
    int totalDifference = compareTotal - esi;
    int lengthDifference = compareLength - length;
    int character = totalDifference/lengthDifference;
    printf("%s",memString);
    for(int i = 0; i < lengthDifference; i++){
        printf("%c",character);
    }
    return 0;
}
