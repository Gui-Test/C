#include <stdio.h>
#include <stdlib.h>
#include "eventos.h"

void menu(){
    int opcao;
    int n = 0;
    Evento *ev = malloc(sizeof(Evento));
    abrir_arquivo(ev,&n);
    printf("%d\n", n);

    do{
        printf("\n[--- Agenda ---]\n\n");
        printf("1 - Cadastro\n");
        printf("2 - Todos os eventos\n");
        printf("3 - Pesquisar por data\n");
        printf("4 - Pesquisar por descricao\n");
        printf("5 - Remover evento\n");
        printf("6 - Sair do Programa\n\n");
        
        printf("Por favor digite um numero entre 1 e 6:\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastrar();
                pause();
                break;
            case 2:
                mostrar_eventos();
                pause();
                break;
            case 3:
                pesquisa_data();
                pause();
                break;
            case 4:
                pesquisa_desc();
                pause();
                break;
            case 5:
                remove_evento();
                pause();
                break;
            case 6:
                printf("Saindo do programa...");
                salvar_sair(ev,n);
                break;
            default:
                printf("Opcao invalida!");
                break;
        }

    }while(opcao != 6);
}

