#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho = 100;
    
    // Alocação dinâmica de memória para 100 inteiros
    int *vetor = (int *) malloc(tamanho * sizeof(int));

    // Verificação de segurança da alocação
    if (vetor == NULL) {
        return 1;
    }

    int maior = 0;
    int posicao = 0;

    // Leitura dos valores e busca do maior número
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);

        if (i == 0 || vetor[i] > maior) {
            maior = vetor[i];
            posicao = i + 1; // A posição no Beecrowd começa em 1
        }
    }

    // Impressão dos resultados
    printf("%d\n", maior);
    printf("%d\n", posicao);

    // Liberação da memória alocada
    free(vetor);

    return 0;
}