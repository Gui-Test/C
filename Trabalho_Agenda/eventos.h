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
void pause();

void abrir_arquivo(Evento *ev, int *n);

void cadastrar();
void mostrar_eventos();
void pesquisa_data();
void pesquisa_desc();
void remove_evento();

void salvar_sair(Evento *ev, int n);


#endif