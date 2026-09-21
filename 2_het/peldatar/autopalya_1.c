#include <stdio.h>
#include <stdlib.h>

int main(){
    int ora_seb[24] = {0};
    int ora = 1;
    int perc = 1;
    int sebesseg = 1;
    printf("Add meg az orat,percet es sebesseget\n\n");
    while(ora != 0 || perc != 0 || sebesseg != 0){
        scanf("%d %d %d",&ora,&perc,&sebesseg);
        if(ora_seb[ora] < sebesseg){
            ora_seb[ora] = sebesseg;
        }
    }
    for(int i=0;i<24;i++){
        if(ora_seb[i] > 130){
            printf("%d:00-%d:59 -> %d km/h\n",i,i,ora_seb[i]);
        }
    }
    return 0;
}
