#include <stdio.h>

// Define PAUSE macro
#ifdef _WIN32
    // Code for Windows
    #define PAUSE() system("pause")
#else
    // Code for Linux (and other platforms)
    #define PAUSE() \
        do { \
            printf("Press Enter to continue... \n"); \
            while (getchar() != '\n'); \
        } while (0)
#endif

void funcion(void){
    PAUSE();
}

int main() {
    // Your program logic here

    // Pause the program
    funcion();

    return 0;
}