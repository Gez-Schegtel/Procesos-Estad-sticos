#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define FILAS 34
#define COLUMNAS 36
#define MAXCHAR 1000

int main(void) {
    FILE *archivo;
    archivo = fopen("co-emissions-per-capita-in-america(1990-2022).csv", "r");

    if (archivo == NULL) {
        perror("Hubo un error al leer el archivo.");
        return (-1);
    }

    char fila[MAXCHAR];
    char *token;
    float matriz[FILAS][COLUMNAS];
    int x = 0;

    // Leer y descartar la primera línea (encabezados)
    fgets(fila, MAXCHAR, archivo);

    while (fgets(fila, MAXCHAR, archivo) != NULL) {
        printf("Estamos leyendo la fila: %s", fila);

        token = strtok(fila, ",");
        int y = 0;

        while (token != NULL) {
            matriz[x][y] = round(atof(token) * 10000) / 10000; // Este cálculo nos asegura de que se almacenen solamente los primeros cuatro dígitos decimales de los números.
            printf("Token: %s\n", token);
            token = strtok(NULL, ",");
            y++;
        }
        x++;
    }

    fclose(archivo);

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%.4f  ", matriz[i][j]); // Acá se indica que se tienen que imprimir por pantalla únicamente los primeros cuatro dígitos decimales. Recordar que, por más que hayan sólo cuatro, C imprimirá un montón de dígitos decimales (los escribe con varios ceros). 
        }
        printf("\n\n");
    }

    return (0);
}
