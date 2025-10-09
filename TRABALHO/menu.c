#include "header.h"

void menu(){
    int conjuntos[M][N], cont=0, opcao=0;
    gera_matriz(conjuntos, cont);
    do {
        printf("Gerenciamento de Conjuntos\n\nMenu\n\n");
        printf("1-Criar um novo conjunto vazio.\n");
        printf("2-Inserir dados em um conjunto.\n");
        printf("3-Remover um conjunto.\n");
        printf("4-Fazer uniao entre dois conjuntos.\n");
        printf("5-Fazer a interseccao entre dois conjuntos.\n");
        printf("6-Mostrar um conjunto.\n");
        printf("7-Mostrar todos os conjuntos.\n");
        printf("8-Fazer busca por um valor.\n");
        printf("9-Sair do Programa\n\n");
        printf("Escolha uma opcao: ");
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
                cria_conj(conjuntos, &cont);
                break;
            case 2:
                insere_dados(conjuntos, cont);
                break;
            case 3:
                remover(conjuntos, &cont);
                break;
            case 4:
                uniao(conjuntos, &cont);
                break;
            case 5:
                inter(conjuntos, &cont);
                break;
            case 6:
                mostra_conj(conjuntos, cont);
                break;
            case 7:
                mostra_todos(conjuntos, cont);
                break;
            case 8:
                buscar(conjuntos, cont);
                break;
            case 9:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
            }
    } while(opcao!=9);
}