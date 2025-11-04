#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (){
	pid_t pid;

	pid = fork(); //Proceso hijo

	if (pid > 0) {
		//Proceso padre
		printf ("Soy el proceso padre. Mi PID es %d\n", getpid());
		sleep(20); //El padre duerme miesntras el hijo termina -> hijo se vuleve xoombie
	} else if (pid == 0) {
		//Proceso hijo
		printf ("Soy el proceso hijo. MI PID es %d\n", getpid ());
		exit (0); // El hijo termina inmediatamente
	} else {
		//ERror al crear el proceso
		perror ("Error al crear el proceso hijo");
		return 1;
	}
	return 0;
}
