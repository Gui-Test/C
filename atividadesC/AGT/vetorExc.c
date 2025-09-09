#include <stdio.h>
//Exc1
/*#define N 8

int main(){
    int i,n;
    int v[N]={1, 3, 4 ,5, 6, 7, 8, 9};
    
    printf("\nDigite um Número:\n");
    scanf("%i", &n);
    printf("\nSomado ao Vetor é igual a:\n");

    printf("\n{");
    for (i=0;i<N;i++){
        v[i] = v[i] + n;
        printf("%i,",v[i]);
    }
    printf("}\n");
}
*/

//Exc2
/*#define N 10

int main(){
    int i;
    int A[N]={1,3,4,5,6,7,8,9,-1,2};
    int B[N]={14,10,6,-5,-2,7,12,99,0,2},C[10];

    printf("{");
    for (i=0;i<N;i++){
        C[i] = A[i] + B[i];
        printf("%i,",C[i]);
    }
    printf("}");
}*/

//Exc3
/*#define N 8
int main(){

    int i,v[N] = {10, 3, 4 ,5, -6, 7, 8, 9}, menor, imenor;

    menor = v[0];

    for (i = 0; i < N;i++){
           
            if (v[i]< menor){
                menor = v[i];
                imenor = i;
            }
    }

    printf("\nMenor Valor: %i na posicao %i \n", menor,imenor);

    printf("[");
    for (i = 0; i < N;i++){
        printf("%i ", v[i]);
    }
    printf("]\n");

    return 0;
}*/

