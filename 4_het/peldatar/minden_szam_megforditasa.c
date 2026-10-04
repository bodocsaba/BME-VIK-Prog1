#include <stdio.h>

int main(){
    unsigned char tomb[1000];
    tomb[0] = 0b10110010;
    unsigned char temp = 0;
    for(int i=0;i<8;++i){
        unsigned char bit = (tomb[0] >> i) &1;
        temp = (temp << 1) | bit;
    }
    tomb[0] = temp;
    for(int i = 7; i >= 0; --i) {
        printf("%b", (tomb[0] >> i) & 1);
    }
    return 0;
}
