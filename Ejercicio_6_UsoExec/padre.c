#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int ejecutarNuevoProc(char *programa, char *arg_list[]);

int main() {
    char *programa = "ls";
    char *arg_list[] = {"ls", "-l", NULL};
    int pid = ejecutarNuevoProc(programa, arg_list);
    wait(NULL);  // el padre espera a que termine el hijo
    fprintf(stdout, "el proceso hijo con PID %d se ha ejecutado\n", pid);
    return 0;
}

int ejecutarNuevoProc(char *programa, char *arg_list[]) {
    pid_t pid;
    pid = fork();
    switch (pid) {
        case -1:
            fprintf(stderr, "No se pudo crear el proceso\n");
            exit(EXIT_FAILURE);
        case 0:
            // Esto se ejecuta en el proceso hijo
            execvp(programa, arg_list); // reemplaza el hijo por "ls -l"
            // Si execvp regresa, significa que hubo un error
            fprintf(stderr, "error al ejecutar execvp\n");
            exit(EXIT_FAILURE);
        default:
            // esto lo ejecuta el padre; devuelve el pid del hijo
            return pid;
    }
}
