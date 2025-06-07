#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define TAM 7
#define NAVIOS 3

typedef struct {
    int pontuacao;
    int vitorias;
    int derrotas;
} Jogador;

typedef struct {
    char tabuleiro[TAM][TAM];
    char tiros[TAM][TAM];
} Jogo;

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    //define a linha a ser trabalhada
    for (int i = 0; i < TAM; i++) {
        //define a coluna a ser trabalhada
        for (int j = 0; j < TAM; j++) {
            //adiciona na posição da linha "i" e na posição da coluna "j" o valor 'o'.
            tabuleiro[i][j] = 'o';
        }
    }
}

//função de exibição do tabuleiro.
void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    //escreve na tela os numeros das colunas
    printf("  1 2 3 4 5 6 7\n");
    //inicia um for, para que rode em cada linha
    for (int i = 0; i < TAM; i++) {
        //na linha do for vai por uma letra, partindo do A, somando a posição para outras linhas.
        printf("%c ", 'A' + i);
        //inicia um for para as colunas dentro da inha sendo trabalhada
        for (int j = 0; j < TAM; j++) {
            //printa o valor REAL do tabuleiro, definido com a base em "inicializar tabuleiro" e sendo modificado com as outras funções dentro do progra
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


//não iremos trabalhar com essa parte, mexer com a parte que o cicero mandou no grupo
void posicionarNavios(char tabuleiro[TAM][TAM]) {
    
    int navios = 0;
    while (navios < NAVIOS) {
        int linha = rand() % TAM;
        int coluna = rand() % TAM;
        if (tabuleiro[linha][coluna] == 'o') {
            tabuleiro[linha][coluna] = 'N';
            navios++;
        }
    }
}


//ainda vou investigar esta sessão.
int atacar(Jogo* oponente, int linha, int coluna) {
    if (oponente->tabuleiro[linha][coluna] == 'N') {
        oponente->tabuleiro[linha][coluna] = '0';
        oponente->tiros[linha][coluna] = '0';
        return 1; // acerto
    } else if (oponente->tiros[linha][coluna] == 'o') {
        oponente->tiros[linha][coluna] = 'x';
        return 0; // erro
    }
    return -1; // já atirado
}


//função para verificação se todos os návios estão afundados
int todosNaviosAfundados(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            //verifica nas linhas selecionadas a cima se ainda há algum N no mapa.
            if (tabuleiro[i][j] == 'N') {
                //se tiver, retorna 0, continue o jogo
                return 0;
            }
        }
    }
    //se não tiver, retorna 1, finaliza o jogo
    return 1;
}

//tenho que estudar esta parte ainda.
void lerCoordenada(int* linha, int* coluna) {
    char entrada[4];
    printf("Digite a coordenada (ex: A1): ");
    scanf("%s", entrada);

    *linha = toupper(entrada[0]) - 'A';
    *coluna = atoi(&entrada[1]) - 1;
}


