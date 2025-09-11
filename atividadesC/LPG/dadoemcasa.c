#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int dN_dados=0,n_rolls,modificador,total;

    scanf("%dd%d", &n_rolls, &dN_dados);

    scanf("%d", &modificador);

    printf("\n");

    srand(time(0));
    for(int i = 0; i < n_rolls;i++){
        int rolagens = rand() % dN_dados + 1 + modificador; 
        total += rolagens;
        printf("d%d: %d\n", dN_dados,rolagens);
    }   
    printf("\n%dd%d: %d\n", n_rolls,dN_dados, total);
}
