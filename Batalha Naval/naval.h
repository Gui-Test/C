#ifndef NAVAL

//para executar o jogo, rodar esse código, adicionando os arquivos novos |
//                                                                       V
//gcc JxJ.c main.c naval.h navio.c tabuleiro.c tiros.c -o batnav


#define NAVAL
#define TAM 7
//esse arquivo serve como cabeçalho para todos os outros, tudo que estiver aqui, os outros irão receber como componente.

//define estrutura para o tipo Jogador
typedef struct {
    int pontuacao;
    int vitorias;
    int derrotas;
} Jogador;

//define estrutura para o tipo Jogo
typedef struct {
    char tabuleiro[TAM][TAM];
    char tiros[TAM][TAM];
} Jogo;

//puxa as funções do "tabuleiro.c"
void iniciarTabuleiro(char tabuleiro [TAM][TAM]);
void mostraTabuleiro(char tabuleiro [TAM][TAM]);
int tabuleiroVazio(char tabuleiro [TAM][TAM]);

//puxa as funções do "JxJ.c"
void jogar(Jogador* j1, Jogador* j2);


//informações sobre os navios
int posSub(char tabuleiro[TAM][TAM]);
int posCruz(char tabuleiro[TAM][TAM]);
int posFrag(char tabuleiro[TAM][TAM]);


//tiros
void atirar(char tabuleiro[TAM][TAM],char tiros[TAM][TAM]);


#endif