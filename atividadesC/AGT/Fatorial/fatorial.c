#include <stdio.h> //biblioteca do C
#include "agt.h" //biblioteca local

int main() {
    
	int f, valor;
	printf("\n Digite um valor :");
	scanf( "%i", &valor);

	f = fatorial(valor);
	
	printf("%i! = %i", valor, f);

	return 0;
}

/*
//funcão fatorial
int fatorial(int valor){
    int i,fat=1; 
    for( i= 1 ; i <= valor ; i++){
		fat = fat * i ;
}
return fat;
}
*/