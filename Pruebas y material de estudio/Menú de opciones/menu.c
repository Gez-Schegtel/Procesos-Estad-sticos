#include <stdio.h> // For `printf()`
#include <ctype.h> // For `tolower()`
#include <string.h> // For `strcmp()`
#include <stdlib.h> // For `exit()`

void menuOpciones(void){
    char respuesta[2];

    while(1){
        printf("Ingrese la letra C para continuar hasta el próximo proceso. \n");
        printf("Ingrese la letra F para continuar hasta el último proceso. \n");
        printf("Ingrese la letra S para salir. \n>> ");
        scanf("%s", respuesta);
        while (getchar() != '\n'); /* Limpiamos el buffer para evitar bucles infinitos. */
        
        /* Convertir la respuesta a minúsculas para hacer la comparación no sensible a mayúsculas. '\0' es el caracter NULL que indica el fin de un string. */
        for (int i = 0; respuesta[i] != '\0'; i++) {
            respuesta[i] = tolower(respuesta[i]);
        }
    
        if (strcmp(respuesta, "c") == 0){
            printf("\nContinuamos.");
        } else {
            if (strcmp(respuesta, "f") == 0){
                printf("\nHacemos un salto de tiempo.");
            } else {
                if (strcmp(respuesta, "s") == 0){
                    printf("Salimos.\n");
                    exit(1);
                } else {
                    printf("\nHas ingresado un valor incorrecto.");
                }
            }
        }
        printf("\n\n");
    }
}

int main(void) {

    menuOpciones();

    return(0);
}