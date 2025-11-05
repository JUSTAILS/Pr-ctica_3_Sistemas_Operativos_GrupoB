# Ejercicio 3.3.1 - Uso de system()

## Descripción
Programa en C que crea un proceso hijo que utiliza la función `system()` para listar todos los procesos del sistema usando el comando `ps aux`.

## Características
- Uso de `fork()` para crear proceso hijo
- Función `system()` para ejecutar comandos del sistema
- Comando `ps aux` para listar procesos
- Sincronización con `wait()`

## Compilación y Ejecución
```bash
gcc sistema_process.c -o sistema_process
./sistema_process
