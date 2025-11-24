#include <stdio.h>
#include <stdlib.h>
#include "eventos.h"

void abrir_arquivo(Evento *ev, int *n){
    int i,k=0;
    FILE *f = fopen("eventos.txt", "rt");
    if(f == NULL){
        printf("\nO arquivo não foi criado...\n");
    }else{
        fscanf(f,"Numero de eventos:%d", &*n);

        ev = realloc(ev, sizeof(Evento)*(*n));

        for(i=0;i<*n;i++){
            fscanf(f,"%d/%d/%d", &ev[i].data.dia,&ev[i].data.mes,&ev[i].data.ano);
            fscanf(f,"%d:%d", &ev[i].inicio.hora,&ev[i].inicio.min);
            fscanf(f,"%d:%d", &ev[i].fim.hora,&ev[i].fim.min);
            fscanf(f," %[^\n]", ev[i].desc);
            fscanf(f," %[^\n]", ev[i].local);
        }
        if(*n == 0){
            printf("\n%d Registros encontrados\n", *n);
        }else{
            printf("\n%d Registros carregados com sucesso!\n", *n);
        }    
    }
    
    fclose(f);
}

void cadastrar(){

}
void mostrar_eventos(){

}

void pesquisa_data(){

}

void pesquisa_desc(){

}

void remove_evento(){

}

void salvar_sair(Evento *ev, int n){
    int i;
    FILE *f = fopen("eventos.txt", "wt" );
    
    fprintf(f,"Numero de eventos:%d\n", n);
    for(i=0;i<n;i++){
            fprintf(f,"%d/%d/%d\n", ev[i].data.dia,ev[i].data.mes,ev[i].data.ano);
            fprintf(f,"%d:%d\n", ev[i].inicio.hora,ev[i].inicio.min);
            fprintf(f,"%d:%d\n", ev[i].fim.hora,ev[i].fim.min);
            fprintf(f,"%s\n", ev[i].desc);
            fprintf(f,"%s\n", ev[i].local);
    }

    fclose(f);
    free(ev);
}

void pause(){
    printf("\n\nAperte enter para voltar ao menu\n");
    getchar();
    getchar();
}