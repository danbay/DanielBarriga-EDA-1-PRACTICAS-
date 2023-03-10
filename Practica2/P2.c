#include <stdio.h>

// Declaración de funciones
void imprimir_tablero(char (*tablero)[8]);
void actualizar_tablero(char (*tablero)[8], int x, int y, char pieza);

// Función principal
int main() {
    char tablero[8][8];
    int opcion,i=0, j=0;
    do {
        printf("Seleccione una opcion:\n");
        printf("1.- Reina\n");
        printf("2.- Rey\n");
        printf("3.- Salir\n");
        scanf("%d", &opcion);
        if(opcion == 1 || opcion == 2) {
            int x, y;
            printf("Ingrese la coordenada x: ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y: ");
            scanf("%d", &y);
            if(x < 1 || x > 8 || y < 0 || y > 8) {
                printf("Coordenadas invalidas.\n");
            }
            else {
                for(i=0;i<8;i++) {
                    for(j=0;j<8;j++) {
                        *(*(tablero + i) + j) = '.';
                    }
                }
                if(opcion == 1) {
                    actualizar_tablero(tablero, y-1, x-1, 'Q');
                }
                else {
                    actualizar_tablero(tablero, y-1, x-1, 'R');
                }
                imprimir_tablero(tablero);
            }
        }
    } while(opcion != 3);
    return 0;
}

// Función para imprimir el tablero
void imprimir_tablero(char (*tablero)[8]) {
    int i=0, j=0;
    printf("\n   1 2 3 4 5 6 7 8\n");
    printf("  -----------------\n");
    for(i=0;i<8;i++){
        printf("%d |", i+1);
        for(j=0; j<8; j++) {
            printf("%c|", *(*(tablero + i) + j));
        }
        printf("\n");
        printf("  -----------------\n");
    }
}

// Función para actualizar el tablero con la pieza seleccionada y sus movimientos válidos
void actualizar_tablero(char (*tablero)[8], int x, int y, char pieza) {
    int i=0, j=0;
    *(*(tablero + x) + y) = pieza;
    for(i=0;i<8;i++) {
        for(j=0;j<8;j++) {
            if((i == x || j == y || i-j == x-y || i+j == x+y) && !(i == x && j == y)) {
                if(pieza == 'R' && (i-x)*(i-x)+(j-y)*(j-y) <= 2*2) {
                    *(*(tablero + i) + j) = 'X';
                }
                else if(pieza == 'Q' && (i == x || j == y || i-j == x-y || i+j == x+y)) {
                    *(*(tablero + i) + j) = 'X';
                }
            }
        }
    }
}