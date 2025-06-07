#include <stdio.h>
#include <math.h>

int main(){

  float x1, y1, x2, y2, d ;    
    
    printf("Digite o x,y do ponto P:"); //escreva
    scanf("%f",&x1);                   //leia
    scanf("%f",&y1);
    printf("Digite o x,y do ponto Q:"); 
    scanf("%f",&x2); 
    scanf("%f",&y2);
   
    
    d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    printf("Calculou:%f ", d);
    return 0;
}
