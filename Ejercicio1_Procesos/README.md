# Ejercicio 1 - Procesos

## Descripción

En este ejercicio se ejecutó un programa en C que implementó la función fork() para la creacion de un proceso hijo a partir de un proceso padre.

## Funcionalidad

- Se uso getpid() y getppid() para la obtencion de los identificadores de proceso de tanto del hijo como del padre respectivamente.

- Cada proceso padre e hijo tiene su propio y unico PID.

- Se utilizó la función sleep() para evitar que los procesos terminaran simultaneamente.

---

### SALIDA DE La EJECUCIÓN DEL PROGRAMA

justinguevara@j-g:~/Practica3/Ejercicio1_Procesos$ gcc programa.c -o programa

justinguevara@j-g:~/Practica3/Ejercicio1_Procesos$ ./programa

Ejemplo de fork.

Inicio del proceso padre. PID=7863

Continuacion del padre. PID=7863

Inicio del proceso hijo. PID=7864, PPID=7863

Fin del proceso 7864

Fin del proceso 7863

---
