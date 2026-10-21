#include <stdio.h>

int main(){
    // a)
    /*
    for(int i=0;i<32;++i){
        printf("%2d. %10u\n",i, 1U << i);
    }
    */
    // b)
    /*
    unsigned int bit = 1;
    int index = 0;
    while(bit > 0){
        printf("%2d. %10u\n",index++, bit);
        bit <<= 1;
    }
    */
    // c)
    unsigned long long bit = 1;
    int hanybites = 0;
    while(bit > 0){
        printf("%2d. %20llu\n",hanybites++, bit);
        bit <<= 1;
    }
    printf("Ez a tipus %d bit hosszu\n",hanybites);
    return 0;
}
