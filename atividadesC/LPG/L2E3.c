#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Séries de Pi

double gregory(double grego,double m,int k);
double nilakantha(double nila,int k);

int main(int argc, char const *argv[])
{
    int k;
    double grego = 0;
    double nila = 3.0;

    printf("Digite o numero de termos das series de pi\n");
    scanf("%d", &k);

    printf("Serie de Gregory: %lf\n", gregory(grego,0,k));
    printf("Serie de Nilakantha: %lf\n", nilakantha(nila,k));

    return 0;
}

double gregory(double grego,double m,int k){
    if (k <= 1){
        return 4.0;
    }
    m = (2*(k)) - 1;
    
    if (k % 2 == 0){
        grego = (-1)*(4.0/m); 
    }else{
        grego = 4.0/m;
    }

    return grego + gregory(grego, m, k-1);
}

double nilakantha(double nila,int k){
    int m = 2;
    int sinal;  
    double termo; 
    double divi;  
      
   
      for (int i=1;i<=k;i++){
        nila+=termo;
        if (i % 2 == 0){
            sinal = -1;
        }else{
            sinal = 1;
        }
        divi = m*(m+1)*(m+2)*sinal;
        termo = 4.0/divi;
        m += 2;
      }

    return nila;
}
