#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estudo de strings
int main(){
    char s[] = "Ola, Za Warudo!";
    printf("s = %s\n", s);
    printf("Tamanho da string s na memoria:%d\n", sizeof(s));
    printf("A string %s tem %d caracteres\n", s, strlen(s));

    int v[100]={65,68,67,64};
    printf("Tamanho do vetor v na memoria:%d\n", sizeof(s));
    for(int i=0;i<4;i++){
        printf("%c (%d)\n", v[i],v[i]);
    }

    printf("\nPrintando os valores da string em char e ASCII:\n");
    for (int i=0;s[i] != '\0';i++){
        printf("%c (%d)\n", s[i],s[i]);
    }
    printf("\n");
}