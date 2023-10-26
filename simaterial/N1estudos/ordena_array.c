//MATERIAL DE APIO
//http://wiki.icmc.usp.br/images/f/fd/AulaTAD.pdf
//chatGPT

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "sortlib.h"
#include <sys/wait.h>

#define ARRAY_SIZE 10

int main() {
    int arr[ARRAY_SIZE];

    // Preencher o array com números desordenados
    printf("Array desordenado: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100 + 2;
        printf("%d ", arr[i]);
    }
    printf("\n");

    pid_t child_pid = fork();

    if (child_pid < 0) {
        fprintf(stderr, "Erro ao criar o processo filho\n");
        exit(1);
    } else if (child_pid == 0) {
        // Processo filho
        printf("Processo filho (Quick Sort) iniciado.\n");
        quickSort(arr, 0, ARRAY_SIZE - 1); //Funcao da Biblioteca sortlib

        printf("Array ordenado pelo processo filho (Quick Sort): ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } else {
        // Processo pai
        printf("Processo pai (Bubble Sort) iniciado.\n");
        bubbleSort(arr, ARRAY_SIZE); //Funcao da  Biblioteca sortlib

        printf("Array ordenado pelo processo pai (Bubble Sort): ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        wait(NULL); // Esperar pelo término do processo filho
        printf("Processo filho (Quick Sort) terminou.\n");
        printf("Processo Pai (Buble Sort) terminou . \n");
    }

    return 0;
}