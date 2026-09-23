#include <stdio.h>
#include <math.h>

double kob(double szam){
    return szam*szam*szam;
}
double abszolut(double szam){
    if(szam < 0)szam*=-1;
    return szam;
}

int main(){
    printf("Fuggvenyek_alapok\n\n");
    for(double i=-1.0;i<=1.0;i+=0.1)
        printf("%g, %g, |%g| %.4lf\n",i,kob(i),abszolut(i),sin(i));
    return 0;
}
