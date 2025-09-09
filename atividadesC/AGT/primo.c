#include <stdio.h>

int main()
{
   int numero,i,nprimo;
   i = 2;
   nprimo = 0;

   printf("Digite um número:");
   scanf("%i", &numero);

   while (i != numero/2 && numero % i != 0){
    if (numero % i == 0){
        nprimo ++;
    };

    i++;
   };
   
   if(nprimo != 0){
    printf("Não é Primo");  
   }else {
    printf("É Primo");
   }

}

int teste_primo(int numero){
    int i,conta_divisor;
    i = numero;
    while (i>0){
        if(numero % i == 0)
         
        
    }
    


}