#include <stdio.h>

//Triângulo

float ordem(float x,float y, float z);

int main(int argc, char const *argv[]){
    float a,b,c, aux;

    printf("Digite os lados do triangulo a b c:\n");
    scanf("%f %f %f", &a,&b,&c);

    ordem(a,b,c);
    printf("%f %f %f", a, b, c);


}

float ordem(float x,float y, float z){
    float maior = x;
    if (y > maior){
        maior = y;
        y = x;
    }
    if (z > maior){
        maior = z;
        z = y;
    }
    x = maior;
    return x,y,z;
}