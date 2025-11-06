#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 3, *p1, **p2;

    p1 = &a;
    p2 = &p1;

    printf(" %d \n %d \n %d \n",a, p1, p2);
}