// Referências: Google Bard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  char comando[100];
  char *parametros[10];
  int i = 0;

  // Entrada do comando e parâmetros
  printf("Digite o comando e seus parâmetros: ");
  fgets(comando, sizeof(comando), stdin); //Captura o parêmetro
  comando[strlen(comando) - 1] = '\0'; // Remove o '\n' do final da string

  // Separa os parâmetros
  while (comando[i] != '\0') {
    if (comando[i] == ' ') {
      parametros[i] = &comando[i + 1];
      i++;
    }
    i++;
  }
  parametros[i] = NULL;

  // Cria um novo processo
  pid_t pid = fork();

  // Se o processo é filho, executa o comando
  if (pid == 0) {
	printf("Marcador - A");
    execvp(comando, parametros);
    printf("Erro ao executar o comando.\n");
    exit(1);
  }

  // Se o processo é pai, espera o filho terminar
  if (waitpid(pid, NULL, 0) < 0) {
	printf("Marcador - B");
	printf("Erro ao esperar o filho terminar.\n");
	exit(1);
  }

  return 0;
}