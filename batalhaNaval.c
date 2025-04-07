#include <stdio.h>

#define TAMANHO 10  // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Valor para representar um navio
#define AGUA 0      // Valor para representar água

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ===== PARTE 1 - NÍVEL NOVATO =====
    // Dois vetores representando navios com 3 posições
    int navioHorizontal[3] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[3] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais para os navios
    int linhaH = 2, colunaH = 1; // horizontal começa na linha 2, coluna 1
    int linhaV = 4, colunaV = 5; // vertical começa na linha 4, coluna 5

    // Posiciona navio horizontal (da esquerda para a direita)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical (de cima para baixo)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // ===== PARTE 2 - NÍVEL AVENTUREIRO =====
    // Dois navios diagonais de tamanho 3

    // Diagonal principal: posições como [i][i]
    int linhaDiag1 = 0, colunaDiag1 = 0;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = NAVIO;
    }

    // Diagonal secundária: posições como [i][9 - i]
    int linhaDiag2 = 0, colunaDiag2 = 9;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = NAVIO;
    }

    // ===== EXIBINDO O TABULEIRO =====
    printf("TABULEIRO BATALHA NAVAL\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
