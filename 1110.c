#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

// Estrutura da Fila que gerencia a lista
typedef struct {
    Node *inicio;
    Node *fim;
    int tamanho;
} Fila;

// Inicializa a fila encadeada
Fila* criar_fila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    if (f == NULL) exit(1);
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

// Insere no final da fila
void enfileirar(Fila *f, int val) {
    Node *novo = (Node *) malloc(sizeof(Node));
    if (novo == NULL) exit(1);
    novo->valor = val;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->tamanho++;
}

// Remove e retorna o valor do início da fila
int desenfileirar(Fila *f) {
    if (f->inicio == NULL) return -1;

    Node *temp = f->inicio;
    int val = temp->valor;
    
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
    f->tamanho--;
    return val;
}

// Libera toda a memória restante da fila
void liberar_fila(Fila *f) {
    while (f->inicio != NULL) {
        desenfileirar(f);
    }
    free(f);
}

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        Fila *f = criar_fila();

        // Preenche a fila com as cartas de 1 até N
        for (int i = 1; i <= n; i++) {
            enfileirar(f, i);
        }

        printf("Discarded cards:");
        int primeiro_descarte = 1;

        // Processa as cartas enquanto houver mais de uma
        while (f->tamanho > 1) {
            // 1. Descarta a carta do topo
            int descartada = desenfileirar(f);
            if (primeiro_descarte) {
                printf(" %d", descartada);
                primeiro_descarte = 0;
            } else {
                printf(", %d", descartada);
            }

            // 2. Mova a próxima carta do topo para a base
            int mover = desenfileirar(f);
            enfileirar(f, mover);
        }

        // Exibe a carta remanescente
        printf("\nRemaining card: %d\n", f->inicio->valor);

        liberar_fila(f);
    }

    return 0;
}