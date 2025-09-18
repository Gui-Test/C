#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Triângulo Função

double triangulo(double a,double b,double c);

int main(int argc, char const *argv[]){
    double x,y,z;
    printf("Digite os valores x,y e z do triangulo\n");
    scanf("%lf %lf %lf", &x,&y,&z);

    triangulo(x,y,z);


}

double triangulo(double a,double b,double c){
    if (a > b + c || b > a + c || c > a + b){
        printf("Nao forma triangulo\n");
    }else
    
    if(a==b && a==c && b==c){
        printf("TRIANGULO EQUILATERO\n");
    }else if(a==b || a==c || b==c){
        printf("TRIANGULO ISOSCELES\n");
    }else
        printf("TRIANGULO ESCALENO\n");
}
