#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("N hosszu oldalu gyemant\n\n");
    printf("Milyen (n) hosszu legyen?\n\n");
    printf("n: ");
    int n;
    scanf("%d",&n);
    printf("\n");
    if(n<1){
        printf("Hiba, tul alacsony hosszusagot adtal meg (minimum 1)");
        return 0;
    }
    int szokoz_db_1 = n;
    int szokoz_db_2 = 1;
    //Felso resz
    for(int i=1;i<=n;i++){
        for(int y = szokoz_db_1;y>=1;y--)
            printf(" ");
        printf("/");
        szokoz_db_1--;
        for(int z=1;z<szokoz_db_2;z++)
            printf("  ");
        szokoz_db_2++;
        printf("\\\n");
    }
    //Also resz
    for(int i=1;i<=n;i++){
        for(int y=0;y<=szokoz_db_1;y++)
            printf(" ");
        printf("\\");
        szokoz_db_1++;
        for(int z=1;z<szokoz_db_2-1;z++)
            printf("  ");
        szokoz_db_2--;
        printf("/\n");
    }
    return 0;
}

