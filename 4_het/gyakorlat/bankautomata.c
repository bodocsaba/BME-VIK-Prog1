#include <stdio.h>

int main(){
    int bankjegyek[12] = {5,10,20,50,100,200,500,1000,2000,5000,10000,20000};
    int penz;
    printf("Add meg a penzosszeget: ");
    scanf("%d",&penz);
    printf("\n\n");
    printf("%d Ft = ",penz);
    int db = 0;
    for(int i=11;i>=0;i--){
        while(penz - bankjegyek[i] > -1){
            db++;
            penz -= bankjegyek[i];
        }
        if(db > 1) printf("%d*%d Ft",db,bankjegyek[i]);
        else if(db == 1) printf("%d Ft",bankjegyek[i]);
        if(penz == 0){
            printf(".");
            i = 0;
        }
        else if(db > 0) printf (" + ");
        db = 0;
    }
    return 0;
}
