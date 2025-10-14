#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc4 Palindromo
#define TAM 50

int palindromo(char s[]);

int main(){
    char str[TAM];
    printf("Digite uma string:\n");
    scanf("%s", str);
    if (palindromo(str)){
        printf("%s eh um palindromo", str);
    }else{
        printf("%s nao eh um palindromo", str); ;
    }
}

int palindromo(char s[]){
    int i,j, eh = 1;
    
    for(i=0; s[i]!='\0';i++);
    for(j=0; s[j]!='\0';i--,j++){
        if(s[i]==!s[j]){
            eh = 0;
        }
    }
    return eh;
}