#include <stdio.h>

int main(){
    printf("Legkisebb\n\n");
    int tomb[10] = {25,69,54,8,77,6,29,10,3,98};
    int legkisebb = tomb[0];
    int minhely;
    printf("A tomb: ");
    for(int i=0;i<10;i++){
        printf("[%d]=%d ",i,tomb[i]);
        if(tomb[i]<legkisebb){
            legkisebb = tomb[i];
            minhely = i;
        }
    }
    printf("\n");
    printf("A legkisebb elem a tombben: %d\n",legkisebb);
    printf("A legkisebb elem indexe tombben: %d\n",minhely);
    printf("Jelolve: ");
    for(int i=0;i<10;i++){
        if(tomb[i] == legkisebb)
            printf("%d[MIN] ",legkisebb);
        else
            printf("%d ",tomb[i]);
    }

    return 0;
}
