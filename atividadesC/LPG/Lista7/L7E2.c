#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc2 repete string

char *repetidor( char *s, int n );

int main(int argc, char const *argv[]){
    char str[20];
    int n;
    
    printf("Digite uma string:\n");
    scanf("%[^\n]", str);

    printf("Quantas vezes quer repetir?\n");
    scanf("%d", &n);

    char *rep = repetidor(str, n);

    printf("String repetida: '%s'\n", rep);

    free(rep);
    
}

char *repetidor( char *s, int n ){
    int leng = (strlen(s));
    char *str= malloc((leng*n)+1);
    int i;
    for(i=0;i<n;i++){
       strcpy(str+leng*i,s);
    }
    return str;
}
