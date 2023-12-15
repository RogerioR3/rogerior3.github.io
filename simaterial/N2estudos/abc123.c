#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

// Definição da estrutura para passar dados aos threads
typedef struct {
    FILE *file;
    sem_t *sem_number, *sem_letter;
} ThreadData;

// Função que representa o comportamento do thread de números
void *numberThread(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    for (int i = 1; i <= 26; i++) {
        sem_wait(data->sem_number);

        fprintf(data->file, "%d\n", i);
        fflush(data->file);

        sem_post(data->sem_letter);
    }

    return NULL;
}

// Função que representa o comportamento do thread de letras
void *letterThread(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    for (char c = 'A'; c <= 'Z'; c++) {
        sem_wait(data->sem_letter);

        fprintf(data->file, "%c\n", c);
        fflush(data->file);

        sem_post(data->sem_number);
    }

    return NULL;
}

int main() {
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Inicialização dos semáforos
    sem_t sem_number, sem_letter;
    sem_init(&sem_number, 0, 1);
    sem_init(&sem_letter, 0, 0);

    // Dados a serem passados para os threads
    ThreadData data = {file, &sem_number, &sem_letter};

    // Identificadores dos threads
    pthread_t numberThreadId, letterThreadId;

    // Criação dos threads
    if (pthread_create(&numberThreadId, NULL, numberThread, &data) != 0 ||
        pthread_create(&letterThreadId, NULL, letterThread, &data) != 0) {
        perror("Erro ao criar threads");
        exit(EXIT_FAILURE);
    }

    // Aguarda a finalização dos threads
    if (pthread_join(numberThreadId, NULL) != 0 ||
        pthread_join(letterThreadId, NULL) != 0) {
        perror("Erro ao aguardar threads");
        exit(EXIT_FAILURE);
    }

    // Fecha o arquivo
    fclose(file);

    // Abre o arquivo para leitura e exibe seu conteúdo
    file = fopen("output.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    int value;
    char ch;

    // Exibe o conteúdo do arquivo
    while (fscanf(file, "%d %c", &value, &ch) != EOF) {
        printf("%d %c\n", value, ch);
    }

    // Fecha o arquivo
    fclose(file);

    // Destroi os semáforos
    sem_destroy(&sem_number);
    sem_destroy(&sem_letter);

    return 0;
}
