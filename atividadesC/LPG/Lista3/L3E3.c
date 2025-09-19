#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//É digito ou não

int ehdigito(int dig);
int charpraint(char c);

int main(int argc, char const *argv[]){
    char cara;
    printf("Digite um caracter\n");
    scanf("%c", &cara);

    int digdug = charpraint(cara);

    if(ehdigito(digdug))
        printf("E digito : %d\n", digdug);
    else
        printf("Nao e digito\n", digdug);

}

int charpraint(char c){
    int dig = c - '0';  // '0' é equivalente ao inteiro 48 na tabela ASCII, e os próximos digitos 1..9 vem logo depois (49..58)
    //muito mais fácil que fazer um switch case.
}

int ehdigito(int dig){
    if (dig >= 0 && dig <= 9)
        return 1;
    else 
        return 0;
}