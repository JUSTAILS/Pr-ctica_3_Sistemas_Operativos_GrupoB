#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

int main()
{
    int pid;
    int i;
    FILE *archivo;
    
    // Crear segmentos de memoria compartida
    int shmid_var = shmget(IPC_PRIVATE, sizeof(int), 0666|IPC_CREAT);
    int shmid_flag = shmget(IPC_PRIVATE, sizeof(int), 0666|IPC_CREAT);
    
    if (shmid_var == -1 || shmid_flag == -1) {
        printf("Error al crear memoria compartida\n");
        exit(1);
    }
    
    // Adjuntar memoria compartida
    int *variable = (int*) shmat(shmid_var, NULL, 0);
    int *flag = (int*) shmat(shmid_flag, NULL, 0);
    
    if (variable == (int*) -1 || flag == (int*) -1) {
        printf("Error al adjuntar memoria compartida\n");
        exit(1);
    }
    
    // Inicializar variables
    *variable = 0;
    *flag = 0; // 0 = padre puede escribir, 1 = hijo puede leer
    
    pid = fork();

    switch(pid)
    {
    case -1: // Si pid es -1 quiere decir que ha habido un error
        printf("No se ha podido crear el proceso hijo\n");
        break;
    
    case 0: // Proceso hijo
        archivo = fopen("valores.txt", "w");
        if(archivo == NULL) {
            printf("Error al abrir el archivo\n");
            exit(1);
        }
        
        for(i=1; i<=10; i++) {
            // Esperar a que el padre actualice el valor
            while(*flag == 0) {
                usleep(1000); // Espera corta
            }
            fprintf(archivo, "%d\n", *variable);
            printf("Hijo: Registrado valor %d en archivo\n", *variable);
            *flag = 0; // Permitir que el padre continúe
        }
        fclose(archivo);
        
        // Desadjuntar memoria compartida
        shmdt(variable);
        shmdt(flag);
        break;
    
    default: // Proceso padre
        for(i=1; i<=10; i++) {
            *variable += 10;
            printf("Padre: Variable incrementada a %d\n", *variable);
            *flag = 1; // Indicar al hijo que puede leer
            
            // Esperar a que el hijo lea el valor
            while(*flag == 1) {
                usleep(1000); // Espera corta
            }
        }
        
        wait(0); // Esperar a que el hijo termine
        
        // Desadjuntar y eliminar memoria compartida
        shmdt(variable);
        shmdt(flag);
        shmctl(shmid_var, IPC_RMID, NULL);
        shmctl(shmid_flag, IPC_RMID, NULL);
        break;
    }
    
    return 0;
}
