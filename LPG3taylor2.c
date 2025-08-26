#include <stdio.h>
#include <math.h>

//versão otimizada

int main() {
   double x;
   int n,i,j; 

    printf("digite o termo x e depois a quantidade de termos n\n");
    scanf("%lf%d", &x, &n);
    double e_x = 0; //inicializa somatório com 0
    
    for (i = 0; i <=n; i++){
        double termo = 1;
        for (j = 1; j <= i; j++){
            termo *= x/j;   
        }
        e_x += termo;
    }
    printf("e elevado a %.3f = %.15lf\n", x, e_x);
}