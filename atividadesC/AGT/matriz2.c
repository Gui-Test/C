#include <stdio.h>
#define D 10

int main(){

 //DDD IS THE NAME YOU SHOLD KNOWN
 int d[D][D] = {{0,147,72,148,70,31,79,269,223,385},
                {147,0,91,8,77,134,68,145,177,406},
                {72,91,0,89,40,48,44,198,160,353},
                {148,8,89,0,78,133,69,139,169,398},
                {70,77,40,78,0,62,10,208,192,392},
                {31,134,48,133,62,0,71,245,192,358},
                {79,68,44,69,10,71,0,201,191,395},
                {269,145,198,139,208,245,201,0,134,364},
                {223,177,160,169,192,192,191,134,0,240},
                {385,406,353,398,392,358,395,364,240,0}};

int i,j;


    printf("\nMatriz das distancias Cidades:\n");
    for (i = 0;i < D;i++){
        printf("\n");
        for(j = 0;j < D;j++){
            printf("%i ", d[i][j]);
        }
    }

    printf("\n\nVetor da diagonal principal:\n");
    for(i = 0;i < D;i++){
            printf("%i ", d[i][i]);
    }

    printf("\n\nVetor da diagonal segundaria:\n");
    i = 0;
    for(j = 9;j >= 0;j--){ 
            printf("%i ", d[i][j]); 
        i++;
    }


printf("\n");
return 0;
}