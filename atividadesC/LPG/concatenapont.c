#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concatena(char *str1, char *str2);

int main(){
    char s1[] = "Alguma";
    char s2[] = " Coisa";

    char *s3 = concatena(s1,s2);
    printf("%s\n", s3);
    free(s3);
}

char * concatena(char *str1, char *str2){
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    char *p = malloc(n1+n2+1);

    strcpy(p, str1);
    strcpy(p+n1, str2);
    return p;
}