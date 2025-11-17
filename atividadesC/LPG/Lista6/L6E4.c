#include <stdio.h>
#include <stdlib.h>
//Exc4 hora

void calcula_hora(int totalMinutos, int *ph, int *pm);

int main(){
    int tmin,h = 0,min = 0;

    printf("Digite quantos minutos que se pasaram no dia:\n");
    scanf("%d", &tmin);
    
    calcula_hora(tmin, &h, &min);

    printf("Agora sao:\n");
    printf("%d Horas e %d Minutos\n", h, min);

}

void calcula_hora(int totalMinutos, int *ph, int *pm){
    if(totalMinutos>=1440){
        totalMinutos -= 1440;
    }
    *ph = totalMinutos/60;
    *pm = totalMinutos - (*ph*60);
}