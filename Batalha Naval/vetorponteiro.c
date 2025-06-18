#include<stdio.h> /* diretiva */

void imprime(int *dado); /* indica uso de função */

int main() /* função principal */

{
int valor [3];
char parada;
printf("\033c") ;//limpar console
valor[0] = 1;
valor[1] = 2;
valor[2] = 3;
imprime (valor);
printf ("dado [0] = %d\n", valor[0]);
scanf(" %c", &parada);
}

void imprime (int *dado)/* função secundaria */

{
*dado=300; 
printf ("dado [0] = %d\n", *dado);
printf ("dado [1] = %d\n", *(dado + 1));
printf ("dado [2] = %d\n", *(dado + 2));
}