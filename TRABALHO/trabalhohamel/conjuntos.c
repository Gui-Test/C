#include "header.h"
//gerador
void gera_matriz(int conjuntos[M][N], int cont){
    int i, j;
    for(i=0; i<M;i++){
        for(j=0; j<N; j++){
            conjuntos[i][j]=0;
        }
    }
}

//opcao 1
void cria_conj(int conjuntos[M][N], int *cont){
    if(*cont<M){
        (*cont)++;
        printf("Conjunto %i criado\n", (*cont-1));
    }else
        printf("ERRO: Limite da matriz foi alcançado!.\n");
    
    printf("\n");
}

//opcao 2
void insere_dados(int conjuntos[M][N], int cont){
    int i, j, valor, conj, conta, disp;
    printf("\nConjuntos disponíveis:\n");
    for(i=0; i<cont;i++)
        printf("Conj.: %i ;\n", i);
    printf("\n");

    printf("Digite o conjunto quer inserir valores: ");
    scanf("%i", &conj);
    if(0<=conj&&conj<cont){
        for(i=0, conta =0, valor=1;  i<N && valor!=0; i++){
            if(conjuntos[conj][i]==0){
                printf("Valor %i: ", i);
                scanf("%i", &valor);
                for(j=0; j<N; j++)
                    if(conjuntos[conj][j]==valor && conjuntos[conj][j]!=0){
                        conta=1;
                        i--;
                        j=N;
                    }else
                        conta=0;
                if(conta)
                    printf("ERRO: Valor já registrado neste conjunto!\n");
                else
                    conjuntos[conj][i]=valor;
            }
        }

        if(conjuntos[conj][N-1]!=0)
                printf("\nLimite Máximo do conjunto atingido.\n");
    }else if(conj>=cont)
        printf("ERRO: conjunto %i não foi criado!\n", conj);
    else 
        printf("ERRO: nao existem conjuntos negativos!\n");

    printf("\n");
}

//opcao 3

void remover(int conjuntos [M][N], int *cont){
    int i, j, conj;
    printf("Escolha qual conjunto remover: ");
    scanf("%i", &conj);
    if(0<=conj && conj<*cont){
        
        for(i=conj; i<M; i++)
            for(j=0; j<N; j++){
                if(i!=M-1){
                    conjuntos[i][j]=conjuntos[i+1][j];
                }else{
                    conjuntos[i][j]=0;
                }
            }

        (*cont)--;
    }else if(conj>=*cont)
        printf("ERRO: conjunto %i não foi criado!.\n", conj);
    else
        printf("ERRO: nao existem conjuntos negativos!\n");
    printf("\n");
}

//opcao 4
    //Modificado depois do if(conj1<*cont && conj2<*cont){
 /*for(i=0;conjuntos[conj1][i]!=0 && i<N;i++)
                aux[i] = conjuntos[conj1][i];
            for(j=0;conjuntos[conj2][j]!=0 && j<N;j++){
                aux[j+i+1] = conjuntos[conj2][j];
            }
            auxiliar(aux); //remove iguais
            for(k=0;aux[k]!=0 && k<N*2;k++); //contando quantidade de elementos 
            
            if (k<=N){
                (*cont)++;
                for(i=0;i<N;i++)
                    conjuntos[*cont-1][i] = aux[i];
            }else{
                printf("ERRO: A uniao entre os conjuntos %i e %i excede espaco do conjunto. Nao gera resultante.\n", conj1, conj2);
            }*/

void uniao(int conjuntos[M][N], int *cont){
    int conj1, conj2, i, j, k, aux[N*2]={0};
    if(*cont<M){
        printf("Escolha o 1° conjunto da uniao: ");
        scanf("%i", &conj1);
        printf("Escolha o 2° conjunto da uniao: ");
        scanf("%i", &conj2);
        if(conj1<*cont && conj2<*cont){
            for(i=0;conjuntos[conj1][i]!=0 && i<N;i++);
            for(j=0;conjuntos[conj2][j]!=0 && j<N;j++); //contando elementos
            if(i+j<=N){
                (*cont)++;
                i=0;
                for(i=0;conjuntos[conj1][i]!=0 && i<N;i++){
                    conjuntos[*cont-1][i] = conjuntos[conj1][i];
                }
                for(j=0;conjuntos[conj2][j]!=0 && j<N;j++){
                    if(busca(conjuntos,conj1,conjuntos[conj2][j])==0)
                        conjuntos[*cont-1][j+i] = conjuntos[conj2][j];
                }
            }else{
               printf("ERRO: A uniao entre os conjuntos %i e %i excede espaco do conjunto. Nao gera resultante.\n", conj1, conj2); 
            }   
        }else if(conj1>=*cont && conj2>=*cont && conj1!=conj2)
            printf("ERRO: O conjunto %i e o conjunto %i nao foram criados ainda!\n", conj1, conj2);
        else if(conj2==conj1||conj1>=*cont)
            printf("ERRO: O conjunto %i nao foi criado ainda!\n", conj1);
        else 
            printf("ERRO: O conjunto %i nao foi criado ainda!\n", conj2);

    }else
        printf("ERRO: Limite da matriz foi alcancado!\n");

    printf("\n");
}

