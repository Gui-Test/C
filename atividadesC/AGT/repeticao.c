//Fareheit pra Celsius 
/*#include <stdio.h>
#include <math.h>

int main()
{
  int f;
  float c;
  f = 50;
  
  while(f <= 150){
  c = 5.0/9.0 * (f-32.0); 
  printf("\n%iF = %fC", f, c);
  f = f+1;
  
  };
}*/

//Volume da Esfera
/*#include <stdio.h>
#include <math.h>

int main()
{
    float raio, volume;
    
    while(raio>0){
        printf("Digite o raio:\n");
        scanf("%f",&raio);
        volume = 4./3. * 3.14 * pow(raio,3);
        printf("Volume %f", volume);
        printf("\n");
    };
    
    return 0;
    
}
*/

//Atividade usando While e For
#include <stdio.h>
#include <math.h>
#define NP 5

int main()
{
	char sexo,olho,cabelo,m,M,V,L;
	int idade,maior_idade,macho,jovem,garotaLV,npes = 1;
	float p_macho,p_garotaLV;

	m = 'm';
	M = 'M';
	V = 'V';
	L = 'L';
	jovem = 0;
	garotaLV = 0;
	macho = 0;
	maior_idade=0;

	//for(npes=1 ; npes <= NP ; npes= npes+1 ){
	while (npes <= NP) {

		printf("\n digite seu sexo('M' ou 'F')");
		scanf(" %c",&sexo);

		printf("\n digite sua cor do Olho ('A', 'V' ou 'C')");
		scanf(" %c",&olho);

		printf("\n digite a cor de seu cabelo('L', 'P' ou 'C')");
		scanf(" %c",&cabelo);

		printf("\n digite sua idade: ");
		scanf(" %i",&idade);

		if (idade >= 18 && idade <= 35) {
			jovem ++;
			if (sexo == M || sexo == m) {
				macho ++;
			} else {
				if (olho == V && cabelo == L) {
					garotaLV ++;
				};
			};

		};

		if (idade > maior_idade) {
			maior_idade = idade;
		};

		npes ++;
	};

	p_macho = (100*macho)/jovem;
	p_garotaLV = (100*garotaLV)/jovem;

	printf("\n Maior Idade: %i",maior_idade);
	printf("\n Porcentagem de homems entre 18 e 35 anos: %f",p_macho);
	printf("\n Porcentagem de mulheres com cabelo loiro, olho verde e entre 18 e 35 anos: %f",p_garotaLV);

}
