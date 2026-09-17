#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int m[10] = {1,2,3,4,5,6,7,8,9,10};
    int z;
    printf("Adj meg egy szamot\n\n");
    printf("z: ");
    scanf("%d",&z);
    printf("\n");
    bool van = false;
    for(int i=0;i<9;i++){
        for(int y=1;y<10;y++)
            if((m[i]*m[y]) == z)
                van = true;
    }
    if(van)
        printf("Van ketto olyan szam a tombben, aminek szorzata %d",z);
    else
        printf("Nincs olyan szam amelynek szorzata %d",z);

    return 0;
}
