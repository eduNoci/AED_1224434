/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome: Eduardo Noci Deri
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 20/04/2026
Objetivo    : Leia 100 valores inteiros. Apresente então o maior valor lido e a posicao dentre os 100 valores lidos.
Aprendizado : Como utilizar vetores em c
-------------------------------------------------------------------------- */
#include <stdio.h>

int main()
{
    int input[99];
    int maior = 0;
    int posicao;
    for (int i = 0;i < 100; i++) 
    {    
        scanf("%d", &input[i]);
        if(input[i] > maior)
            {
                maior = input[i];
                posicao = i + 1;
            }
    }
    printf("%d\n%d\n", maior, posicao);
    return 0;
}
