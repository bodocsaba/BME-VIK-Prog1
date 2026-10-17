#include <stdio.h>

double atlag(int *tomb, int k, int sz){
    double atlag = 0;
    for(int i=k;i<k+sz;++i)atlag += tomb[i];
    return atlag / sz;
}

int kereses(int *tomb, int meret, int sz){
    int Legritkabb = 0;
    double Atlag = atlag(tomb,0,sz);
    for(int i=1;i<=meret-sz;++i){
        double temp = atlag(tomb,i,sz);
        if(temp < Atlag){
            Legritkabb = i;
            Atlag = temp;
        }
    }
    return Legritkabb;
}

int main(){
    int vendegszam[6] = {8,5,8,2,1,0};
    printf("Atlagosan %g vendeg lakik a 3-5.szinteken.\n",atlag(vendegszam,3,3));
    printf("A legritkabban lakott szint: %d\n",kereses(vendegszam,6,5));
    printf("%d szinttol kezdodik.",kereses(vendegszam,6,3));
    return 0;
}
