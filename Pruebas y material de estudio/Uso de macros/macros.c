#include <stdio.h>

#ifdef _WIN32
    // Definir una macro específica para Windows
    #define SISTEMA "Windows"
    #define MENSAJE "Estás en un sistema Windows"
#elif __linux__
    // Definir una macro específica para Linux
    #define SISTEMA "Linux"
    #define MENSAJE "Estás en un sistema Linux"
#else
    // Definir una macro por defecto si no estamos en Windows ni Linux
    #define SISTEMA "Desconocido"
    #define MENSAJE "Sistema operativo desconocido"
#endif

int main() {
    printf("%s\n", MENSAJE);
    return 0;
}