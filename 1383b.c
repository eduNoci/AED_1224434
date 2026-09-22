#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente uma matriz de inteiros (linhas x colunas)
int** alocar_matriz(int linhas, int colunas) {
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) return NULL;

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) return NULL;
    }
    return matriz;
}

// Função para liberar a memória alocada da matriz
void liberar_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Verifica se a matriz atende a todas as regras do Sudoku
int eh_valido(int **matriz) {
    // 1. Validação de cada Linha e Coluna
    for (int i = 0; i < 9; i++) {
        int linha_vis[10] = {0};
        int coluna_vis[10] = {0};

        for (int j = 0; j < 9; j++) {
            // Checa a linha i
            int val_linha = matriz[i][j];
            if (val_linha < 1 || val_linha > 9 || linha_vis[val_linha]) return 0;
            linha_vis[val_linha] = 1;

            // Checa a coluna i
            int val_coluna = matriz[j][i];
            if (val_coluna < 1 || val_coluna > 9 || coluna_vis[val_coluna]) return 0;
            coluna_vis[val_coluna] = 1;
        }
    }

    // 2. Validação dos 9 sub-blocos 3x3
    for (int bloco_r = 0; bloco_r < 9; bloco_r += 3) {
        for (int bloco_c = 0; bloco_c < 9; bloco_c += 3) {
            int bloco_vis[10] = {0};

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int val = matriz[bloco_r + i][bloco_c + j];
                    if (val < 1 || val > 9 || bloco_vis[val]) return 0;
                    bloco_vis[val] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Aloca a matriz 9x9 uma única vez para reutilizar em todas as instâncias
    int **sudoku = alocar_matriz(9, 9);
    if (sudoku == NULL) return 1;

    for (int k = 1; k <= n; k++) {
        // Leitura da matriz 9x9
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // Exibição do resultado
        printf("Instancia %d\n", k);
        if (eh_valido(sudoku)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    // Liberação da memória
    liberar_matriz(sudoku, 9);

    return 0;
}