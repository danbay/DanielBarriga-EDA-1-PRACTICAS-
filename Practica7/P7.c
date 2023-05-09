#include <stdio.h>
#include <stdlib.h>

// definición de la estructura de un nodo de la lista ligada circular
struct Nodo {
    int valor;
    struct Nodo* siguiente;
};

// función para insertar un nuevo nodo al final de la lista ligada circular
void insertar(struct Nodo** cabeza, int valor) {
    // se crea un nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    // si la lista está vacía, se establece el nuevo nodo como cabeza y se enlaza consigo mismo
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        return;
    }

    // se busca el último nodo de la lista
    struct Nodo* ultimo = (*cabeza)->siguiente;
    while (ultimo->siguiente != *cabeza) {
        ultimo = ultimo->siguiente;
    }

    // se enlaza el nuevo nodo al final de la lista y se enlaza consigo mismo
    ultimo->siguiente = nuevoNodo;
    nuevoNodo->siguiente = *cabeza;
}

// función para imprimir la lista ligada circular
void imprimir(struct Nodo* cabeza) {
    // si la lista está vacía, se muestra un mensaje
    if (cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    // se recorre la lista desde la cabeza y se muestra cada valor
    printf("Lista ligada circular: ");
    struct Nodo* actual = cabeza;
    do {
        printf("%d ", actual->valor);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("\n");
}

// función para buscar un valor en la lista ligada circular
void buscar(struct Nodo* cabeza, int valorBuscado) {
    // si la lista está vacía, se muestra un mensaje y se termina la función
    if (cabeza == NULL) {
        printf("La lista esta vacia. No se puede buscar el valor.\n");
        return;
    }

    // se recorre la lista desde la cabeza y se compara cada valor con el valor buscado
    struct Nodo* actual = cabeza;
    do {
        if (actual->valor == valorBuscado) {
            printf("El valor %d fue encontrado en la lista.\n", valorBuscado);
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    // si se llega al final de la lista sin encontrar el valor, se muestra un mensaje
    printf("El valor %d no fue encontrado en la lista.\n", valorBuscado);
}

// función principal del programa
int main() {
    // se crea una lista ligada circular con valores predefinidos
    struct Nodo* cabeza = NULL;
    insertar(&cabeza, 1);
    insertar(&cabeza, 3);
    insertar(&cabeza, 5);
    insertar(&cabeza, 7);
    insertar(&cabeza, 9);

    // se imprime la lista ligada circular
    imprimir(cabeza);

    // se pide al usuario que introduzca un valor para buscar
    int valorBuscado;
    printf("Introduce un valor para buscar en la lista: ");
    scanf("%d", &valorBuscado);

    // se busca el valor introducido por el usuario en la lista ligada circular
    buscar(cabeza, valorBuscado);

    // se imprime la lista ligada circular nuevamente para cotejar si se encontró el valor o no
    imprimir(cabeza);

    return 0;
}
