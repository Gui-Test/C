#include <stdio.h>
#include <stdlib.h>

int main(){
    float *p, x;
    p = malloc(sizeof(float));
    scanf("%f", p);
    printf("%f\n", *p);
    x = *p;
    printf("end. de x:%d\n", &x);
    printf("end. alocado:%d\n", p);
    free(p);
}
