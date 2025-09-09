#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Série de Taylor
double taylor(double x, int n, int i, double termo);

int main() {
   double x;
   int n; 

    printf("digite o termo x e depois a quantidade de termos n\n");
    scanf("%lf%d", &x, &n);
  
    double e_x = taylor(x,n,0,1);

    printf("Serie de Taylor:\n");
    printf("e elevado a %.3f = %.15lf\n", x, e_x);
}

double taylor(double x, int n, int i, double termo){
    if (i <= n )
        return termo + taylor(x, n, i+1, termo*x/(i+1));
    else 
        return 0;
}