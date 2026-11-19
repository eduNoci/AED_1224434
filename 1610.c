/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Eduardo Noci Deri
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : Ler dois valores inteiros e mostrar a soma.
Dificuldade : Compreensão do funcionamento do DFS
Uso de IA   : Utilizada para auxiliar na compreensão do funcionamento do DFS
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int head[10005];
int to[30005];
int nxt[30005];
int edge_cnt;

int estado[10005]; 

void init(int n) {
    edge_cnt = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        estado[i] = 0;
    }
}

void add_edge(int u, int v) {
    to[edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}

int tem_ciclo(int u) {
    estado[u] = 1; 

    for (int e = head[u]; e != -1; e = nxt[e]) {
        int v = to[e];

        if (estado[v] == 1) {
            return 1; 
        }
        if (estado[v] == 0) {
            if (tem_ciclo(v)) {
                return 1;
            }
        }
    }

    estado[u] = 2; 
    return 0;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        init(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            add_edge(a, b);
        }

        int ciclo = 0;
      
        for (int i = 1; i <= n; i++) {
            if (estado[i] == 0) {
                if (tem_ciclo(i)) {
                    ciclo = 1;
                    break;
                }
            }
        }

        if (ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
