#include <stdio.h>

#define TAMANHO 10  // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Valor para representar um navio
#define AGUA 0      // Valor para representar água
#define HABILIDADE 5 // Valor para representar área de efeito da habilidade

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ===== PARTE 1 - NÍVEL NOVATO =====
    int navioHorizontal[3] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[3] = {NAVIO, NAVIO, NAVIO};

    int linhaH = 2, colunaH = 1;
    int linhaV = 4, colunaV = 5;

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // ===== PARTE 2 - NÍVEL AVENTUREIRO =====
    int linhaDiag1 = 0, colunaDiag1 = 0;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = NAVIO;
    }

    int linhaDiag2 = 0, colunaDiag2 = 9;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = NAVIO;
    }

    // ===== PARTE 3 - NÍVEL MESTRE =====
    int habilidadeCone[5][5];
    int habilidadeCruz[5][5];
    int habilidadeOctaedro[5][5];

    // Cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                habilidadeCone[i][j] = 1;
            } else {
                habilidadeCone[i][j] = 0;
            }
        }
    }

    // Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                habilidadeCruz[i][j] = 1;
            } else {
                habilidadeCruz[i][j] = 0;
            }
        }
    }

    // Octaedro (losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 0 && j == 2) ||
                (i == 1 && (j == 1 || j == 2 || j == 3)) ||
                (i == 2) ||
                (i == 3 && (j == 1 || j == 2 || j == 3)) ||
                (i == 4 && j == 2)) {
                habilidadeOctaedro[i][j] = 1;
            } else {
                habilidadeOctaedro[i][j] = 0;
            }
        }
    }

    // Ponto de origem da habilidade (você pode trocar para testar outras posições)
    int origemLinha = 6;
    int origemColuna = 6;

    // Sobrepor uma das habilidades (ex: Cone)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaTab = origemLinha - 2 + i;
            int colunaTab = origemColuna - 2 + j;

            if (linhaTab >= 0 && linhaTab < TAMANHO && colunaTab >= 0 && colunaTab < TAMANHO) {
                if (habilidadeCone[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == AGUA) {
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }

    // ===== EXIBINDO TABULEIRO FINAL =====
    printf("TABULEIRO BATALHA NAVAL (COM HABILIDADE)\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//  Acabei me perdendo no codigo, espero que esteja conforme desejado!
