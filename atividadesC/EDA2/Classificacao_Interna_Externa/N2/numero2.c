//Lista Slide Classificacão Exc 2
#include <stdlib.h>
#include <stdio.h>
#define TAM 7

int minindex(int v[], int n);

int main(){
    
    FILE *f;
    f = fopen("dados.txt", "r");

    
    if(f == NULL){
        printf("Não foi possível abrir o arquivo");
        return 0;
    }

    int mem[TAM]; //memória principal
    int temp = 0;
    int i = 0, j = 1;
    int **part = malloc(sizeof(int*)*1); //matriz dinâmica de partições
    part[0] = malloc(sizeof(int)*1);

    for(i = 0; i<TAM;i++){
        if(fscanf(f,"%i ", &temp) != EOF){
            mem[i] = temp;
        }
    }
    
    i = 1;
    j = 1;

    while(temp!= EOF){
        int r = minindex(mem,TAM);
        if(mem[r]>part[j]){
            j++;
            part[i] = realloc(sizeof(int)*j, part[i]);
            part[i][j] = mem[r];
        }else{
            //tenho que arranjar uma forma de congelar o número... mas como?
        }
            
    }
    

    printf("\n");

    
    fclose(f);

} 

int minindex(int v[], int n) {
  
    int min = 0;
    for (int i = 1; i < n; i++) {
      
        if (v[i] < v[min]) {
            min = i; 
        }
    }
    return min;
}




