# Ejercicio 3.1.3 - Creación de proceso hijo sin espera

## Descripción
Programa en C que crea un proceso hijo y responde preguntas sobre la relación padre-hijo, evitando que el proceso quede huérfano.

## Código Modificado
Se modificó el código original agregando `wait(0)` en el proceso padre para evitar que el hijo quede huérfano.

## Respuestas a las Preguntas

### a) ¿Cuál es el PID del proceso padre del proceso hijo creado?
 El PPID del proceso hijo será igual al PID del proceso padre que se muestra en la ejecución. En este caso, el PPID del hijo (92149) es 92148, que es el PID del padre.

### b) Verifique a qué proceso corresponde el ID encontrado.
 Corresponde al proceso padre que ejecutó este programa.

### c) ¿Cómo se denomina al tipo de proceso hijo?
 Se denomina **"proceso hijo huérfano"** (orphan process) cuando el padre termina antes que el hijo. En este código modificado, el hijo NO queda huérfano.

### d) Modificación para evitar hijo huérfano
 Se agregó `wait(0);` en el caso `default` (proceso padre) para que espere a que el hijo termine antes de finalizar.

## Compilación y Ejecución
```bash
gcc proceso_hijo.c -o proceso_hijo
./proceso_hijo
