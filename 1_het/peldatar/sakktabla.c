#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Sakktabla\n\n"); // ezt biztosan lehet tobb ciklussal is megoldani
    for(int i=1;i<=8;i++){   // ciklus valtozokat elneveztem erthetoseg celjabol
        if(i % 2 != 0){
            for(int sor_kiir=1;sor_kiir<=2;sor_kiir++){
                printf("\n");
                for(int hanyszor_kiir = 1;hanyszor_kiir<=4;hanyszor_kiir++){
                    for(int x_db=1;x_db<=2;x_db++)
                        printf("X");
                    for(int szokoz=1;szokoz<=2;szokoz++)
                        printf(" ");
                }
            }
        }
        else
            for(int sor_kiir=1;sor_kiir<=2;sor_kiir++){
                printf("\n");
                for(int hanyszor_kiir = 1;hanyszor_kiir<=4;hanyszor_kiir++){
                    for(int szokoz=1;szokoz<=2;szokoz++)
                        printf(" ");
                    for(int x_db=1;x_db<=2;x_db++)
                        printf("X");
                }
            }
    }
    return 0;
}
