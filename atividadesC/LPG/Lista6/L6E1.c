#include <stdio.h>
#include <stdlib.h>
//Exc1 incremento e decremento

void inc_dec (int *a, int *b);

int main(){
    int x,y;

    printf("Digite x e y:\n");
    scanf("%d %d", &x, &y);
    printf("x = %d y = %d\n", x, y);

    inc_dec(&x,&y);

    printf("Apos inc_dec:\n");
    printf("x = %d y = %d\n", x, y);

}

void inc_dec (int *a, int *b){
    *a+=1;
    *b-=1;
}