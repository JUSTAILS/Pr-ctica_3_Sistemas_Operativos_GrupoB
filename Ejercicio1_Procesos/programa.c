#include <stdio.h>
#include <unistd.h>
int main(){
	
	printf("Ejemplo de fork.\n");
	printf("Inicio del proceso padre. PID=%d\n", getpid());//se obtiene el Process ID del proceso padre
	if (fork() == 0){
		/*Proceso hijo*/
		printf("Inicio del proceso hijo. PID=%d, PPID=%d\n", getpid(), getppid());//Se obtienen los Process ID del proceso padre y del proceso Hijo
		sleep(1);
	}
	else
	{
		/*Proceso padre*/
		printf("Continuacion del padre. PID=%d\n", getpid());//Continua el proceso padre hasta su finalizacion, se obtine nuevamente su Process ID
	       sleep(1);	
	}
	printf("Fin del proceso %d\n", getpid());
	return 0;
}



