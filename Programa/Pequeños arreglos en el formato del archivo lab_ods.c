

#include<stdio.h> // Nos permite invocar a la función `printf()`.
#include<ctype.h> // Nos permite invocar a la función `toupper()`.
#include<stdlib.h> // Nos permite invocar a la función `system()`.
#include <string.h> // Nos permite invocar a la función `strtok()`.
#include <math.h> // Nos permite invocar a la función `round()`.

#define FILAS 34 // Representa a los años, empezando la cuenta desde el 1 y tomando una fila más para los totales.
#define COLUMNAS 36 // Representa a los países, empezando la cuentra desde el 1 y tomando una columna más para los totales.
#define ANIO_MIN 1990 // Año desde donde se tomará en cuenta las estadísticas.
#define ANIO_MAX 2022 // Año hasta donde se tomará en cuenta las estadísticas.
#define MAXCHAR 1000 // Definición del tamaño del buffer cuando se lea el archivo de entrada, necesario para rellenar la matriz.

float matt[FILAS][COLUMNAS];

int x, y, comp1, comp2, pais_user, ann_user;
float val1, val2;
char op, in_cont;

int clean_stdin(void){
    while (getchar() != '\n');
    return(1);
}


void procesar_totales(float matt[FILAS][COLUMNAS]){
    for(x = 0; x <= FILAS-2; x++){
        for(y = 0; y <= COLUMNAS-2; y++){
            matt[FILAS-1][y] = matt[FILAS-1][y] + matt[x][y];
            matt[x][COLUMNAS-1] = matt[x][COLUMNAS-1] + matt[x][y];
            matt[FILAS-1][COLUMNAS-1] = matt[FILAS-1][COLUMNAS-1] + matt[x][y];
        }
    }
}


const char* lista_de_paises(int y){
    switch(y){
        case 0: return "Antigua y Barbuda";
        case 1: return "Argentina";
        case 2: return "Bahamas";
        case 3: return "Barbados";
        case 4: return "Belize";
        case 5: return "Bolivia";
        case 6: return "Brasil";
        case 7: return "Canadá";
        case 8: return "Chile";
        case 9: return "Colombia";
        case 10: return "Costa Rica";
        case 11: return "Cuba";
        case 12: return "Dominica";
        case 13: return "Ecuador";
        case 14: return "El Salvador";
        case 15: return "Estados Unidos";
        case 16: return "Granada";
        case 17: return "Guatemala";
        case 18: return "Guyana";
        case 19: return "Haití";
        case 20: return "Honduras";
        case 21: return "Jamaica";
        case 22: return "México";
        case 23: return "Nicaragua";
        case 24: return "Panamá";
        case 25: return "Paraguay";
        case 26: return "Perú";
        case 27: return "República Dominicana";
        case 28: return "San Cristóbal y Nieves";
        case 29: return "San Vicente y las Granadinas";
        case 30: return "Santa Lucía";
        case 31: return "Surinam";
        case 32: return "Trinidad y Tobago";
        case 33: return "Uruguay";
        case 34: return "Venezuela";
    }
}


int listar_todo(float matt[FILAS][COLUMNAS]){
    /* Esta función está definida como "int" porque en caso de no poder crear el archivo que escribirá, devuelve el valor entero "-1". */
	
    FILE *archivo_salida;
    archivo_salida = fopen("listado_completo.txt", "w");
    
    if (archivo_salida == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return (-1);
    }

    for(y = 0; y <= COLUMNAS-2; y++){
        const char* pais = lista_de_paises(y);
        for(x = 0; x <= FILAS-2; x++){
            printf("Año >> %d | País >> %s | Emisiones de CO2 per cápita (metrics tons per cápita) >> %.4f\n", ANIO_MIN+x, pais, matt[x][y]); 

            fprintf(archivo_salida, "Año >> %d | País >> %s | Emisiones de CO2 per cápita (metrics tons per cápita) >> %.4f\n", ANIO_MIN+x, pais, matt[x][y]);
        }
        printf("Total de emisiones en %s >> %.4f\n\n", pais, matt[FILAS-1][y]);

        fprintf(archivo_salida, "Total de emisiones en %s >> %.4f\n\n", pais, matt[FILAS-1][y]);
    }
    printf("Total de emisiones en el Continente Americano >> %.4f\n", matt[FILAS-1][COLUMNAS-1]);
    printf("\nEl informe completo de todas estas estadísticas han sido grabadas en el archivo 'listado_completo.txt', bajo el mismo directorio del programa.\n");

    fprintf(archivo_salida, "Total de emisiones en el Continente Americano >> %.4f\n", matt[FILAS-1][COLUMNAS-1]);

    fclose(archivo_salida);
}


