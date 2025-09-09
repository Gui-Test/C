#include <stdio.h>
#include <locale.h>
#define L 10

int main(/*int argc, char *argv[]*/){

    //Código

    setlocale(LC_ALL,"pt_PT.UTF-8");
    
    //unsigned exclui os números negativos
    unsigned int positivo;
    //é meio esquisito mas da pra fazer
    unsigned char c;

    char teste[L];
    scanf("%s", &teste); 
    printf("\n teu %s e gordo", teste);

    scanf("%i", &positivo);

    return 0;
}