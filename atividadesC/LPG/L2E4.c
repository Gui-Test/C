#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Calculando e.
double calcula_e(int n, int i, double termo);

int main() {
   int n; 

   printf("digite a quantidade de termos n\n");
   scanf("%d", &n);

   double e = calcula_e(n,0,1);
   printf("e = %lf\n", e);

}

double calcula_e(int n, int i, double termo){
    if (i <= n )
        return termo + calcula_e(n, i+1, termo*1/(i+1));
    else 
        return 0;
}
