#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc10 Inverte String
#define TAM 20
void reverse(char s[]);

int main(){
    char str[TAM];
    printf("Digite uma String:\n");
    scanf("%s", str);
    printf("String: %s \n", str);
    reverse(str);
    printf("String com reverse: %s \n", str);

}

void reverse(char s[]){
    int i,j;
    char aux = ' ';
    for(i=0;s[i]!='\0';i++);
    int size=i;
    i--;
    for(j=0,i=i;j<(size/2);j++,i--){
        aux  = s[j];
        s[j] = s[i];
        s[i] = aux;
    }
}