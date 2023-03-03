#include <stdio.h>
#include <stdlib.h>
#define p printf
#define s scanf
int main() {
    int i, j, x, y, A, T, opcion;
do{
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
            return 0;
        default:
            p("Opción inválida.\n");
            return 1;
    }
    p("Por favor, introduzca las coordenadas donde quiere la pieza (x,y): ");
    //Originalmente la maquina interpreta ax como el eje de las ordenadas y a y como
	//el eje de las abscisas, es por esto que intercambio el lugar de mis variables x, y para 
	//que no interfiera con la interpretación que le quiero dar de los ejes.
    s("%d %d", &y, &x);
    if (x<1|x>8|y<1|y>8) {
        p("Coordenadas inválidas. Saliendo...\n");
        return 0;
    }
    p("Ha seleccionado la casilla (%d, %d)\n", x, y);
    char tablero[8][8];
    for (i=1;i<9;i++) {
        for(j=1;j<9;j++) {
            tablero[i][j] = '.';
        }
    }
    tablero[x][y] = (opcion == 1) ? 'A' : 'T';
    p("Los movimientos válidos se verían así:\n");
    if (opcion == 1) {
// Alfil
        for(i=1;i<9;i++) {
            for(j=1;j<9;j++) {
                if (abs(x - i) == abs(y - j)) {
                    tablero[i][j] = 'X';
                }
                 tablero[x][y] = (opcion == 1)?'A':'T';
            }
        }
    } else{
// Torre
        for (i=1;i<9;i++) {
            tablero[x][i] = 'X';
            tablero[i][y] = 'X';
        }
        tablero[x][y] = (opcion == 1)?'A':'T';
    }
    for(i=1;i<9;i++) {
        for (j=1;j<9;j++) {
            p("%c   ", tablero[i][j]);
        }
        p("\n");
    }
} while (opcion != 3);
    return 0;
}