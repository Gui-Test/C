#include <stdio.h>
#include <stdlib.h>
#include "eventos.h"

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
            fprintf(f,"%d/%d/%d\n", &ev[i].data.dia,&ev[i].data.mes,&ev[i].data.ano);
            fprintf(f,"%d:%d\n", &ev[i].inicio.hora,&ev[i].inicio.min);
            fprintf(f,"%d:%d\n", &ev[i].fim.hora,&ev[i].fim.min);
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