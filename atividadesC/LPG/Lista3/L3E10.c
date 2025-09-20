#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Calculando e iterativo e recursivo
double e_iterativo(int n);
double e_recursivo(int n, int i, double termo);

int main() {
   int n; 

   printf("digite a quantidade de termos n\n");
   scanf("%d", &n);

   double e1 = e_iterativo(n);
   printf("e iterativo = %lf\n", e1);
   double e2 = e_recursivo(n,0,1.0);
   printf("e recursivo = %lf\n", e2);

}

double e_iterativo(int n){
    double ei = 1.0;
    double termu = 1.0;
    for (int i = 1; i<=n; i++){
        termu *= 1.0/(i);
        ei += termu;
    }
    return ei;
}

double e_recursivo(int n, int i, double termo){
    if (i <= n )
        return termo + e_recursivo(n, i+1, termo*1/(i+1));
    else 
        return 0;
}