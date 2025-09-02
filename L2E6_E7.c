#include <stdio.h>
#include <math.h>

double seno_cosseno(double x, int n,double termo, int k);
double seno(double x, int n);
double cosseno(double x, int n);

int main(int argc, char const *argv[])
{
    double x = M_PI;
    int n;
    scanf(" %i", &n);
    printf("\n Seno: %d", (seno(x,n)));
    printf("\n Cosseno: %d", (cosseno(x,n)));
}


// Seno : termo = x , k = 1;
// Cosseno : termo = 1, k = 0;

double seno_cosseno(double x, int n, double termo, int k){
    double s=0;
    int i;
    
    for (i = 0;i<n;i++){
        s+=termo;
        termo*= x/(k+1) * x/(k+2) *(-1);
        k+=2; 
    }
    
    return s;
}

double seno(double x, int n){
  return seno_cosseno(x,n, x, 1);   
}

double cosseno(double x, int n){
  return seno_cosseno(x,n, 1, 0);   
}