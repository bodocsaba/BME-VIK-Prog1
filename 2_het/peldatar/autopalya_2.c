#include <stdio.h>
#include <stdlib.h>

int main(){
    int ora_osszeg[24] = {0};
    int ora = 1;
    int perc = 1;
    int sebesseg = 1;
    printf("Add meg az orat,percet es sebesseget\n\n");
    while(ora != 0 || perc != 0 || sebesseg != 0){
        scanf("%d %d %d",&ora,&perc,&sebesseg);
        if(sebesseg > 140 && sebesseg <=180){
            ora_osszeg[ora] += 30000;
        }
        else if(sebesseg > 180){
            ora_osszeg[ora] += 100000;
        }
    }
    for(int i=0;i<24;i++){
        if(ora_osszeg[i] > 0){
            printf("%d:00-%d:59, %d Ft\n",i,i,ora_osszeg[i]);
        }
    }
    return 0;
}
