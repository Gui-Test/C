#include <stdio.h>
#include <math.h>

int main() {
   float x;
   int n,i,j;

    scanf("%f%d", &x, &n);
    float e_x = 0; //inicializa somatório com 0
    
    for (i = 0; i <=n; i++){
        float pot = 1;
        int fat = 1;
        for (j = 1; j <= i; j++){
            pot = pot * x;
            fat = fat * j;   
        }
        e_x = e_x + pot/fat;
    }
    printf("e elevado a %.3f = %f\n", x, e_x);
}