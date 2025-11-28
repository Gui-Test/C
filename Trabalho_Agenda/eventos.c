#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eventos.h"

//Abrir Arquivo
void abrir_arquivo(Evento **ev, int *n){
    FILE *f = fopen("eventos.txt", "r");
    if(!f){
        printf("Arquivo não encontrado.\n");
        return;
    }

    fscanf(f, "Numero de eventos: %d", n);
    fgetc(f);
    fgetc(f);

    *ev = realloc(*ev, sizeof(Evento) * (*n));

    char linha[256];
    int i = 0;

    while (i < *n)
    {
        fgets(linha, sizeof(linha), f);
        if (strncmp(linha, "Data:", 5) == 0)//encontra o texto data
        {
            fgets(linha, sizeof(linha), f);
            sscanf(linha, "%d/%d/%d", &(*ev)[i].data.dia, &(*ev)[i].data.mes, &(*ev)[i].data.ano);

            fgets(linha, sizeof(linha), f);//pula(sentido de não ler ) inicio
            fgets(linha, sizeof(linha), f);
            sscanf(linha, "%d:%d", &(*ev)[i].inicio.hora, &(*ev)[i].inicio.min);

            fgets(linha, sizeof(linha), f);//pula fim
            fgets(linha, sizeof(linha), f);
            sscanf(linha, "%d:%d", &(*ev)[i].fim.hora, &(*ev)[i].fim.min);

            fgets(linha, sizeof(linha), f);//pula descrição
            fgets((*ev)[i].desc, sizeof((*ev)[i].desc), f);
            (*ev)[i].desc[strcspn((*ev)[i].desc, "\n")] = 0;

            fgets(linha, sizeof(linha), f);//pula local
            fgets((*ev)[i].local, sizeof((*ev)[i].local), f);
            (*ev)[i].local[strcspn((*ev)[i].local, "\n")] = 0;

            fgets(linha, sizeof(linha), f);

            i++;
        }
    }

    fclose(f);
}


//Func 1
void cadastrar(Evento **ev, int *n){
    *ev = realloc(*ev, sizeof(Evento) * (*n + 1));
    le_evento(&(*ev)[*n]);
    (*n)++;
    ordena_evento(*ev, *n);
}

//Func 2
void mostrar_eventos(Evento *ev, int n){
    int i;
    printf("---------------------------\n");
    for (i = 0; i < n; i++){
        printf("# Evento %d\n", i+1);
        print_eva(ev[i]);
        printf("---------------------------\n");
    }
}

//Func 3
void pesquisa_data(){

}

//Func 4
void pesquisa_desc(){

}

//Func 5
void remove_evento(Evento **ev, int *n){
    Data pesqd;
    Horario pesqh;
    printf("REMOVER EVENTO!\n");
    printf("Digite a data do evento a ser removido(*/*/*):\n");
    le_data(&pesqd);
    printf("Digite a hora de inicio do evento a ser removido(*:*):\n");
    le_hora(&pesqh);

    int i,j, np = *n;
    for(i=0;i<np;i++){
        if((compara_data(pesqd,((*ev)[i].data)) == 0) && (compara_hora(pesqh,((*ev)[i].inicio)) == 0)){
            for(j=i;j<np-1;j++){
                (*ev)[j] = (*ev)[j+1];  // Antes tava dando erro por causa disso: *ev[j] = *ev[j+1]; , agora tá dando certo
            }
            (*n)--;
            *ev = realloc(*ev, sizeof(Evento) * (*n));
            printf("\nEvento Removido com Sucesso!");
            break;
        }
    }
    if(np == *n){
        printf("\nEvento não encontrado..");
    }

}

//Func 6
void salvar_sair(Evento *ev, int n){
    FILE *f = fopen("eventos.txt", "w");
    if(!f){
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    fprintf(f, "Numero de eventos: %d\n\n", n);

    for(int i = 0; i < n; i++){
        fprintf(f, "Data:\n%02d/%02d/%04d\n", ev[i].data.dia, ev[i].data.mes, ev[i].data.ano);
        fprintf(f, "Inicio:\n%02d:%02d\n", ev[i].inicio.hora, ev[i].inicio.min);
        fprintf(f, "Fim:\n%02d:%02d\n", ev[i].fim.hora, ev[i].fim.min);
        fprintf(f, "Descricao:\n%s\n", ev[i].desc);
        fprintf(f, "Local:\n%s\n\n", ev[i].local);
    }

    fclose(f);
}


//Auxiliares
void print_eva(Evento ev){
    printf("Data: %02d/%02d/%04d\n", ev.data.dia, ev.data.mes, ev.data.ano);
    printf("Horario Inicio: %02d:%02d\n", ev.inicio.hora, ev.inicio.min);
    printf("Horario Fim:    %02d:%02d\n", ev.fim.hora, ev.fim.min);
    printf("Descricao: %s\n", ev.desc);
    printf("Local: %s\n", ev.local);
}

void pause(){
    printf("\n\nAperte enter para voltar ao menu\n");
    getchar();
    getchar();
}

void ordena_evento(Evento *ev, int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        int i_menor = i;
        for(j = i + 1; j < n; j++)
            if(compara_eventos(ev[j], ev[i_menor]) < 0)
                i_menor = j;

        Evento aux = ev[i];
        ev[i] = ev[i_menor];
        ev[i_menor] = aux;
    }
}

int compara_eventos(Evento ev, Evento av){
    Data a = ev.data, b = av.data;
    Horario c = ev.inicio, d = av.inicio;
    if(compara_data(a, b) != 0)
        return compara_data(a, b);
    else
        return compara_hora(c, d);
}

int compara_data(Data a, Data b){
    if(a.ano != b.ano)
        return a.ano - b.ano;
    else if(a.mes != b.mes)
        return a.mes - b.mes;
    else
        return a.dia - b.dia;
}

int compara_hora(Horario a, Horario b){
    if(a.hora != b.hora)
        return a.hora - b.hora;
    else
        return a.min - b.min;
}

void le_evento(Evento *ev){
    printf("Cadastre a Data do Evento(*/*/*): \n");
    le_data(&ev->data);
    printf("Cadastre Horario de Inicio do Evento(*:*): \n");
    le_hora(&ev->inicio);
    printf("Cadastre Horario de Finalização do Evento(*:*): \n");
    le_hora(&ev->fim);
    printf("Descreva o Evento: ");
    scanf(" %[^\n]", ev->desc);
    printf("Cadastre o  local do Evento: ");
    scanf(" %[^\n]", ev->local);
}

void le_data(Data *p){
    scanf("%d/%d/%d", &p->dia,&p->mes,&p->ano);
}

void le_hora(Horario *p){
    scanf(" %d:%d", &p->hora, &p->min);
}
