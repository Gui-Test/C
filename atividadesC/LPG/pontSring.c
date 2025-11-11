#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * aloca_string(char *msg);
void mostra_vetor_strings(char **v, int n);
void free_vetor(char **v,int n);
void insere_string(char ***pv,int *pn, char *s);
void insere_indice(char ***pv,int *pn, char *s, int ind);

int main(int argc, char const *argv[])
{
    int n = 0;
    char **vetor= NULL;

    char *str = aloca_string("Digite um texto(ou 'sair' para sair): ");

    while(strcmp(str,"sair") != 0){
        insere_string(&vetor,&n,str);
        str = aloca_string("Digite um texto(ou 'sair' para sair): ");
    }

    mostra_vetor_strings(vetor,n);

    str = aloca_string("Digite um novo texto: ");
    int id;
    do{
        printf("digite o indice onde o texto deve ser inserido(0-%d): ", n);
        scanf("%d", &id);
    }while(id < 0 || id > n);

    insere_indice(&vetor,&n,str, id);
    mostra_vetor_strings(vetor,n);

    free_vetor(vetor,n);
    free(str);
    
}

char * aloca_string(char *msg){
    char buffer[1001];
    printf("%s", msg);
    scanf(" %[^\n]", buffer);
    char *p = malloc( sizeof(char) * (strlen(buffer) + 1));
    strcpy(p, buffer);
    return p;
}

void insere_string(char ***pv,int *pn, char *s){
    (*pn)++;
    *pv = realloc( *pv, sizeof(char*)* *pn);
    (*pv)[*pn-1] = s;
}

void insere_indice(char ***pv,int *pn, char *s, int ind){
    (*pn)++;
    *pv = realloc( *pv, sizeof(char*)* *pn);
    int i;
    for(i = *pn-1; i > ind; i--)
        (*pv)[i] = (*pv)[i-1];
    (*pv)[ind] = s;
}

void mostra_vetor_strings(char **v, int n){
    int i;
    printf("Lista de strings:\n");
    for(i = 0; i < n; i++){
        printf("[%d] : '%s'\n", i, v[i]);
    }
}

void free_vetor(char **v,int n){
    //libera memória
    for(int i=0;i<n;i++)
        free(v[i]);
    free(v);
}