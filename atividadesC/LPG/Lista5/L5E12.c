#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc12 compara string
#define TAM 20
int str_compara(char s1[], char s2[]);

int main(){
    char str1[TAM],str2[TAM];
    printf("Digite uma String:\n");
    scanf("%s", str1);
    printf("Digite outra String:\n");
    scanf("%s", str2);

    int cancan = str_compara(str1,str2);
    if(cancan>0)
        printf("%s eh maior que %s\n", str1,str2);
    else if(cancan<0)
        printf("%s eh menor que %s\n", str1,str2);
    else
        printf("%s e %s tem o mesmo valor\n", str1,str2);
    
}

//função str_compara()
int str_compara(char s1[], char s2[]){
    int i,valor = 0;
    for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
        valor = (int)s1[i] - (int)s2[i];
        if(valor!=0)
            return valor;
    }
    return valor;
}