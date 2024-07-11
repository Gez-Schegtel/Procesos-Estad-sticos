
/* Versión alternativa a "reading_file.c". 

	Prefiero esta versión porque es más segura, ya que se encarga de cerrar el arhivo, da un mensaje de error más detallado si el archivo no pudo ser abierto y, lo más importante, es que se desaconseja utilizar `feof` en el ciclo `While` (como lo hace la versión anterior) porque puede ocasionar errores cuando el archivo CSV termine con un salto de línea `\n`.

	Para más información acerca de esto último, podés consultar el siguiente link: https://stackoverflow.com/questions/27463126/reading-from-file-and-exiting-loop-using-feof

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 1000 // Tamaño máximo del arreglo que contendrá los datos de cada fila. Muchas veces llamado "buffer".

int main(void) {
    FILE *file; // `FILE` (así, en mayúsculas) es un tipo de dato. `*file` es una puntero que puede contener a una variable del tipo de dato `FILE`. 
    char row[MAXCHAR]; // Arreglo de caracteres que contendrá los datos de cada fila del archivo POR CADA ITERACIÓN (esto es, se sobreescribe lo que tenga guardado, y se almacena lo que se obtiene en la iteración actual en la que esté). Lo necesitamos para poder leer el mismo fila por fila.

    file = fopen("example.csv", "r"); // La función fopen abre el archivo "example.csv" en modo lectura ("r"). Si la apertura es exitosa, fopen devuelve un puntero a una estructura FILE que representa el archivo abierto. La dirección de esta estructura FILE es lo que se asigna al puntero file.
   
    if (file == NULL) { // Se comprueba si resultó exitosa la apertura del archivo. En caso de no ser así, se termina el programa devolviendo el mensaje de error que hayas escrito en perror.
        perror("Error al abrir el archivo");
        return (-1);
    }

    while (fgets(row, MAXCHAR, file) != NULL) { /* Ver explicación en línea 34. */
        printf("%s", row);
    }

    fclose(file); // Cerramos el archivo.
    return (0); // Terminó el programa sin errores.
}

/*
El ciclo while (fgets(row, MAXCHAR, fp) != NULL) es una forma común en C de leer un archivo línea por línea hasta llegar al final del archivo (EOF). Vamos a desglosar cómo funciona este ciclo:

Componentes del ciclo

    1. fgets(row, MAXCHAR, fp):
        - row: Es un puntero a un buffer donde fgets almacenará la línea leída.
        
        - MAXCHAR: Especifica el tamaño máximo del buffer (incluyendo el carácter nulo \0).
        
        - fp: Es un puntero a un archivo abierto (de tipo FILE).
    
        La función fgets lee una línea del archivo apuntado por fp y la almacena en row. La lectura se detiene cuando se ha leído MAXCHAR - 1 caracteres, cuando se encuentra un carácter de nueva línea (\n), o cuando se alcanza el final del archivo (EOF), lo que ocurra primero.

    2. Condición del ciclo while:
        - fgets devuelve un puntero: Si la lectura es exitosa, fgets devuelve el puntero row. Si se alcanza el final del archivo o ocurre un error de lectura fgets devuelve NULL.
        
        - != NULL: El ciclo continúa mientras fgets no devuelva NULL. Esto significa que el ciclo se ejecutará para cada línea leída correctamente.

    3. Cuerpo del ciclo:
        - printf("%s", row): Imprime la línea leída. El formato %s en printf imprime una cadena de caracteres, y row contiene la línea leída por fgets.
*/