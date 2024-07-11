
/*
    Realizamos una carga de diversos personajes a un archivo CSV, con los datos que el usuario quiera ingresar para cada uno.

    En este código se demuestra también la forma más segura de ingresar datos desde una terminal.

    La única diferencia entre esta versión y la versión v2 es que aquí existe la posibilidad de dar a elegir al usuario el nombre del archivo de salida.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000

int main(void) {
    // Variables para almacenar los datos ingresados por el usuario
    char nombre[MAXCHAR];
    char apellido[MAXCHAR];
    char direccion[MAXCHAR];
    char fecha_nacimiento[MAXCHAR];
    char respuesta[MAXCHAR];
    char nombre_archivo[MAXCHAR];

    puts("Ingrese el nombre del archivo en el que desee añadir sus personajes:");
    fgets(nombre_archivo, MAXCHAR, stdin); // stdin es una abreviatura de "standard input"
    nombre_archivo[strcspn(nombre_archivo, "\n")] = '\0'; // Eliminamos el salto de línea. El caracter '\0' es el caracter NULL. Nótese que tiene que ir con comillas simples porque se trata de un caracter. Si se usan dobles, el compilador arrojará un «warning». En cambio, como la función strcspn (string complementary span) "espera" un string como entrada, sí es necesario ingresar el salto de línea (\n) con comillas dobles.


    // Abre el archivo en modo escritura
    FILE *file = fopen(nombre_archivo, "w");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return (-1);
    }

    // Escribe las cabeceras en el archivo
    fprintf(file, "nombre,apellido,dirección,fecha_de_nacimiento\n");

    // Bucle para ingresar datos de los usuarios
    do {
        // Solicita los datos del usuario
        printf("Ingrese el nombre: ");
        fgets(nombre, MAXCHAR, stdin);
        nombre[strcspn(nombre, "\n")] = '\0'; // Elimina el salto de línea. 

        printf("Ingrese el apellido: ");
        fgets(apellido, MAXCHAR, stdin);
        apellido[strcspn(apellido, "\n")] = '\0'; // Elimina el salto de línea

        printf("Ingrese la dirección: ");
        fgets(direccion, MAXCHAR, stdin);
        direccion[strcspn(direccion, "\n")] = '\0'; // Elimina el salto de línea

        printf("Ingrese la fecha de nacimiento (dd/mm/yyyy): ");
        fgets(fecha_nacimiento, MAXCHAR, stdin);
        fecha_nacimiento[strcspn(fecha_nacimiento, "\n")] = '\0'; // Elimina el salto de línea

        // Escribe los datos en el archivo
        fprintf(file, "%s,%s,%s,%s\n", nombre, apellido, direccion, fecha_nacimiento);

        // Pregunta si desea agregar otra fila
        printf("¿Desea agregar otra fila? (si/no): ");
        fgets(respuesta, MAXCHAR, stdin);
        respuesta[strcspn(respuesta, "\n")] = '\0'; // Elimina el salto de línea

    } while (strcmp(respuesta, "si") == 0);

    // Cierra el archivo
    fclose(file);

    printf("\nArchivo CSV creado con éxito.\n");

    return (0);
}
