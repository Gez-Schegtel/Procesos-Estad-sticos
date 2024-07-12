#include<stdio.h>
#include<string.h>

#define MAXCHAR 1000

int main(void){

    FILE *archivo;
    char fila[MAXCHAR];
    char *token;

    archivo = fopen("example.csv","r");

    if (archivo == NULL) {
        perror("Hubo un error al leer el archivo.");
        return(-1);
    }

    while (fgets(fila, MAXCHAR, archivo) != NULL) {
        printf("Estamos leyendo la fila: %s", fila);

        token = strtok(fila, ","); // Tomamos como "token" todo lo que haya justo antes de la coma.

        while(token != NULL) {
            printf("Token: %s\n", token);
            token = strtok(NULL, ",");
        }

    }
    
    return (0);

}
