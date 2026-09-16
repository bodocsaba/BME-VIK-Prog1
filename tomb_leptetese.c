#include <stdio.h>

int main(){
    char tomb[10] = {'P','i','t','a','g','o','r','a','s','z'};
    int lepteto = 10;
    for(int i=1;i<=10;i++){
        for(int y=0;y<10;y++){
            printf("%c ",tomb[y]);
        }
        printf("\n");
        for(int z=0;z<10;z++){
            char temp = tomb[z];
            tomb[z] = tomb[z+1];
            tomb[z+1] = temp;
        }
    }
    return 0;
}
