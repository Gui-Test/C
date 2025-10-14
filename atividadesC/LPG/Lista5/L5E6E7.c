#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Exc6 É número
//Exc7 String to Number
#define TAM 20

int eh_numero(char s[]);
int converte_str(char s[]);

int main(){
    char str[TAM];
    printf("Digite uma string:\n");
    scanf("%s", str);
    
    if (eh_numero(str)){
        printf("Eh Numero!\n");
        int num = converte_str(str);
        printf("O numero (%d + 1): %d", num, num+1);
    }else{
        printf("Nao eh numero!\n");
    }
}


//Funcão Exc6
int eh_numero(char s[]){
    int i;
    for (i=0; s[i] != '\0'; i++){
        if (s[i] < '0' || s[i] > '9')
            return 0;
    }
    return 1;
}
//Função Exc7
int converte_str(char s[]){
    int i;
    for (i=0; s[i] != '\0'; i++); //tamanho
    int n = i-1;
    int num = 0;
    for (n,i=0;n>=0;n--,i++){
        num += (s[i]-48) * (pow(10,n));    
    }
}

