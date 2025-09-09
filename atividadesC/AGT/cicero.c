#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define NAVIO 3

void inicializaTabuleiro(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = '~';  // água
}

void imprimeTabuleiro(char tab[TAM][TAM], int reveal) {
    printf("  ");
    for (int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            if (reveal)
                printf("%c ", tab[i][j]);
            else {
                // Esconde navios
                if (tab[i][j] == 'N')
                    printf("~ ");
                else
                    printf("%c ", tab[i][j]);
            }
        }
        printf("\n");
    }
}

int posicionaNavio(char tab[TAM][TAM]) {
    int linha, coluna, direcao;
    printf("Posicione seu navio (tamanho %d)\n", NAVIO);
    printf("Digite linha (0-%d): ", TAM - 1);
    scanf("%d", &linha);
    printf("Digite coluna (0-%d): ", TAM - 1);
    scanf("%d", &coluna);
    printf("Direcao (0 - horizontal, 1 - vertical): ");
    scanf("%d", &direcao);

    if (direcao == 0) { // horizontal
        if (coluna + NAVIO > TAM) {
            printf("Posição inválida, tente novamente.\n");
            return 0;
        }
        for (int i = 0; i < NAVIO; i++) {
            if (tab[linha][coluna + i] == 'N') {
                printf("Já existe navio aqui, tente novamente.\n");
                return 0;
            }
        }
        for (int i = 0; i < NAVIO; i++)
            tab[linha][coluna + i] = 'N';
    } else if (direcao == 1) { // vertical
        if (linha + NAVIO > TAM) {
            printf("Posição inválida, tente novamente.\n");
            return 0;
        }
        for (int i = 0; i < NAVIO; i++) {
            if (tab[linha + i][coluna] == 'N') {
                printf("Já existe navio aqui, tente novamente.\n");
                return 0;
            }
        }
        for (int i = 0; i < NAVIO; i++)
            tab[linha + i][coluna] = 'N';
    } else {
        printf("Direção inválida.\n");
        return 0;
    }
    return 1;
}

int ataque(char tab[TAM][TAM], int linha, int coluna) {
    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
        printf("Coordenada inválida!\n");
        return 0;
    }

    if (tab[linha][coluna] == 'N') {
        tab[linha][coluna] = 'X'; // acerto
        printf("Você acertou um navio!\n");
        return 1;
    } else if (tab[linha][coluna] == '~') {
        tab[linha][coluna] = 'O'; // água atingida
        printf("Você errou.\n");
        return 0;
    } else {
        printf("Você já atacou essa posição, tente outra.\n");
        return 0;
    }
}

int navioAfundado(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (tab[i][j] == 'N') // ainda há parte do navio
                return 0;
    return 1;
}

int main() {
    char tabuleiro1[TAM][TAM];
    char tabuleiro2[TAM][TAM];
    int linha, coluna, sucesso;

    printf("Jogo Batalha Naval simples\n");

    // Inicializa tabuleiros
    inicializaTabuleiro(tabuleiro1);
    inicializaTabuleiro(tabuleiro2);

    // Posiciona navios jogador 1
    do {
        printf("\nJogador 1:\n");
        sucesso = posicionaNavio(tabuleiro1);
    } while (!sucesso);

    // Posiciona navios jogador 2
    do {
        printf("\nJogador 2:\n");
        sucesso = posicionaNavio(tabuleiro2);
    } while (!sucesso);

    int jogador_atual = 1;
    while (1) {
        printf("\nTabuleiro do adversário:\n");
        if (jogador_atual == 1)
            imprimeTabuleiro(tabuleiro2, 0);
        else
            imprimeTabuleiro(tabuleiro1, 0);

        printf("Jogador %d, digite o ataque (linha coluna): ", jogador_atual);
        scanf("%d %d", &linha, &coluna);

        if (jogador_atual == 1) {
            sucesso = ataque(tabuleiro2, linha, coluna);
            if (navioAfundado(tabuleiro2)) {
                printf("Jogador 1 venceu!\n");
                break;
            }
        } else {
            sucesso = ataque(tabuleiro1, linha, coluna);
            if (navioAfundado(tabuleiro1)) {
                printf("Jogador 2 venceu!\n");
                break;
            }
        }

        if (sucesso == 0) {
            // Passa o turno apenas se o ataque foi erro ou posição já atacada
            jogador_atual = (jogador_atual == 1) ? 2 : 1;
        }
    }

    printf("Fim do jogo.\n");
    return 0;
}