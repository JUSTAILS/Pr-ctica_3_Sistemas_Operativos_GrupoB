# Ejercicio 6 - Uso de exec()

Este programa en C crea un proceso hijo usando `fork()` y ejecuta un comando externo (`ls -l`) mediante `execvp()`.

## Explicación breve:
- `fork()` crea un nuevo proceso hijo.
- En el hijo, `execvp()` reemplaza el proceso con el programa indicado.
- El padre espera que el hijo termine con `wait()`.

Autor: Alejandro
