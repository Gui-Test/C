#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc13 substring
#define TAM 20
void substring( char str[], int ini, int n, char sub[] );

int main(){
    char str[TAM],sub[TAM]="";
    int ini,n;
    printf("Digite uma String:");
    scanf("%s", str);
    printf("Digite a posicao inicial:");
    scanf("%i", &ini);
    printf("Digite quantos caracteres voce quer:");
    scanf("%i", &n);

    substring(str, ini, n, sub);
    printf("String:%s\n", str);
    printf("Substring:%s\n", sub);

}

void substring( char s[], int ini, int n, char sub[] ){
    int i,j = ini-1;
    for (i=0,j;i<n && s[j]!='\0';i++,j++){
        sub[i] = s[j];
    }
}