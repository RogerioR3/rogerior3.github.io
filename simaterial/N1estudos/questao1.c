#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO_FILA 100

struct Fila {
    int itens[MAX_TAMANHO_FILA];
    int frente, fundo;
};

struct Fila criarFila() {
    struct Fila fila;
    fila.frente = -1;
    fila.fundo = -1;
    return fila;
}

int estaVazia(struct Fila *fila) {
    return (fila->frente == -1);
}

int estaCheia(struct Fila *fila) {
    return (fila->fundo == MAX_TAMANHO_FILA - 1);
}

void inserir(struct Fila *fila, int item) {
    if (estaCheia(fila)) {
        printf("A fila está cheia. Não é possível inserir mais itens.\n");
    } else {
        if (fila->frente == -1) {
            fila->frente = 0;
        }
        fila->fundo = fila->fundo + 1;
        fila->itens[fila->fundo] = item;
    }
}

int remover(struct Fila *fila) {
    int item_removido;
    if (estaVazia(fila)) {
        printf("A fila está vazia. Não é possível remover itens.\n");
        return -1; // Valor inválido
    } else {
        item_removido = fila->itens[fila->frente];
        if (fila->frente == fila->fundo) {
            fila->frente = fila->fundo = -1;
        } else {
            fila->frente = fila->frente + 1;
        }
        return item_removido;
    }
}

int tamanho(struct Fila *fila) {
    if (estaVazia(fila)) {
        return 0;
    } else {
        return fila->fundo - fila->frente + 1;
    }
}

int main() {
    struct Fila fila_de_impressao = criarFila();

    // Simulando a chegada de tarefas à fila de impressão
    inserir(&fila_de_impressao, 1);
    inserir(&fila_de_impressao, 2);
    inserir(&fila_de_impressao, 3);

    printf("Tamanho da fila de impressão: %d\n", tamanho(&fila_de_impressao));

    // Simulando a impressão, onde a primeira tarefa é retirada da fila
    int tarefa_atual = remover(&fila_de_impressao);
    printf("Imprimindo: %d\n", tarefa_atual);

    printf("Tamanho da fila de impressão após a impressão: %d\n", tamanho(&fila_de_impressao));

    return 0;
}
