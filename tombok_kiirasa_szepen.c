#include <stdio.h>

int main(){
    printf("Tomb kiirasa\n\n");
    printf("Mennyi szamot szeretnel kiirni?\n\n");
    int n;
    printf("n: ");
    scanf("%d",&n);
    printf("\n");
    int tomb[n];
    for(int i=0;i<n;i++){
        printf("Az %d. szam: ",i+1);
        scanf("%d",&tomb[i]);
        printf("\n");
    }
    printf("A tomb:");
    for(int i=0;i<n-1;i++)
        printf(" %d,",tomb[i]);
    printf(" %d.",tomb[n-1]);
    return 0;
}
