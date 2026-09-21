#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Gyok ketto\n\n");
    double gyokketto = 1.0;
    double x = 0.1;
    for(int i=1;i<=10;i++){
        while( (gyokketto+x)*(gyokketto+x) < 2){
            gyokketto += x;
        }
        x /= 10;
    }
    printf("%.10lf",gyokketto);
    return 0;
}
