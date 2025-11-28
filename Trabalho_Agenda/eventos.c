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
    Evento novo;
    le_evento(&novo, *ev, *n);

    *ev = realloc(*ev, sizeof(Evento) * (*n + 1));
    (*ev)[*n] = novo;
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
void pesquisa_data(Evento *ev, int n){
    int i;
    Data pesq;
    printf("Digite a Data a Ser Pescada:\n");
    le_data(&pesq);
    printf("\nEventos na data: %d/%d/%d.\n---------------------------\n", pesq.dia, pesq.mes, pesq.ano);

    for(i=0; i<n; i++)
        if((ev)[i].data.dia == pesq.dia && (ev)[i].data.mes == pesq.mes && (ev)[i].data.ano == pesq.ano){
            print_eva(ev[i]);
            printf("---------------------------\n");
        }
    
}

//Func 4
void pesquisa_desc(Evento *ev, int n){
    char pesq[50], aux[50];
    int cont= 0;

    printf("Digite a descricao que deseja pesquisar:\n");
    scanf(" %[^\n]", pesq);

    printf("\nEventos que correspondem a: \"%s\"\n", pesq);
    printf("---------------------------\n");

    for(int i = 0; i < n; i++){
        strcpy(aux, ev[i].desc);
        str_min(pesq);
        str_min(aux);
        if(strstr(aux, pesq) != NULL){
            print_eva(ev[i]);
            printf("---------------------------\n");
            cont = 1;
        }
    }

    if(!cont){
        printf("Nenhum evento encontrado com essa descricao.\n");
    }
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
                (*ev)[j] = (*ev)[j+1];  // Antes tava dando erro por causa da sintaxe: *ev[j] = *ev[j+1]; , agora tá dando certo
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

void le_evento(Evento *ev, Evento *lista, int n){
    Horario *hora;
    int i, cont, tipo;
    printf("Cadastre a Data do Evento(*/*/*): \n");
    le_data(&ev->data);
    do{
        tipo=0;
    do{
        printf("Cadastre Horario de Inicio do Evento(*:*): \n");
        le_hora(&ev->inicio);
    }while(conflito(*ev, lista, n, tipo));
    tipo=1;
    do{
    printf("Cadastre Horario de Finalização do Evento(*:*): \n");
    le_hora(&ev->fim);
    }while(conflito(*ev, lista, n, tipo));
    tipo=2;
    }while(conflito(*ev, lista, n, tipo));
    printf("Descreva o Evento: ");
    scanf(" %[^\n]", ev->desc);
    printf("Cadastre o  local do Evento: ");
    scanf(" %[^\n]", ev->local);
}

void le_data(Data *p){
    do{
    scanf("%d/%d/%d", &p->dia,&p->mes,&p->ano);
    }while(valida_data(p) != 1);
}


void le_hora(Horario *p){   
    do{
    scanf(" %d:%d", &p->hora, &p->min);
    }while(valida_hora(p) !=1);
}

int valida_data(Data *p){
    int max=0;
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(p->mes<1 || p->mes>12){
        printf("Mês Inválido!\n");
        return 0;
    }
    if(p->mes==02 && bissexto(*p))
        max = 29;
    else
        max = m[p->mes -1];
    if(p->dia<1 || p->dia>max){
        printf("Dia Inválido!\n");
        return 0;
    }

    return 1;
}
int bissexto(Data p){
    if(p.ano % 4 == 0 && (p.ano % 100 != 0 || p.ano % 400 == 0))
        return 1;
    return 0;
}

int valida_hora(Horario *p){
    if(p->hora<00 || p->hora>23){
        printf("Hora Inválida!");
        return 0;
    }
    if(p->min<00 || p->min>59){
        printf("Minuto Inválido!");
        return 0;
    }
    return 1;
}


int conflito(Evento novo, Evento *ev, int n, int tipo){
    for(int i = 0; i < n; i++){
        if(novo.data.dia == ev[i].data.dia && novo.data.mes == ev[i].data.mes && novo.data.ano == ev[i].data.ano){
            if(hora_maior_ou_igual(novo.inicio, ev[i].inicio) && hora_menor(novo.inicio, ev[i].fim) && tipo==0){
                printf("\n‼ Conflito no horário de INÍCIO com Evento %d: [%d:%d - %d:%d]\nTente Novamente\n\n", i+1, ev[i].inicio.hora,ev[i].inicio.min, ev[i].fim.hora,ev[i].fim.min);
                return 1;
            }else if(hora_maior(novo.fim, ev[i].inicio) && hora_menor(novo.fim, ev[i].fim) && tipo==1){
                printf("\n‼ Conflito no horário de Final com Evento %d: [%d:%d - %d:%d]\nTente Novamente\n\n", i+1, ev[i].inicio.hora,ev[i].inicio.min, ev[i].fim.hora,ev[i].fim.min);
                return 1;
            }else if(hora_menor(novo.inicio, ev[i].fim) && hora_maior(novo.fim,ev[i].inicio) && tipo==2){
                printf("\n‼ Conflito no horario, invadindo horário do Evento %d: [%d:%d - %d:%d]\nTente Novamente\n\n", i+1, ev[i].inicio.hora,ev[i].inicio.min, ev[i].fim.hora,ev[i].fim.min);
                return 1;
            }
        }
    }
    return 0;
}


int hora_maior_ou_igual(Horario a, Horario b){
    if(a.hora > b.hora)
        return 1;
    if(a.hora == b.hora && a.min >= b.min)
        return 1;
    return 0;
}

int hora_menor(Horario a, Horario b){
    if(a.hora < b.hora)
        return 1;
    if(a.hora == b.hora && a.min < b.min)
        return 1;
    return 0;
}

int hora_maior(Horario a, Horario b){
    if(a.hora > b.hora)
        return 1;
    if(a.hora == b.hora && a.min > b.min)
        return 1;
    return 0;
}

void str_min(char *s){
    for(int i = 0; s[i]; i++){
        s[i] = tolower(s[i]);
    }
}

