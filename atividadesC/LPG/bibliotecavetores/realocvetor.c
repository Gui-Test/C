#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, n, m, i;
    printf("Quantos valores? ");
    scanf("%d", &n);
    p = malloc(sizeof(int) * n);
    for(i=0;i<n;i++){
        printf("P[%d]= ", i);
        scanf("%d", p + i);
    }
    
    printf("Quantos valores a mais? ");
    scanf("%d", &m);

    p = realloc(p, sizeof(int)*(n+m));

    for(i=n;i<n+m;i++){
        printf("P[%d]= ", i);
        scanf("%d", p + i);
    }
    printf("\n/////////////\n");

    for(i=0; i<n+m;i++)
        printf("P[%d]: %d\n", i, p[i]);    
    free(p);
}