#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, n, i;
    printf("Quantos valores? ");
    scanf("%d", &n);
    p = malloc(sizeof(int) * n);
    for(i=0;i<n;i++){
        printf("P[%d]= ", i);
        scanf("%d", p + i);
    }
    printf("\n/////////////\n");
    for(i=0;i<n;i++){
        printf("P[%d]= %d   end.: %d\n", i, *(p+i), p+i);
    }
    
    free(p);
}