#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
typedef struct Node {
    char caractere;
    struct Node *prox;
} Node;

// Estrutura da Pilha
typedef struct {
    Node *topo;
} Pilha;

// Inicializa a pilha
Pilha* criar_pilha() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if (p == NULL) exit(1);
    p->topo = NULL;
    return p;
}

// Empilha um elemento (push)
void empilhar(Pilha *p, char c) {
    Node *novo = (Node *) malloc(sizeof(Node));
    if (novo == NULL) exit(1);
    novo->caractere = c;
    novo->prox = p->topo;
    p->topo = novo;
}

// Desempilha um elemento (pop)
int desempilhar(Pilha *p) {
    if (p->topo == NULL) return 0; // Pilha vazia

    Node *temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
    return 1; // Sucesso ao desempilhar
}

// Verifica se a pilha está vazia
int esta_vazia(Pilha *p) {
    return p->topo == NULL;
}

// Libera toda a memória restante da pilha
void destruir_pilha(Pilha *p) {
    while (!esta_vazia(p)) {
        desempilhar(p);
    }
    free(p);
}

int main() {
    char expressao[1005];

    // Leitura das expressões até o Fim de Arquivo (EOF)
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        Pilha *p = criar_pilha();
        int valido = 1;

        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                empilhar(p, '(');
            } else if (expressao[i] == ')') {
                // Tenta desempilhar o '(' correspondente
                if (!desempilhar(p)) {
                    valido = 0; // Tentou fechar sem ter parêntese aberto prévio
                    break;
                }
            }
        }

        // Se sobrou algum '(' sem ser fechado, a expressão é inválida
        if (!esta_vazia(p)) {
            valido = 0;
        }

        if (valido) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        destruir_pilha(p);
    }

    return 0;
}