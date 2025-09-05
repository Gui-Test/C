#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Horas do jogo

int main(int argc, char const *argv[]){
    int starth,endh,horas = 0;

    printf("Digite as horas de inicio e termino de um jogo\n");
    scanf("%d %d", &starth,&endh);

    if (starth <= endh){
        horas = endh - starth;
    }else{
        while(starth != endh){
            starth++;
            if(starth != endh){
            horas++;
            }
            if (starth > 24){
                starth = 0;
            }
        }
    }

    printf("O JOGO DUROU %d HORA(S)\n", horas);

    
}
