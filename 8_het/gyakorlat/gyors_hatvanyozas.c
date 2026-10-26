#include <stdio.h>
#include <math.h>

int hatvanyozas(int a, int k){
    if (k == 0) return 1;
    if (k == 1) return a;
    if(k % 2 == 0){
        return hatvanyozas(a,k/2) * hatvanyozas(a,k/2);
    }
    else{
        return a*hatvanyozas(a,k-1);
    }
}

int main(){
    printf("%d",hatvanyozas(4,3));
    return 0;
}
