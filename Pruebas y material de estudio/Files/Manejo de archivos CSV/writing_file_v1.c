#include <stdio.h>
#include <stdlib.h>

# define NUM_PERSONAJES 3 // Definimos el número de personajes

int main(void) {
    // Datos de ejemplo para los personajes
    const char *personajes[][4] = {
        {"John", "Doe", "123 Main St", "01/01/1980"},
        {"Jane", "Smith", "456 Elm St", "02/02/1990"},
        {"Alice", "Johnson", "789 Oak St", "03/03/1985"}
    };

    // Abre el archivo en modo escritura
    FILE *file = fopen("personajes.csv", "w");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return (-1);
    }

    // Escribe las cabeceras en el archivo
    fprintf(file, "nombre,apellido,dirección,fecha_de_nacimiento\n");

    // Escribe los datos de los personajes en el archivo
    for (int i = 0; i < NUM_PERSONAJES; i++) {
        fprintf(file, "%s,%s,%s,%s\n", personajes[i][0], personajes[i][1], personajes[i][2], personajes[i][3]);
    }

    // Cierra el archivo
    fclose(file);

    printf("Archivo CSV creado con éxito.\n");

    return (0);
}
