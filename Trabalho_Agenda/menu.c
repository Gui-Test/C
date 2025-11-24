#include <stdio.h>
#include <stdlib.h>
#include "eventos.h"

void menu(){
    int i,opcao;
    int n = 0;
    Evento *ev;
    FILE *f = fopen("eventos.txt", "rt" );
    if(f == NULL){
        printf("\nO arquivo não foi criado...\n");
    }else{
        fscanf(f,"Numero de eventos:%d", &n);

        for(i=0;i<n;i++){
            fscanf(f,"%d/%d/%d", &ev[i].data.dia,&ev[i].data.mes,&ev[i].data.ano);
            fscanf(f,"%d:%d", &ev[i].inicio.hora,&ev[i].inicio.min);
            fscanf(f,"%d:%d", &ev[i].fim.hora,&ev[i].fim.min);
            fscanf(f," %[^\n]", ev[i].desc);
            fscanf(f," %[^\n]", ev[i].local);
        }
        if(n == 0){
            printf("\n%d Registros encontrados\n", n);
        }else{
            printf("\n%d Registros carregados com sucesso!\n", n);
        }    
    }
    
    fclose(f);

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

