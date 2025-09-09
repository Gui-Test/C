#include <stdio.h>
#include <math.h>

int main() {
 //Contador de Primos
 int n, m, 
 x, i, 
 primos = 0;
    scanf("%i", &n);
    scanf("%i", &m);
    
    for(x = n; x <= m; x++){
        int i,eh_primo = 1; //Verdadeiro
        float r = sqrt(x);
        for(i = 2; i <= r && eh_primo; i++){
            if(x % i == 0){
                eh_primo = 0; //Falso
            }
        }
        if (eh_primo){
            primos++;
            printf("%d : %d\n", primos, x);
        }
    }

    return 0;
}
