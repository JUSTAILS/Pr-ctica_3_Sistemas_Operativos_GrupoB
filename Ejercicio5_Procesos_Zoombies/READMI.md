# Ejercicio 5 - Procesos Zoombies

## Descripción

Este ejercicio fue diseñado para demostrar la creación de un proceso zombie en un sistema operativo tipo Unix. Se implementó un programa en C que utiliza la función fork() para crear un hijo. El objetivo es forzar una situación donde el proceso hijo termina su ejecución, pero el proceso padre (su responsable) no lee su estado de salida, dejando al hijo en un estado de "no-muerto" (Zombie) en la tabla de procesos.

## Funcionalidad

- Creación de Procesos: Se usó la función fork() para dividir el programa en un Proceso Padre y un Proceso Hijo.

- Muerte del Hijo: El proceso hijo es programado para terminar inmediatamente usando exit(0);.

- El Padre Desinteresado: El proceso padre utiliza la función sleep(60); para suspender su ejecución durante 60 segundos. Crucialmente, el padre no invoca a wait() ni a waitpid() antes de dormir.

- El Resultado (Zombie): Al morir el hijo y no ser "recogido" por el padre (que está durmiendo), el sistema operativo lo etiqueta con el estado Z (Zombie) hasta que el padre despierte y termine (o sea forzado a recogerlo).

---

### COMPILACIÓN Y EJECUCIÓN DEL PROGRAMA

gcc programa.c -o programa

./programa

Proceso Hijo. PID = 16839

Proceso Padre. PID = 16838

---
