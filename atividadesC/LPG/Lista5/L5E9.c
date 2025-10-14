#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc9 Remove Espaços
#define TAM 30
void trim(char s[]);

int main(){
    char str[TAM] = " Teste   ";
    printf("String: %s \n", str);
    trim(str);
    printf("String com triming: %s\n", str);
}

/*//Versão do Rui
void trim(char s[]){
    int i,n;
    //Frente
    for(n=0;s[n]==' ';n++);
    for(i=n;s[i]!='\0';i++){
        s[i-n] = s[i];
    }
    s[i-n] = '\0';
    //Trás
    for(i=i-n;s[i-1]==' '&& i!=0;i--);
    s[i] = '\0';
    //Print teste
    printf("%i\n", i);
    for(i=0;s[i]!='\0';i++)
        printf(" %c\n", s[i]);
}*/

//Minha versão
void trim(char s[]){
    int i,j;
    //Frente
    for(i=0;s[i]==' ';i++);
    for(i=i,j=0;s[i]!='\0';i++,j++){
        s[j] = s[i];
    }
    s[j] = '\0';
    //Trás
    for(i=j;s[i-1]==' '&& i!=0;i--);
    s[i] = '\0';
    //Print teste
    for(i=0;s[i]!='\0';i++)
        printf(" %c\n", s[i]);
}
