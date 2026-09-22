#include <stdio.h>

int main(){
    printf("Kasszak II.\n\n");
    int vevok[32] = {0};
    int kassza;
    printf("Add meg a kassza sorszamat\n\n");
    scanf("%d",&kassza);
    int ossz = 0;
    while(kassza != 0){
        vevok[kassza-1]++;
        ossz++;
        scanf("%d",&kassza);
    }
    printf("\n");
    int index = 0;
    for(int i=1;i<32;i++){
        if(vevok[i] > vevok[index]){
            index = i;
        }
    }
    printf("A(z) %d. kasszanal voltak a legtobben -> ez az osszes vevok %g%%-a\n",index+1,100.0*vevok[index]/ossz);
    return 0;
}
