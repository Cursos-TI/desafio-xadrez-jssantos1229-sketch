#include <stdio.h>

// ===============================
// FUNÇÕES RECURSIVAS
// ===============================

// Torre → move para a Direita
void moverTorre(int casas) {
    if (casas <= 0) return;  // Caso base
    printf("Direita\n");
    moverTorre(casas - 1);   // Chamada recursiva
}

// Rainha → move para a Esquerda
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Bispo → movimento diagonal (Cima + Direita)
// Usa recursividade + loops aninhados
void moverBispo(int casas) {
    if (casas <= 0) return;

    // Loop externo → movimento vertical
    for (int v = 0; v < 1; v++) {
        printf("Cima\n");

        // Loop interno → movimento horizontal
        for (int h = 0; h < 1; h++) {
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1); // Próxima casa diagonal
}

// ===============================
// CAVALO → LOOPS COMPLEXOS
// Movimento em L: Cima, Cima, Direita
// ===============================
void moverCavalo() {
    int vertical = 2;
    int horizontal = 1;

    for (int v = 0; v < vertical; v++) {
        printf("Cima\n");

        // Só executa o movimento horizontal após subir 2 vezes
        if (v == vertical - 1) {
            int h = 0;

            while (h < horizontal) {
                if (h == 0) {
                    printf("Direita\n");
                }
                h++;
            }
        }
    }
}

// ===============================
// FUNÇÃO PRINCIPAL
// ===============================
int main() {

    int casasTorre = 3;
    int casasRainha = 2;
    int casasBispo = 3;

    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    printf("\nMovimento do Bispo:\n");
    moverBispo(casasBispo);

    printf("\nMovimento do Cavalo:\n");
    moverCavalo();

    return 0;
}
