#include <stdio.h>

int main(){
    printf("Zh statisztika II.\n\n");
    int eredmenyek[31] = {0};
    int elso,masodik,harmadik;
    printf("Add meg a harom feladat pontszamait\n\n");
    scanf("%d %d %d",&elso,&masodik,&harmadik);
    int osszeg = elso+masodik+harmadik;
    while(elso != -1 || masodik != -1 || harmadik != -1){
        eredmenyek[osszeg]++;
        scanf("%d %d %d",&elso,&masodik,&harmadik);
        osszeg = elso+masodik+harmadik;
    }
    printf("\n");
    for(int i=0;i<30;i++){
        if(eredmenyek[i] > 0){
            printf("%2d pontos: %2d db\n",i,eredmenyek[i]);
        }
    }
    return 0;
}
