#include <stdio.h>
#include <stdlib.h>

#define p printf
#define s scanf

int main() {
    int i, j, x, y, A, T, opcion;
    char **tablero;

    // Asignación dinámica de memoria para el tablero
    tablero = (char **) malloc(sizeof(char*) * 8);
    for (i = 0; i < 8; i++) {
        tablero[i] = (char *) malloc(sizeof(char) * 8);
    }

    do {
        p("Bienvenido al programa de ajedrez\n");
        p("Menú de opciones:\n");
        p("1. Alfil\n");
        p("2. Torre\n");
        p("3. Salir\n");
        p("Elija una opcion: ");
        s("%d", &opcion);

        switch (opcion) {
            case 1:
                p("Ha seleccionado el alfil.\n");
                break;
            case 2:
                p("Ha seleccionado la torre.\n");
                break;
            case 3:
                p("Ha seleccionado salir.\n");
                break;
            default:
                p("Opción inválida.\n");
                return 1;
        }

        if (opcion == 3) {
            break;
        }

        p("Por favor, introduzca las coordenadas donde quiere la pieza (x,y): ");
        s("%d %d", &y, &x);

        if (x < 1 || x > 8 || y < 1 || y > 8) {
            p("Coordenadas inválidas. Saliendo...\n");
            return 0;
        }

        p("Ha seleccionado la casilla (%d, %d)\n", y, x);

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                tablero[i][j] = '.';
            }
        }

        tablero[x - 1][y - 1] = (opcion == 1) ? 'A' : 'T';

        p("Los movimientos válidos se verían así:\n");

        if (opcion == 1) {
            // Alfil
            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (abs(x - i - 1) == abs(y - j - 1)) {
                        tablero[i][j] = 'X';
                    }
                }
            }
        } else {
            // Torre
            for (i = 0; i < 8; i++) {
                tablero[x - 1][i] = 'X';
                tablero[i][y - 1] = 'X';
            }
        }

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                p("%c   ", tablero[i][j]);
            }
            p("\n");
        }

    } while (opcion != 3);

    // Liberación de la memoria asignada
    for (i = 0; i < 8; i++) {
        free(tablero[i]);
    }
    free(tablero);

    return 0;
}