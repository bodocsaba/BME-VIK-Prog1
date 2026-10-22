#include <stdio.h>
#include <stdbool.h>

void buborekrendezes(double* tomb, int meret){
    int voltcsere = false;
    for(int i=meret-1;i>0;--i){
        for(int y=0;y<i;++y){
            if(tomb[y] > tomb[y+1]){
                double temp = tomb[y];
                tomb[y] = tomb[y+1];
                tomb[y+1] = temp;
                voltcsere = true;
            }
        }
        if (!voltcsere)break;
    }
}

void kiir(double* tomb, int meret){
    for(int i=0;i<meret;++i)printf("%g ",tomb[i]);
    printf("\n");
}

void linearis_kereses(double* tomb, int meret, double szam, int* min, int* max){
    *min = -1; *max = -1;
    bool eleje = false;
    for(int i=0;i<meret;++i){
        if(tomb[i] == szam && !eleje){
            *min = i;
            *max = i;
            eleje = true;
        }
        else if(tomb[i] == szam)*max = i;
    }
}

void binaris_kereses(double* tomb, int meret, double szam, int* min, int* max){
    *min = -1;
    *max = -1;

    int bal = 0;
    int jobb = meret - 1;
    while(bal <= jobb){
        int kozep = bal + (jobb - bal) / 2;
        if(tomb[kozep] == szam){
            *min = kozep;
            jobb = kozep - 1;
        }
        else if(tomb[kozep] < szam){
            bal = kozep + 1;
        }
        else{
            jobb = kozep - 1;
        }
    }

    bal = 0;
    jobb = meret - 1;
    while(bal <= jobb){
        int kozep = bal + (jobb - bal) / 2;
        if(tomb[kozep] == szam){
            *max = kozep;
            bal = kozep + 1;
        }
        else if(tomb[kozep] < szam){
            bal = kozep + 1;
        }
        else{
            jobb = kozep - 1;
        }
    }
}

int main(){
    double tomb[10] = {1,2,9,9,9,9,9,9,9,10};
                    //{0,1,2,3,4,5,6,7,8, 9}
    buborekrendezes(tomb,10);
    kiir(tomb,10);
    int min, max;
    linearis_kereses(tomb,10,9,&min,&max);
    if(min != -1)printf("A keresett a szam a [%d,%d] tartomanyban van.\n",min,max);
    else printf("Hiba, a keresett szam nincs benne az ertelmezesi tartomanyban.\n");
    binaris_kereses(tomb, 10, 9, &min, &max);
    if(min != -1) {
        printf("Binaris kereses: A keresett szam a [%d, %d] tartomanyban van.\n", min, max);
    } else {
        printf("Hiba, a keresett szam nincs benne a tartomanyban.\n");
    }
    return 0;
}
