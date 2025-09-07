#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Séries de Pi

double gregory(double grego,double m,int k);

int main(int argc, char const *argv[])
{
    int k;
    double grego = 0;

    printf("Digite o numero de termos das series de pi\n");
    scanf("%d", &k);

    printf("Serie de Gregory: %lf", gregory(grego,0,k));

    return 0;
}

double gregory(double grego,double m,int k){
    if (k <= 1){
        return 4.0;
    }
    m = (2*(k)) - 1;
    
    if (k % 2 == 0){
        grego = (-1)*(4.0/m); 
    }else{
        grego = 4.0/m;
    }

    return grego + gregory(grego, m, k-1);
}
