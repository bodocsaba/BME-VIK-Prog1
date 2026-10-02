#include <stdio.h>

void min_max(int *tomb, int meret, int *minimum, int *maximum){
    *minimum = 0; *maximum = 0;
    for(int i=1;i < meret;++i){
        if(tomb[i] < tomb[*minimum]) *minimum = i;
        if(tomb[i] > tomb[*maximum]) *maximum = i;
    }
}

int main(){
    int tomb[10] = {3,2,1,4,5,6,7,8,9,10};
    int minimum,maximum;
    min_max(tomb,10,&minimum,&maximum);
    printf("Minimum cime: %p, index: %d\n",&tomb[minimum],minimum);
    printf("Maximum cime: %p, index: %d\n",&tomb[maximum],maximum);
    return 0;
}