void listar_totales(float matt[FILAS][COLUMNAS]){
    for(x = 0; x <= FILAS-2; x++){
        printf("Emisiones totales de CO2 en el año %d >> %.4f\n", ANIO_MIN+x, matt[x][COLUMNAS-1]);
    }

    for(y = 0; y <= COLUMNAS-2; y++){
        const char* pais = lista_de_paises(y);
        printf("Emisiones totales de CO2 de %s >> %.4f\n", pais, matt[FILAS-1][y]);
    }
}


void pais_menorymayor(float matt[FILAS][COLUMNAS]){
    int men, may;
    float res_men = 100000000;
    float res_may = 0;

    for(y = 0; y <= COLUMNAS-2; y++){

        if (matt[FILAS-1][y] < res_men){
            men = y;
            res_men = matt[FILAS-1][y];
        } else {
            if (matt[FILAS-1][y] > res_may){
                may = y;
                res_may = matt[FILAS-1][y];
            }
        }
    }
    const char* pais_men = lista_de_paises(men);
    const char* pais_may = lista_de_paises(may);
    printf("El país con menores emisiones de CO2 per cápita (metrics tons per cápita) es %s con >> %.4f\n", pais_men, matt[FILAS-1][men]);
    printf("El país con mayores emisiones de CO2 per cápita (metrics tons per cápita) es %s con >> %.4f\n", pais_may, matt[FILAS-1][may]);
}


int ingresar_pais(void){
    printf("Indique el país según la denominación a continuación...\n");

    for(y = 0; y <= COLUMNAS-2; y++){
        const char* pais = lista_de_paises(y);
        printf("%s >> %d\n", pais, y+1);
    }

    printf("\n>> ");

    if(((scanf("%d%c", &pais_user, &in_cont) != 2 || in_cont != '\n') && clean_stdin()) || pais_user < 1 || pais_user > COLUMNAS-1){
        system("clear");
        printf("Ha ingresado un valor incorrecto.\n");
        ingresar_pais();
	}
    return(pais_user);
}


void e_pais_user(float matt[FILAS][COLUMNAS]){
    ingresar_pais();
    system("clear");

    const char* pais = lista_de_paises(pais_user-1);
    printf("El número de emisiones de %s es >> %.4f\n", pais, matt[FILAS-1][pais_user-1]);
}


int ingresar_ann(void){
    printf("Indique el año que desee evaluar desde el %d al %d, ingresando el año completo (4 dígitos) \n\n>> ", ANIO_MIN, ANIO_MAX);

    if(((scanf("%d%c", &ann_user, &in_cont) != 2 || in_cont != '\n') && clean_stdin()) || ann_user < ANIO_MIN || ann_user > ANIO_MAX){
        system("clear");
        printf("Ha ingresado un valor incorrecto.\n");
        ingresar_ann();
	}
    return(ann_user);
}


void e_ann_user(float matt[FILAS][COLUMNAS]){
    ingresar_ann();
    system("clear");
    printf("El número de emisiones del año %d es >> %.4f\n", ann_user, matt[ann_user-ANIO_MIN][COLUMNAS-1]);
}


void comp_paises(float matt[FILAS][COLUMNAS]){
    printf("Ingrese dos países que desee comparar.");

    comp1 = ingresar_pais()-1;
    val1 = matt[FILAS-1][pais_user-1];

    comp2 = ingresar_pais()-1;
    val2= matt[FILAS-1][pais_user-1];

    const char* pais_comp1 = lista_de_paises(comp1);
    const char* pais_comp2 = lista_de_paises(comp2);

    system("clear");
	
    if(val1 > val2){
        printf("%s posee un número mayor de emisiones que %s con %.4f y %.4f, respectivamente.\n", pais_comp1, pais_comp2, val1, val2);
    } else
        if(val1 < val2){
            printf("%s posee un número mayor de emisiones que %s con %.4f y %.4f, respectivamente.\n", pais_comp2, pais_comp1, val2, val1);
        } else {
            printf("Ha ingresado el mismo país. %s posee un número de emisiones de %.4f\n", pais_comp1, val1);
        }
}


