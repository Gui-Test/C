#include <stdio.h>
#include <stdlib.h>


int main(){
    int v[5];
    int *p = v;
    
    int i;
    //vetores são ponteiros
    for(i=0;i<5;i++){
        scanf("%d", &p[i]);
    }
    printf("\n");
    for(i=0;i<5;i++){
        printf("V[%d]",i);
        printf("(%d)", &v[i]);
        printf("%d\n", v[i]);
    }
    printf("\n");
    //Printando com ponteiro
    int *j;
    for(j=v;j<v+5;j++){
        printf("V[%d]", j - v);
        printf("(%d)", j);
        printf("%d\n", *(v+j));
    }

    //endereco de memoria
    printf("\n %d", v);
    printf("\n %d", v + 1);

    

}
