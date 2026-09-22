#include <stdio.h>
#include <stdlib.h>

int main(){
    int tomb[48] = {0};
    int ora,perc;
    printf("Add meg az orat, percet\n\n");
    scanf("%d %d", &ora, &perc);
    while(ora != -1 || perc != -1){
        if(perc <=29 && perc >=0 ){
            tomb[ora*2]++;
        }
        else if(perc >=30 && perc <=59){
            tomb[ora*2+1]++;
        }
        scanf("%d %d",&ora,&perc);
    }
    for(int i=0;i<48;i++){
        if(tomb[i] > 0){
            if(i % 2 == 0){
                printf("%2d:00-%2d:29 kozott %d utas\n",i/2,i/2,tomb[i]);
            }
            else{
                printf("%2d:30-%2d:59 kozott %d utas\n",i/2,i/2,tomb[i]);
            }
        }
    }
    return 0;
}