void comp_ann(float matt[FILAS][COLUMNAS]){
    comp1 = ingresar_ann() - ANIO_MIN;
    comp2 = ingresar_ann() - ANIO_MIN;

    if(matt[comp1][COLUMNAS-1] > matt[comp2][COLUMNAS-1]){
        printf("En el año %d hubo mayores emisiones de CO2 con respecto a %d con %.4f y %.4f, respectivamente.\n", comp1+ANIO_MIN, comp2+ANIO_MIN, matt[comp1][COLUMNAS-1], matt[comp2][COLUMNAS-1]);
    } else
        if(matt[comp1][COLUMNAS-1] < matt[comp2][COLUMNAS-1]){
            printf("En el año %d hubo mayores emisiones de CO2 con respecto a %d con %.4f y %.4f, respectivamente.\n", comp2+ANIO_MIN, comp1+ANIO_MIN, matt[comp2][COLUMNAS-1], matt[comp1][COLUMNAS-1]);
        } else {
            printf("Se han seleccionado dos años iguales. En el año %d hubo %.4f emisones de CO2.\n", comp1+ANIO_MIN, matt[comp1][COLUMNAS-1]);
        }
}


char menu(void){
    printf("\nSeleccione una opción: \n");
    printf("1- Listar todos los países, por año y con sus respectivos totales.\n");
    printf("2- Listar los totales, por país y año.\n");
    printf("3- Listar el país con menor y mayor número de emisiones en total.\n");
    printf("4- Ingresar un país para conocer su número total de emisiones.\n");
    printf("5- Ingresar un año para conocer su número total de emisiones.\n");
    printf("6- Ingresar dos países para realizar una comparación acerca de sus emisiones.\n");
    printf("7- Ingresar dos años para realizar una comparación acerca de sus emisiones.\n");
    printf("8- Detener la ejecución del programa.\n\n>> ");
    scanf("%s", &op);

    if(op == '8'){
        exit(0);
    }

    if(!(op >= '1' && op <= '7')){
        system("clear");
        printf("Ha ingresado una opción incorrecta.\n");
        printf("Por favor, ingrese un valor del 1 al 8\n");
        op = menu();
    }
    system("clear");
    return(op);
}


char pregunta(void){
    printf("\nIngrese >> s << para realizar otra operación.");
    printf("\nIngrese >> n << para detener la ejecución del programa.\n\n>> ");
    scanf("%s", &op);
    op = toupper(op);

    if(op != 'S' && op != 'N'){
        system("clear");
        printf("Ha ingresado un dato erróneo.");
        op = pregunta();
    }
    system("clear");
    return(op);
}


void inicio(void){
    printf("\nIngrese >> s << para iniciar el programa.\n");
    printf("Ingrese >> n << para detener la ejecución del programa.\n\n>> ");
    scanf("%s", &op);
    op = toupper(op);

    if(op != 'S' && op != 'N'){
        system("clear");
        printf("\nHa ingresado un dato erróneo.\n");
        inicio();
    }

    system("clear");
    if(op == 'N'){
        exit(0);
    }
}


int cargar_matriz(void){
    /* Esta función está definida como `int` porque en caso de no poder abrir el archivo de entrada, devuelve -1. */

    FILE *archivo_entrada;
    archivo_entrada = fopen("co-emissions-per-capita-in-america(1990-2022).csv", "r");

    if (archivo_entrada == NULL) {
        perror("Hubo un error al leer el archivo.");
        return (-1);
    }

    char fila[MAXCHAR];
    char *token;
    int x = 0;

    // Leer y descartar la primera línea (encabezados)
    fgets(fila, MAXCHAR, archivo_entrada);

    while (fgets(fila, MAXCHAR, archivo_entrada) != NULL) {
        token = strtok(fila, ",");
        int y = 0;

        while (token != NULL) {
            matt[x][y] = round(atof(token) * 10000) / 10000; // Este cálculo nos asegura de que se almacenen solamente los primeros cuatro dígitos decimales de los números.
            token = strtok(NULL, ",");
            y++;
        }
        x++;
    }
    fclose(archivo_entrada);
}


int main(void){
    system("clear");
    inicio();
    cargar_matriz();
    procesar_totales(matt);

    do{
        op = menu();

        switch(op){
            case '1': listar_todo(matt); break;
            case '2': listar_totales(matt); break;
            case '3': pais_menorymayor(matt); break;
            case '4': e_pais_user(matt); break;
            case '5': e_ann_user(matt); break;
            case '6': comp_paises(matt); break;
            case '7': comp_ann(matt); break;
        }

        pregunta();

    }while(op != 'N');

    return(0);
}
