int main (){
	
	int numero,i;
	i=2;
	
	printf("Digite um número:identificaremos os seu carater relativo aos divisores que possui");
	scanf("%i", &numero);

	while (numero % i != 0){
		if ( i != numero/2){
		i = i++;
		}
		else{
		i = numero;
		printf ("O número é primo");
		};
	}
	
	return 0;
}