//opcao 5
void inter(int conjuntos[M][N], int *cont){
    int conj1, conj2, i, j, k;
    if(*cont<M){
        printf("Escolha o 1° conjunto da intersecao: ");
        scanf("%i", &conj1);
        printf("Escolha o 2° conjunto da intersecao: ");
        scanf("%i", &conj2);
        if(conj1<*cont && conj2<*cont){
            for(i=0; i<N; i++)
                for(j=0; j<N; j++)
                    if(conjuntos[conj1][i]==conjuntos[conj2][j] && (conjuntos[conj1][i]!=0||conjuntos[conj2][j]!=0))
                        for(k=0; k<N; k++)
                            if(conjuntos[*cont][k]==0){
                                conjuntos[*cont][k]=conjuntos[conj1][i];
                                k=N;
                            }
            (*cont)++;
        }else if(conj1>=*cont && conj2>=*cont && conj1!=conj2)
            printf("ERRO: O conjunto %i e o conjunto %i nao foram criados ainda!\n", conj1, conj2);
        else if(conj2==conj1||conj1>=*cont)
            printf("ERRO: O conjunto %i nao foi criado ainda!\n", conj1);
        else 
            printf("ERRO: O conjunto %i nao foi criado ainda!\n", conj2);
        
    }else
        printf("ERRO: Limite da matriz foi alcancado!\n");
    printf("\n");
}

//opcao 6
void mostra_conj(int conjuntos[M][N], int cont){
    int conj, i;
    printf("Digite o conjunto que quer acessar: ");
    scanf("%i", &conj);
    if(0<=conj && conj<cont){
        printf("Conjunto %i: ", conj);
        if(conjuntos[conj][0]==0)
            printf("Vazio");
        else{
            for(i=0;i<N; i++){
                if(conjuntos[conj][i]!=0)
                    printf("%i ", conjuntos[conj][i]);
            }
        }
        printf("\n");
    }else if(conj>=cont)
        printf("ERRO: conjunto %i não foi criado!.\n", conj);
    else 
        printf("ERRO: nao existem conjuntos negativos!");
    
    printf("\n");
}

//opcao 7
void mostra_todos(int conjuntos[M][N], int cont){
    int i, j;
    if(cont==0)
        printf("Não existem conjuntos!");
    else if(cont==1){
        printf("Temos 1 conjunto: \nConjunto 0: ");
        if(conjuntos[0][0]==0)
            printf("Vazio");
        else
            for(j=0; j<N; j++)
                if(conjuntos[0][j]!=0)
                    printf("%i ", conjuntos[0][j]);
        printf("\n");
    }else{
        printf("Temos %i conjuntos: \n", cont);
        for(i=0; i<cont; i++){
            printf("Conjunto %i: ", i);
            if(conjuntos[i][0]==0)
                printf("Vazio");
            else{
                for(j=0; j<N ; j++){
                    if(conjuntos[i][j]!=0)
                        printf("%i ", conjuntos[i][j]);
                }
            }
            printf("\n");
        }
    }

    printf("\n");
}

//opcao 8
void buscar(int conjuntos[M][N], int cont){
    int valor, i, j, count=0;
    if(cont>0){
        printf("Digite o valor a ser buscado: ");
        scanf("%i", &valor);
        if(valor!=0){
            printf("Conjuntos que contem o valor %i:\n", valor);
            for(i=0; i<cont; i++)
                for(j=0; j<N; j++){
                    if(conjuntos[i][j]==valor){
                        printf("Conjunto %i\n", i);
                        j=N;
                        count = 1;
                    }
                }
            
            if(count==0)
                printf("Nenhum.\n\n");
            }else
                printf("ERRO: 0 nao eh um valor valido nestes conjuntos!\n");
    }else
        printf("Nao existem conjuntos.\n");
    
    printf("\n");
}

/*
//aux remove iguais de um vetor, mudei pra usar na aux da união
void auxiliar(int vet[N*2]){
    int i, j, k;
    for(i=0; i<N*2 ; i++)
        for(j=0; j<N*2 ; j++)
            if(i!=j){
                if(vet[i]==vet[j]){
                    for(k=j; k<N*2; k++){
                        if(k!=(N*2)-1)
                            vet[k]=vet[k+1];
                        else
                            vet[(N*2)-1]=0;
                    }
                }
            }


}*/

int busca(int conjuntos[M][N], int conj, int n){
    int i;
    for(i=0;i<N;i++){
        if(conjuntos[conj][i]==n)
            return 1;
    }
    return 0;
}



void pausa(){
    printf("\nAperte Enter para Voltar ao Menu...\n");
    getchar();
    getchar();
}
