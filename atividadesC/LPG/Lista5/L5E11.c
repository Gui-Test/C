#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exc11 remove char

int main(){

}

void remover(char s[], char c){
    int i,j; 
    for(i=0;s[i]!='\0';i++){
        if(s[i]==c){
            for(j=i;s[j]!='\0';j++){
                s[j]=s[j+1];
            }
            i--;
        }
    }
}