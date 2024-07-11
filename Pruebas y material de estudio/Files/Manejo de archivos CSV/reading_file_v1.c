#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAXCHAR 1000 // Tamaño máximo del arreglo que contendrá los datos de cada fila. Muchas veces llamado "buffer".

int main(void){

    FILE *file; // `FILE` (así, en mayúsculas) es un tipo de dato. `*file` es una puntero que puede contener a una variable del tipo de dato `FILE`. 
    char row[MAXCHAR]; // Arreglo de caracteres que contendrá los datos de cada fila del archivo POR CADA ITERACIÓN (esto es, se sobreescribe lo que tenga guardado, y se almacena lo que se obtiene en la iteración actual en la que esté). Lo necesitamos para poder leer el mismo fila por fila.

    file = fopen("example.csv","r"); /* Ver descripción de esta línea debajo, a partir de la línea 22. */
	
    while (feof(file) != true) { /* Ver descripción a partir de la línea 26. */
        fgets(row, MAXCHAR, file); // ... almacenamos cada fila en el arreglo...
        printf("Row: %s", row); // ... y leemos su contenido.
    }
    
    return (0); // Fin del programa.
}

/*
    El puntero `file` no tiene el archivo completo en memoria, sino que es una referencia a esta estructura que permite a las funciones de la biblioteca estándar de C realizar operaciones de entrada/salida en el archivo.
*/

/*
    Se desaconseja utilizar la función `feof` dentro de un bucle. En este programa, esto genera el error de que se lee una línea de más. Este puede error se puede generar cuando al final del archivo de entrada hay un salto de línea. Esto provoca que se en la anteúltima fila no se detecte el fin del archivo, se itera por lo tanto una vez más (llegando al fin a la última línea, donde sólo está el salto) imprime lo que quedó en "buffer" (que es la anteúltima línea) y ahí recién es cuando termina el programa. Esto produce que se repita la en pantalla la duplicación en la escritura de la última línea "real" de información.

    Sacado de "StackOverflow":https://stackoverflow.com/questions/27463126/reading-from-file-and-exiting-loop-using-feof

    «If your text file ends without a newline after the last line of text, the testUnsafe() function will reach end-of-file when it reads the last line, and produce the three lines of output you have shown.

    If your text file does have a newline after the last line of text, the function will read the last line, including the newline, without reaching end-of-file. When it enters the while() loop again, it reads zero characters, sets the end-of-file flag, and outputs the last line which is still in the buffer from the last round.

    The while (!feof(f)) construction is not unsafe in itself. It's neglecting to check the return value of fgets() that is unsafe.
    »
*/