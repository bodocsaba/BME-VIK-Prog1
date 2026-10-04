#include <stdio.h>

int main(){
    unsigned char tomb[100];
    tomb[0] = 0b01001010;
    tomb[1] = 0b11111101;
    tomb[2] = 0b01011110;
    tomb[3] = 0b00001101;
    unsigned char elozobit = 0;
    for(int i=0;i<4;++i){
        unsigned char nextbit = (tomb[i] >> 0) &1;
        if(i == 0)elozobit = (tomb[3] >> 0) &1;
        unsigned char temp = 0;
        temp = (temp << 1) | elozobit;
        for(int y=7;y>=1;--y){
            unsigned char bit = (tomb[i] >> y) &1;
            temp = (temp << 1) | bit;
        }
        tomb[i] = temp;
        elozobit = nextbit;
    }
    printf("\n\n");
    for(int i=0;i<4;++i){
        printf("%d. ",i);
        for(int y=7;y>=0;--y){
            unsigned char temp = (tomb[i] >> y) &1;
            printf("%b", temp);
        }
        printf("\n");
    }
    return 0;
}
