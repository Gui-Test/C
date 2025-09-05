#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Triângulo
#define N 3

double maior(double x,double y, double z);

int main(int argc, char const *argv[]){
    double a,b,c, aux;

    printf("Digite os lados do triangulo a b c:\n");
    scanf("%lf %lf %lf", &a,&b,&c);
    
    //selection_sort: não é tão bom, mas eu tinha esquecido como fazer e não queria ter que fazer if else nisso
    double v[] = {a,b,c};
    int i = 0;
    for (i; i<N-1; i++){
        int i_maior = i, j;
        for (j = 1; j < N; j++){
            if(v[j] > v[i_maior]){
                i_maior = j;
            }
        }
        aux = v[i];
        v[i] = v[i_maior];
        v[i_maior] = aux;
    }
    a = v[0]; b = v[1]; c = v[2];
    printf("%lf %lf %lf \n", a, b, c);

    if (a >= b+c){
        printf("NAO FORMA TRIANGULO\n");
    }else if(pow(a,2.0) == pow(b,2.0) + pow(c,2.0)){
        printf("TRIANGULO RETANGULO\n");
    }else if(pow(a,2.0) > pow(b,2.0) + pow(c,2.0)){
        printf("TRIANGULO OBTUSANGULO\n");
    }else if(pow(a,2.0) < pow(b,2.0) + pow(c,2.0)){
        printf("TRIANGULO ACUTANGULO\n");
    }

    if(a==b && a==c && b==c){
        printf("TRIANGULO EQUILATERO\n");
    }else if(a==b || a==c || b==c){
        printf("TRIANGULO ISOSCELES\n");
    }
}
