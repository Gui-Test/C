#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contem(char s[],char c);
int contem_quantos(char s[],char c);

int main(){
    char str[20];
    char car;
    printf("Digite uma string:\n");
    scanf("%s", str);
    printf("Digite um caracter:\n");
    scanf(" %c", &car);

    if(contem(str,car)){
        printf("Contem %c!\n",car);
    }
    else{
        printf("Nao Contem %c\n", car);
    }
    printf("Ocorrencias de (%c): %d\n", car, contem_quantos(str,car));

}


//Funcão Exc1
int contem(char s[],char c){
    int i;
    for (i=0; s[i] != '\0'; i++){
        if (s[i] == c)
            return 1;
    }
    return 0;
}

//Funcão Exc2
int contem_quantos(char s[],char c){
    int i;
    int quantos = 0;
    for (i=0; s[i] != '\0'; i++){
        if (s[i] == c)
            quantos++;
    }
    return quantos;
}