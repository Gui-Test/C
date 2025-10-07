#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

void copia_str( char dest[], char orig[] );

void ordena_vetor(char vet[][MAX], int n);
void mostra_strings(char vet[][MAX], int n);

int main(int argc, char *argv[]) {
	char nomes[5][MAX] = { "Maria", "Joao", "Andre", "Pedro", "Mateus" };
	mostra_strings( nomes, 5 );
	ordena_vetor( nomes, 5 );
	mostra_strings( nomes, 5 );	
	
	/*
	char a[] = "Teste 123 absbxmcmsdhd asd";
	char b[100] = "Alo";
	
	printf("A='%s' e B='%s'\n", a, b);
	
	copia_str( b, a );
	
	printf("A='%s' e B='%s'\n", a, b);
	*/
	
	return 0;
}

void copia_str( char dest[], char orig[] ){
	int i;
	for(i=0; orig[i] != '\0' ; i++)
		dest[i] = orig[i];
	
	dest[i] = '\0';
}

void ordena_vetor(char vet[][MAX], int n){
	int i, j;
	for(i = 0; i < n-1; i++){
		int i_menor = i;
		for(j = i+1; j < n; j++)
			if( strcmp( vet[j] , vet[i_menor] ) < 0 )
				i_menor = j;
	
		char aux[MAX];
		strcpy( aux , vet[i] );
		strcpy( vet[i] , vet[i_menor] );
		strcpy( vet[i_menor] , aux );
	}
}

void mostra_strings(char vet[][MAX], int n){
	int i;
	for( i = 0 ; i< n ; i++ )
		printf("(%d): '%s'\n", i, vet[i] );
	
	printf("\n");
}



