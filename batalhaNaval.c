#include <stdio.h>

// Preenche a matriz com água (0)
void preencher(int m[10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            m[i][j] = 0;
}

// Mostra a matriz com letras e números
void mostrar(int m[10][10]) {
    printf("   ");
    for (char c = 'A'; c <= 'J'; c++) printf(" %c", c);
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++)
            printf(" %d", m[i][j]);
        printf("\n");
    }
}

// Posiciona navio (0 = horizontal, 1 = vertical)
void posicionar(int m[10][10], int lin, int col, int direcao) {
    for (int i = 0; i < 3; i++) {
        int l = lin + (direcao ? i : 0);
        int c = col + (direcao ? 0 : i);
        m[l][c] = 3;
    }
}

// Verifica se pode posicionar o navio
int pode(int m[10][10], int lin, int col, int dir) {
    for (int i = 0; i < 3; i++) {
        int l = lin + (dir ? i : 0);
        int c = col + (dir ? 0 : i);
        if (l >= 10 || c >= 10 || m[l][c] != 0) return 0;
    }
    return 1;
}

int main() {
    int matriz[10][10];
    int lh = 2, ch = 4; // navio horizontal
    int lv = 5, cv = 7; // navio vertical

    preencher(matriz);

    if (pode(matriz, lh, ch, 0)) posicionar(matriz, lh, ch, 0);
    if (pode(matriz, lv, cv, 1)) posicionar(matriz, lv, cv, 1);

    mostrar(matriz);
    return 0;
}