#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Obs: por algum motivo o gcc não está reconhecendo o math.h então é necessário escrever "gcc L2E6_E7.c -lm"
// na hora de compilar

double seno_cosseno(double x, int n,double termo, int k);
double seno(double x, int n);
double cosseno(double x, int n);

int main(int argc, char const *argv[])
{
    double x = M_PI;
    int n;
    scanf(" %i", &n);
    printf("\n Seno: %.15lf", seno(x,n));
    printf("\n Cosseno: %.15lf", cosseno(x,n));
}

//tá endendi o que eu tava fazendo de errado %d não é pra double, é %lf


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