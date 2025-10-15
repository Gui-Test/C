#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc11 remove char
#define TAM 20
void remover(char s[], char c);

int main(){
    char str[TAM],cara;
    printf("Digite uma String:\n");
    scanf("%s", str);
    printf("Digite um Caracter para remover da String:\n");
    scanf(" %c", &cara);

    printf("String: %s \n", str);
    remover(str,cara);
    printf("String sem %c: %s \n", cara, str);
}

void remover(char s[], char c){
    int i,j; 
    for(i=0;s[i]!='\0';i++){
        if(s[i]==c){
            for(j=i;s[j]!='\0';j++){
                s[j]=s[j+1];
            }
            i--;
        }
    }
}