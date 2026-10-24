#include <stdio.h>

void forditva(void){
    char c;
    if(scanf(" %c",&c) == 1){
        forditva();
        printf("%c",c);
    }
}

int main(){
    forditva();
    return 0;
}
