#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc8 Dia Mês Ano
#define TAM 10
int eh_data(char s[]);
int data_int(char s[],int dado);

int main(){
    char data[TAM];
    int dia,mes,ano;
    
    printf("Digite uma data no formato 'DD/MM/AAAA':\n");
    scanf("%s", data);
    if(eh_data(data)){
        printf("\nEh uma data.\n");
        dia = data_int(data,1);
        mes = data_int(data,2);
        ano = data_int(data,3);
        printf("Dia:%i.\n",dia);
        printf("Mes:%i.\n",mes);
        printf("Ano:%i.\n",ano);
    }else
        printf("\nNao eh uma data.\n");

}

int eh_data(char s[]){
    int i;
    if(s[2]!='/'||s[5]!='/')
        return 0;

    for (i=0; s[i] != '\0'; i++){
        if(i == 2 || i == 5)
        i++;
        if (s[i] < '0' || s[i] > '9')
            return 0;
    }
    return 1;
}

int data_int(char s[],int dado){
    int i,j,pow = 1,valor = 0;
    if(dado == 1)
        for(i=0;s[i]!='/';i++);
    if(dado == 2)
        for(i=3;s[i]!='/';i++);
    if(dado == 3)
        for(i=5;s[i]!='\0';i++);

    for(j=i-1;j>=0 && s[j]!='/';j--){
        valor += (s[j]-'0')*pow;
        pow *=10;
    }
    return valor;
}



