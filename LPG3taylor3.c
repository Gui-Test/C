#include <stdio.h>
#include <math.h>

//versão otimizada+ Deluxe Edition, with Dante from the Devil May Cry Series, New Funky Mode & Knuckles

//funções
double calcula_e_x(double x, int n);
double calcula_e_x_rec(double x, int n, int i, double termo);

int main() {
   double x;
   int n; 

    printf("digite o termo x e depois a quantidade de termos n\n");
    scanf("%lf%d", &x, &n);
    /*double e_x = 0;
    double termo = 1;
    for (i = 0; i <=n; i++){
        termo *= x/(i+1);   
        e_x += termo;
    }*/
    
    //função
    /*double e_x = calcula_e_x(x,n);*/

    //função recursiva
    double e_x = calcula_e_x_rec(x,n,0,1);

    printf("e elevado a %.3f = %.15lf\n", x, e_x);
}

//função pra calcular
double calcula_e_x(double x, int n){
    int i;
    double resultado = 0;
    double termo = 1;
    for (i = 0; i <=n; i++){
        termo *= x/(i+1);   
        resultado += termo;
    }
    return resultado;
}

//função recursiva
double calcula_e_x_rec(double x, int n, int i, double termo){
    if (i <= n )
        return termo + calcula_e_x_rec(x, n, i+1, termo*x/(i+1));
    else 
        return 0;
}