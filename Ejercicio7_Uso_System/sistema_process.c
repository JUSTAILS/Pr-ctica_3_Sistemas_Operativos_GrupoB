#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    int pid;
    
    pid = fork();
    
    switch(pid)
    {
    case -1: // Error al crear proceso
        printf("No se ha podido crear el proceso hijo\n");
        break;
    
    case 0: // Proceso hijo
        printf("=== PROCESO HIJO - LISTANDO PROCESOS DEL SISTEMA ===\n");
        printf("PID del hijo: %d\n", getpid());
        
        // Usar system() para listar procesos
        system("ps aux");
        
        printf("=== FIN DE LISTADO DE PROCESOS ===\n");
        break;
    
    default: // Proceso padre
        printf("=== PROCESO PADRE ===\n");
        printf("PID del padre: %d\n", getpid());
        printf("PID del hijo: %d\n", pid);
        
        // Esperar a que el hijo termine
        wait(NULL);
        printf("El proceso hijo ha terminado\n");
        break;
    }
    
    return 0;
}

