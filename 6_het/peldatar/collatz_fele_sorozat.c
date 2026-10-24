#include <stdio.h>

void iterativ_collatz(int szam){
    int lepesekszama = 0;
    while(szam != 1){
        printf("%d ",szam);
        if(szam % 2 == 0)szam /= 2;
        else szam = szam*3+1;
        lepesekszama++;
    }
    printf("%d\n",szam);
    printf("%d lepes kellett.",lepesekszama);
    printf("\n");
}

void rekurziv_collatz(int szam, int lepesekszama){
    printf("%d ", szam);
    if(szam == 1){
        printf("\n%d lepes kellett.", lepesekszama);
        return;
    }
    if(szam % 2 == 0)rekurziv_collatz(szam/2,lepesekszama+1);
    else rekurziv_collatz(szam*3+1,lepesekszama+1);
}

int main(){
    iterativ_collatz(23);
    printf("\n");
    rekurziv_collatz(23,0);
    return 0;
}
