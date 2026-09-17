#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Kisebbek vagy nagyobbak?\n\n");
    int p;
    printf("Adj meg egy random (p) erteket: ");
    scanf("%d",&p);
    printf("\n");

    int kisebb_db = 0;
    int nagyobb_db = 0;
    srand(time(0));
    int tomb[10]; // lehet nagyobb elemû tömb is, annyi volt meghatározva, hogy 'm' egészekbõl álló tömb
    for(int i=0;i<10;i++){
        tomb[i] = rand();
        if(tomb[i] > p)
            nagyobb_db++;
        else if(tomb[i] < p)
            kisebb_db++;
    }
    if(kisebb_db > nagyobb_db)
        printf("A tombben p-nel kisebb szamokbol van tobb: %d db",kisebb_db);
    else if(kisebb_db < nagyobb_db)
        printf("A tombben p-nel nagyobb szamokbol van tobb: %d db",nagyobb_db);
    else
        printf("A tombben ugyannyi kisebb es nagyobb szam van, mint p  %d db kisebb es %d db nagyobb",kisebb_db,nagyobb_db);

    return 0;
}
