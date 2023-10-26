#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_A, pid_B, pid_C;

    // Processo P_A
    printf("Sou P_A com PID %d, filho de PID %d\n", getpid(), getppid());

    // Cria P_B
    pid_B = fork();
    
    if (pid_B == 0) {
        // Processo P_B
		printf("Eu P_A criei P_B!\n");
        printf("	Sou P_B com PID %d, PID interno %d, filho do PID %d\n", getpid(), pid_B, getppid());
		

        // Cria P_C
        pid_C = fork();
        
        if (pid_C == 0) {
            // Processo P_C
            printf("	Eu P_B criei P_C!\n");
			printf("		Sou P_C com PID %d, PID interno %d, filho do PID %d\n", getpid(), pid_C, getppid());
            printf("		Eu P_C executei: ps\n");
			
            // Executa o comando "ps"
            execlp("ps", "ps", NULL);
        } else {
            wait(NULL); // Espera P_C terminar
			sleep(2);
            printf("\n	Eu P_B aguardei P_C terminar!\n");
            printf("	Eu P_B executei: ps\n");
            execlp("ps", "ps", NULL);
        }
    } else {
        wait(NULL); // Espera P_B terminar
		sleep(2);
        printf("\nEu P_A aguardei P_B terminar!\n");
        printf("Eu P_A executei: ps\n");
        execlp("ps", "ps", NULL);
    }

    return 0;
}
