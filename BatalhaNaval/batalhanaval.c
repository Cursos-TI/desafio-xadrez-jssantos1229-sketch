#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais
    int linhaH = 2, colunaH = 4; // Horizontal
    int linhaV = 5, colunaV = 1; // Vertical

    int i, j;

    // Inicializa tabuleiro com água
    for (i = 0; i < TAM_TABULEIRO; i++)
        for (j = 0; j < TAM_TABULEIRO; j++)
            tabuleiro[i][j] = AGUA;

    // Valida e posiciona navio horizontal
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora do limite.\n");
        return 1;
    }

    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != AGUA) {
            printf("Erro: Sobreposição no navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Valida e posiciona navio vertical
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora do limite.\n");
        return 1;
    }

    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] != AGUA) {
            printf("Erro: Sobreposição no navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // ===============================
    // Exibição com coordenadas
    // ===============================

    printf("\n    ");
    for (j = 0; j < TAM_TABULEIRO; j++) {
        printf("%c ", 'A' + j);  // Letras A até J
    }
    printf("\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d  ", i); // Números das linhas
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
