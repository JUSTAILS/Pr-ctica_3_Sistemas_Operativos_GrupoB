# Ejercicio 4 - Procesos Padre e Hijos

## Descripción
Programa en C que crea **tres procesos hijos** mediante la función `fork()`.  
Cada proceso hijo ejecuta una tarea distinta:  
- Imprimir los números del 1 al 10.  
- Imprimir los números pares del 2 al 20.  
- Imprimir los números impares del 1 al 19.  

El proceso padre espera la finalización de todos los hijos usando `wait()` y muestra los PID de cada uno al terminar.

## Características
- Uso de `fork()` para crear procesos hijos.  
- Uso de `wait()` para sincronizar la finalización de los hijos.  
- Ejecución de diferentes funciones para cada hijo.  
- Comunicación simple mediante impresión en consola.  

## Compilación y Ejecución
Compila el programa con:

```bash
gcc programa.c -o programa
```

Ejecuta el programa con:

```bash
./programa
```

## Salida esperada
Cada proceso hijo imprime su secuencia numérica y el padre muestra los PID de los hijos al terminar.
