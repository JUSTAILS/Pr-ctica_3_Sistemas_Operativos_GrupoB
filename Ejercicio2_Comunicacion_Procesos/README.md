# Ejercicio 2 - Comunicación entre Procesos

## Descripción
Programa en C que demuestra la comunicación entre procesos padre e hijo usando memoria compartida. El proceso padre incrementa una variable en pasos de 10, mientras que el proceso hijo registra cada valor en un archivo de texto.

## Funcionalidad
- Uso de `fork()` para creación de procesos
- Memoria compartida con `shmget()`, `shmat()`, `shmdt()`
- Sincronización entre procesos
- Manejo de archivos con `fopen()`, `fprintf()`

## Compilación y Ejecución
```bash
gcc programa.c -o programa
./programa
cat valores.txt
