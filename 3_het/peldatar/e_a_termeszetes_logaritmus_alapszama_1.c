#include <stdio.h>

double e(int n){
    double e = 1;
    if(n > 1){
        for(int i=1;i<=n;i++){
            double faktorialis = 1;
            for(int y=1;y<=i;y++){
                faktorialis *= y;
            }
            e += 1/faktorialis;
        }
    }
    return e;
}
int main(){
    printf("e: a termeszetes logaritmus alapszama I.\n\n");
    int n = 10;
    printf("e = %.10g",e(n));
    return 0;
}
