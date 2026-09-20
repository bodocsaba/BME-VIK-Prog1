#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    printf("Egyforma elemek\n\n");
    printf("Hany szam lesz?\n\n");
    int n;
    printf("n: ");
    scanf("%d",&n);
    printf("\n");
    printf("Add meg a szamokat\n\n");
    double tomb[n];
    for(int i=0;i<n;i++){
        printf("%d.szam: ",i+1);
        scanf("%lf",&tomb[i]);
        printf("\n");
    }
    bool kulonbozo = true;
    for(int i=0;i<n-1;i++){
        for(int y=i+1;y<n;y++){
            if(tomb[i] == tomb[y]){
                kulonbozo = false;
                break;
            }
        }
    }
    if(kulonbozo){
        printf("A tomb minden eleme kulonbozo.");
    }
    else{
        printf("A tomb nem minden elem kulonbozo");

    }
    return 0;
}
