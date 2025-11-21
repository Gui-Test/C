#include <stdio.h>
#include "data.h"

void mostra_data(Data x){
    printf("%d/%d/%d", x.dia, x.mes, x.ano);
}

void le_data(Data *p){
    printf("Digite o dia: ");
    scanf("%d", &p->dia);
    printf("Digite o mes: ");
    scanf("%d", &p->mes);
    printf("Digite o ano: ");
    scanf("%d", &p->ano);
}