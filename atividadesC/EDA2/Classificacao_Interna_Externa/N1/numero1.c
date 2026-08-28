//Lista Slide Classificacão Exc 1
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void insertion_sort(int *v, int m);

int main(){
    int *v;
    int m = 0, i;
    int result = 0;
    srand(time(0));
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &m);
    v = malloc(sizeof(int) * m);
    for(i=0;i<m;i++){
        v[i] = rand() % 100 + 1;
    }

    for(i=0;i<m;i++){
        printf("v[%i]: %i\n", i, v[i]);
    }

    printf("\n");

    insertion_sort(v,m);
    
    for(i=0;i<m;i++){
        printf("v[%i]: %i\n", i, v[i]);
    }

    FILE *f;
    f = fopen("dados.txt", "w");

    for(i=0;i<m;i++){
        fprintf(f, "%d ", v[i]);
    }

    fclose(f);

}

void insertion_sort(int *v, int m){ 
    for(int i = 0; i < m ;i++){
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = chave; 
    }

}