//não iremos mais realizar o serviço com jogo contra computador, muito estressante.
void jogarContraBot(Jogador* usuario, Jogador* bot) {
    Jogo player, cpu;
    inicializarTabuleiro(player.tabuleiro);
    inicializarTabuleiro(player.tiros);
    inicializarTabuleiro(cpu.tabuleiro);
    inicializarTabuleiro(cpu.tiros);

    posicionarNavios(cpu.tabuleiro);
    posicionarNavios(player.tabuleiro);

    int turno = 0;

    while (1) {
        printf("\nSeu Mapa de Ataques:\n");
        exibirTabuleiro(player.tiros);
        printf("Seu Mapa de Defesa:\n");
        exibirTabuleiro(player.tabuleiro);

        int linha, coluna;

        if (turno % 2 == 0) {
            printf("\nSua vez de atirar!\n");
            lerCoordenada(&linha, &coluna);
            int resultado = atacar(&cpu, linha, coluna);
            if (resultado == 1) {
                printf("Acertou um navio!\n");
                usuario->pontuacao++;
            } else if (resultado == 0) {
                printf("Errou!\n");
            } else {
                printf("Você já atirou aqui.\n");
                continue;
            }
        } else {
            printf("\nVez do bot...\n");
            linha = rand() % TAM;
            coluna = rand() % TAM;
            int resultado = atacar(&player, linha, coluna);
            if (resultado == 1) {
                printf("O bot acertou seu navio na posição %c%d!\n", 'A' + linha, coluna + 1);
                bot->pontuacao++;
            } else if (resultado == 0) {
                printf("O bot errou na posição %c%d.\n", 'A' + linha, coluna + 1);
            } else {
                continue;
            }
        }

        if (todosNaviosAfundados(cpu.tabuleiro)) {
            printf("\nVocê venceu!\n");
            usuario->vitorias++;
            bot->derrotas++;
            break;
        }

        if (todosNaviosAfundados(player.tabuleiro)) {
            printf("\nO bot venceu!\n");
            bot->vitorias++;
            usuario->derrotas++;
            break;
        }

        turno++;
    }

    printf("\nPontuação do Usuário: %d\nVitórias: %d\nDerrotas: %d\n", usuario->pontuacao, usuario->vitorias, usuario->derrotas);
}


//iremos utilizar a versão do código cicero
void jogarLocal(Jogador* j1, Jogador* j2) {
    Jogo p1, p2;
    inicializarTabuleiro(p1.tabuleiro);
    inicializarTabuleiro(p1.tiros);
    inicializarTabuleiro(p2.tabuleiro);
    inicializarTabuleiro(p2.tiros);

    posicionarNavios(p1.tabuleiro);
    posicionarNavios(p2.tabuleiro);

    int turno = 0;

    while (1) {
        int linha, coluna;
        if (turno % 2 == 0) {
            printf("\nJogador 1 - Seu mapa de ataques:\n");
            exibirTabuleiro(p1.tiros);
            printf("Jogador 1 - Ataque!\n");
            lerCoordenada(&linha, &coluna);
            int resultado = atacar(&p2, linha, coluna);
            if (resultado == 1) {
                printf("Acertou um navio!\n");
                j1->pontuacao++;
            } else if (resultado == 0) {
                printf("Errou!\n");
            } else {
                printf("Já atirou aqui.\n");
                continue;
            }
        } else {
            printf("\nJogador 2 - Seu mapa de ataques:\n");
            exibirTabuleiro(p2.tiros);
            printf("Jogador 2 - Ataque!\n");
            lerCoordenada(&linha, &coluna);
            int resultado = atacar(&p1, linha, coluna);
            if (resultado == 1) {
                printf("Acertou um navio!\n");
                j2->pontuacao++;
            } else if (resultado == 0) {
                printf("Errou!\n");
            } else {
                printf("Já atirou aqui.\n");
                continue;
            }
        }

        if (todosNaviosAfundados(p2.tabuleiro)) {
            printf("\nJogador 1 venceu!\n");
            j1->vitorias++;
            j2->derrotas++;
            break;
        }
        if (todosNaviosAfundados(p1.tabuleiro)) {
            printf("\nJogador 2 venceu!\n");
            j2->vitorias++;
            j1->derrotas++;
            break;
        }

        turno++;
    }

    printf("\nPontuação Jogador 1: %d\nPontuação Jogador 2: %d\nVitórias Jogador 1: %d\nVitórias Jogador 2: %d\n",
           j1->pontuacao, j2->pontuacao, j1->vitorias, j2->vitorias);
}


//função principal, menu.
int main() {
    srand(time(NULL));

    char modo;
    printf("Quer jogar contra Bot ou Local? (B para Bot, L para Local): ");
    scanf(" %c", &modo);
    modo = toupper(modo);

    Jogador jogador1 = {0, 0, 0};
    Jogador jogador2 = {0, 0, 0}; 

    if (modo == 'B') {
        jogarContraBot(&jogador1, &jogador2);
    } else if (modo == 'L') {
        jogarLocal(&jogador1, &jogador2);
    } else {
        printf("Modo inválido.\n");
    }

    return 0;
}
