#include <stdio.h>
#include <stdlib.h>

int main(){
    char a[10] = "ZA WARUDO";
    char b[10] = "Testeeeee";

    printf("A = '%s' e B = '%s'\n",a,b);
    strcpy(a,b);

    printf("A = '%s' e B = '%s'\n",a,b);

}

void strcpy(char dest[], char orig[]){
    int i;
    for(i = 0; orig[i] != '\0'; i++){
        dest[i] = orig[i];
    }
    dest[i] = '\0';
}