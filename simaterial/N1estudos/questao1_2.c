#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* criarNovoNo(int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->next = NULL;
    return novoNo;
}

// Função para imprimir os elementos da lista
void imprimirLista(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = criarNovoNo(1);
    struct Node* segundo = criarNovoNo(2);
    struct Node* terceiro = criarNovoNo(3);

    head->next = segundo;
    segundo->next = terceiro;

    printf("Lista Encadeada: ");
    imprimirLista(head);

    return 0;
}
