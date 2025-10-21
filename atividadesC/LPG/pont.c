#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(float a,float b,float c,float *x1,float *x2);
int main(){
    float a,b,c,x1,x2;

    scanf("%f %f %f", &a,&b,&c);

    if(raizes(a,b,c,&x1,&x2)){
        printf("Raizes: x1=%f x2:%f", x1,x2);
    }else{
        printf("Nao tem raiz real");
    }
    
}

int raizes(float a,float b,float c,float *x1,float *x2){
    float delta = b*b - (4*a*c);
    if(delta < 0){
        return 0;
    }

    *x1 = (-b + sqrt(delta))/(2*a); 
    *x2 = (-b - sqrt(delta))/(2*a); 
    return 1;
}

/*
Im hanging on,
On the other side
I wont give up
Until the end of Meeeee

Oooohh oooohhh
Youre crosing the line 
Oooohh oooohhh

You can trow me 
Into the Wooollfs,
Because Im UNDEFEATABLE
*/