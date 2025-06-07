#include <stdio.h> 
#include <string.h> //biblioteca de string
#include <ctype.h> //biblioteca de char

int main(){
    
    int indice;
    char palavra[100] = "Hoje tem Algoritmo";
    char palavra2[100] = "Computação";
    // char* palavra3;
    printf("\nDigite uma frase:");
    scanf("%s", palavra);    // %[^\n]s para poder ler uma string com espaço
    printf("\nLeu %s ",palavra);
    printf("\nTamanho:%li", strlen(palavra));
    
    for (indice=0;indice < strlen(palavra);indice++){
        printf("\n%c %i", palavra[indice],palavra[indice]);
    }
    
    strcpy(palavra, palavra2);
    printf("\nSaida: %s !! %s", palavra, palavra2);
    
    
    return 0;
}
