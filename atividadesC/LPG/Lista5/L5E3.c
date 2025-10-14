#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc3 Concatenar
#define TAM 50

void concatena(char str1[], char str2[]);

int main(){
    char str1[TAM],str2[TAM];
    printf("Digite uma string:\n");
    scanf("%s", str1);
    printf("Digite outra string:\n");
    scanf("%s", str2);

    concatena(str1,str2);
    printf("Concatenacao: %s", str1);

    
}

void concatena(char s1[], char s2[]){
    int tam;
    int i;
    for (i=0;s1[i]!='\0';i++);
    tam = i;
    for(i=0,tam;s2[i]!='\0';i++,tam++){
        s1[tam] = s2[i];
    }
    s1[tam] = '\0';
}