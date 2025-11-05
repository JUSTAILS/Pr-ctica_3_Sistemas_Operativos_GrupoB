#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 3

void hijo_imprime_1_a_10(void);
void hijo_imprime_pares(void);
void hijo_imprime_impares(void);

int main(void)
{
    pid_t pid;
    int i;

    for (i = 0; i < NUM_PROC; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("Error al crear el proceso");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            switch (i)
            {
                case 0: hijo_imprime_1_a_10();   break;
                case 1: hijo_imprime_pares();     break;
                case 2: hijo_imprime_impares();   break;
                default:
                    printf("Hijo %d: tarea por defecto\n", i);
                    break;
            }
            exit(EXIT_SUCCESS);
        }
    }

    for (i = 0; i < NUM_PROC; i++)
    {
        pid_t w = wait(NULL);
        if (w > 0) printf("Padre: terminó hijo con PID %d\n", (int)w);
    }

    printf("Padre: todos los hijos han terminado.\n");
    return 0;
}

void hijo_imprime_1_a_10(void)
{
    int j;
    printf("Hijo[1-10] (PID %d) empezando:\n", getpid());
    for (j = 1; j <= 10; j++) printf("%d ", j);
    printf("\nHijo[1-10] (PID %d) terminado.\n", getpid());
}

void hijo_imprime_pares(void)
{
    int j;
    printf("Hijo[pares] (PID %d) empezando:\n", getpid());
    for (j = 2; j <= 20; j += 2) printf("%d ", j);
    printf("\nHijo[pares] (PID %d) terminado.\n", getpid());
}

void hijo_imprime_impares(void)
{
    int j;
    printf("Hijo[impares] (PID %d) empezando:\n", getpid());
    for (j = 1; j <= 19; j += 2) printf("%d ", j);
    printf("\nHijo[impares] (PID %d) terminado.\n", getpid());
}
