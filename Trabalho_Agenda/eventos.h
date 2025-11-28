#ifndef EVENTS_H
#define EVENTS_H

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int hora;
    int min;
}
Horario;

typedef struct{
    Data data;
    Horario inicio;
    Horario fim;
    char desc[50];
    char local[50];
}Evento;


void menu();

void abrir_arquivo(Evento **ev, int *n);

void cadastrar(Evento **ev, int *n);
void mostrar_eventos(Evento *ev, int n);
void pesquisa_data(Evento *ev, int n);
void pesquisa_desc(Evento *ev, int n);
void remove_evento(Evento **ev, int *n);
void salvar_sair(Evento *ev, int n);

void ordena_evento(Evento *ev,int n);
int compara_eventos(Evento ev, Evento av);
int compara_data(Data a, Data b);
int compara_hora(Horario a, Horario b);
void le_evento(Evento *ev, Evento *lista, int n);
void le_data(Data *p);
void le_hora(Horario *p);
void print_eva(Evento ev);
void pause();
int valida_data(Data *p);
int valida_hora(Horario *p);
int bissexto(Data p);
int conflito(Evento novo, Evento *ev, int n, int tipo);
int hora_maior_ou_igual(Horario a, Horario b);
int hora_menor(Horario a, Horario b);
int hora_maior(Horario a, Horario b);
void str_min(char *s);

#endif