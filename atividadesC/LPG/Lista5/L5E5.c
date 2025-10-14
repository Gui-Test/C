#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc5 Minúscula para maiúscula
#define TAM 20
void min_mai(char s[]);

int main(){
    char str[TAM];
    printf("Digite uma String:\n");
    scanf("%s", str);
    min_mai(str);
    printf("\nString Maiuscula:%s", str);
}

void min_mai(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++)
        if(s[i]>=97 && s[i]<=122)
            s[i] = s[i] - 32;
}