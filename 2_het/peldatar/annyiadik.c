#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Annyiadik\n\n");
    int tomb[10] = {1,2,3,4,5,6,7,8,9,10};
    int n;
    printf("A 10 elemu tomb hanyadik elemet szeretned kiiratni?\n");
    printf("n: ");
    scanf("%d",&n);
    printf("\n");
    for(int i=0;i<10;i++){
        if(i == n){
            printf("A tomb %d.eleme: %d",n,tomb[i-1]);
        }
    }
    return 0;
}
