/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Noci Deri
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1258
Data        : 23/06/2026
Objetivo    : Sudoku
Aprendizado : utilização de vetores para checagem de elementos em uma lista
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int validarSudoku(int matriz[9][9]) {

    //verificando Linhas e Colunas
    for (int i = 0; i < 9; i++) {
        int v_linha[10] = {0};
        int v_coluna[10] = {0};
        
        //loop for coloca o valor 1 em cada elemento já reconhecido da linha ou coluna
        //se o elemento já tem o valor de 1, é pq a entrada é uma solução incorreta
        for (int j = 0; j < 9; j++) {
            int num_linha = matriz[i][j];
            int num_coluna = matriz[j][i];
            
            // retorna 0 se um elemento já existe na linha
            if (v_linha[num_linha] == 1) return 0;
            v_linha[num_linha] = 1;
            
            // retorna 0 se um elemento já existe na coluna
            if (v_coluna[num_coluna] == 1) return 0;
            v_coluna[num_coluna] = 1;
        }
    }

    //verificando as 9 subgrades 3x3
    //mesma logica de cima so que para a subgrade
    for (int L = 0; L < 9; L += 3) {
        for (int C = 0; C < 9; C += 3) {
            int v_bloco[10] = {0};
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = matriz[L + i][C + j];
                    
                    if (v_bloco[num] == 1) return 0;
                    v_bloco[num] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n, instancia;
    
    scanf("%d", &n);

    for (instancia = 1; instancia <= n; instancia++) {
        int sudoku[9][9];
        int i, j;

        // Leitura da matriz
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", instancia);

        if (validarSudoku(sudoku) == 1) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
