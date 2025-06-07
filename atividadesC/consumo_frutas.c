#include <stdio.h>
#define CALBAN 89
#define CALMACA 55
#define CALMAMAO 108
#define CALTAN 40

void exibe_menu();
int calcula_cal(int valor,int unid);
int main(){
    char fruta;
    int unidade, total_frutas = 0,caloria = 0;

    exibe_menu();

    for(total_frutas=1;total_frutas<=3;total_frutas ++){
        printf("\nDigite a Fruta:");
        scanf(" %c", &fruta);
        printf("\nQuantas unidades:");
        scanf("%i", &unidade);
        
        switch (fruta)
        {
        case 'B':
            caloria = caloria + (CALBAN * unidade);
            break;
        case 'M':
            caloria = caloria + (CALMACA * unidade);
            break;
        case 'N':
            caloria = caloria + (CALMAMAO * unidade);
            break;
        case 'T':
            caloria = caloria + (CALTAN * unidade);
            break;
        
        default:
            printf("\nFruta Inválida");
            abort();    
        }

        printf("Calorias Consumidas: %i",caloria);
    }


return 0;

}

void exibe_menu(){
    printf("\nPrograma das frutas.");
    printf("\n\nB)Banana");
    printf("\n  Vitaminas C, B6, A; Potássio, fósforo, magnésio, zinco");
    printf("\n  89 calorias/unidade");

    printf("\n\nM)Maçã\n ");
    printf("\n  Fonte de vitaminas B1, B2, Fósforo e Ferro.");
    printf("\n  55 calorias /unidade (6,5 diametro)");
    
    printf("\n\nN)Mamão");
    printf("\n  Vitaminas A, C, cálcio, ferro, potássio, licopeno e fibras.");
    printf("\n  108 calorias /unidade");

    printf("\n\nT)Tangerina");
    printf("\n  Vitamina C, A e B6. Contém tiamina, folato, potássio, cálcio,ferro e magnésio.");
    printf("\n 40 calorias /unidade");

}

int calcula_cal(int valor,int unid){
    return unid * valor;
}