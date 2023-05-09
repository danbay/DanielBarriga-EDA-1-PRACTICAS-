#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura nodo
struct Nodo {
  int dato;
  struct Nodo *anterior;
  struct Nodo *siguiente;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
  struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->anterior = NULL;
  nuevoNodo->siguiente = NULL;
  return nuevoNodo;
}

// Función para agregar un nodo al inicio de la lista
void agregarInicio(struct Nodo** cabeza, int dato) {
  struct Nodo* nuevoNodo = crearNodo(dato);
  if (*cabeza == NULL) {
    nuevoNodo->siguiente = nuevoNodo;
    nuevoNodo->anterior = nuevoNodo;
    *cabeza = nuevoNodo;
  } else {
    nuevoNodo->siguiente = *cabeza;
    nuevoNodo->anterior = (*cabeza)->anterior;
    (*cabeza)->anterior->siguiente = nuevoNodo;
    (*cabeza)->anterior = nuevoNodo;
    *cabeza = nuevoNodo;
  }
}

// Función para agregar un nodo al final de la lista
void agregarFinal(struct Nodo** cabeza, int dato) {
  struct Nodo* nuevoNodo = crearNodo(dato);
  if (*cabeza == NULL) {
    nuevoNodo->siguiente = nuevoNodo;
    nuevoNodo->anterior = nuevoNodo;
    *cabeza = nuevoNodo;
  } else {
    nuevoNodo->anterior = (*cabeza)->anterior;
    nuevoNodo->siguiente = *cabeza;
    (*cabeza)->anterior->siguiente = nuevoNodo;
    (*cabeza)->anterior = nuevoNodo;
  }
}

// Función para agregar un nodo en una posición específica de la lista
void agregarEnPosicion(struct Nodo** cabeza, int dato, int posicion) {
  struct Nodo* nuevoNodo = crearNodo(dato);
  if (*cabeza == NULL) {
    nuevoNodo->siguiente = nuevoNodo;
    nuevoNodo->anterior = nuevoNodo;
    *cabeza = nuevoNodo;
  } else {
    struct Nodo* actual = *cabeza;
    int i = 1;
    while (i < posicion && actual->siguiente != *cabeza) {
      actual = actual->siguiente;
      i++;
    }
    if (i == posicion) {
      nuevoNodo->siguiente = actual->siguiente;
      nuevoNodo->anterior = actual;
      actual->siguiente->anterior = nuevoNodo;
      actual->siguiente = nuevoNodo;
    } else {
      printf("La posición no existe en la lista.\n");
    }
  }
}

// Función para eliminar el primer nodo de la lista
void eliminarInicio(struct Nodo** cabeza) {
  if (*cabeza == NULL) {
    printf("La lista está vacía.\n");
  } else if ((*cabeza)->siguiente == *cabeza) {
    free(*cabeza);
    *cabeza = NULL;
  } else {
    struct Nodo* temp = *cabeza;

(*cabeza)->siguiente->anterior = (*cabeza)->anterior;
(*cabeza)->anterior->siguiente = (*cabeza)->siguiente;
*cabeza = (*cabeza)->siguiente;
free(temp);
}
}

// Función para eliminar el último nodo de la lista
void eliminarFinal(struct Nodo** cabeza) {
if (*cabeza == NULL) {
printf("La lista está vacía.\n");
} else if ((*cabeza)->siguiente == *cabeza) {
free(*cabeza);
cabeza = NULL;
} else {
struct Nodo *temp = (*cabeza)->anterior;
(*cabeza)->anterior = (*cabeza)->anterior->anterior;
(*cabeza)->anterior->siguiente = *cabeza;
free(temp);
}
}

// Función para eliminar un nodo en una posición específica de la lista
void eliminarEnPosicion(struct Nodo** cabeza, int posicion) {
if (cabeza == NULL) {
printf("La lista está vacía.\n");
} else {
struct Nodo *actual = *cabeza;
int i = 1;
while (i < posicion && actual->siguiente != *cabeza) {
actual = actual->siguiente;
i++;
}
if (i == posicion) {
actual->anterior->siguiente = actual->siguiente;
actual->siguiente->anterior = actual->anterior;
if (actual == *cabeza) {
*cabeza = actual->siguiente;
}
free(actual);
} else {
printf("La posición no existe en la lista.\n");
}
}
}

// Función para imprimir la lista desde el inicio
void imprimirDesdeInicio(struct Nodo* cabeza) {
if (cabeza == NULL) {
printf("La lista está vacía.\n");
} else {
struct Nodo* actual = cabeza;
do {
printf("%d ", actual->dato);
actual = actual->siguiente;
} while (actual != cabeza);
}
printf("\n");
}


// Función para imprimir la lista desde el final
void imprimirDesdeFinal(struct Nodo* cabeza) {
if (cabeza == NULL) {
printf("La lista está vacía.\n");
} else {
struct Nodo* actual = cabeza->anterior;
do {
printf("%d ", actual->dato);
actual = actual->anterior;
} while (actual != cabeza->anterior);
printf("\n");
}
}

int main() {
struct Nodo* cabeza = NULL;
int opcion = 0;
int dato = 0;
int posicion = 0;

// Valores iniciales de la lista
agregarInicio(&cabeza, 3);
agregarFinal(&cabeza, 5);
agregarFinal(&cabeza, 7);
agregarFinal(&cabeza, 9);

while (opcion != 7) {
printf("\nMenú de opciones:\n");
printf("1. Agregar un elemento al inicio de la lista\n");
printf("2. Agregar un elemento al final de la lista\n");
printf("3. Agregar un elemento en una posición específica de la lista\n");
printf("4. Eliminar el primer elemento de la lista\n");
printf("5. Eliminar el último elemento de la lista\n");
printf("6. Eliminar un elemento en una posición específica de la lista\n");
printf("7. Salir del programa\n");
printf("Ingrese la opción que desea realizar: ");
scanf("%d", &opcion);

switch (opcion) {
  case 1:
    printf("Ingrese el dato que desea agregar al inicio de la lista: ");
    scanf("%d", &dato);
    agregarInicio(&cabeza, dato);
    printf("Se agregó el elemento %d al inicio de la lista.\n", dato);
    printf("La lista actual es: ");
    imprimirDesdeInicio(cabeza);
    break;
  case 2:
    printf("Ingrese el dato que desea agregar al final de la lista: ");
    scanf("%d", &dato);
    agregarFinal(&cabeza, dato);
    printf("Se agregó el elemento %d al final de la lista.\n", dato);
    printf("La lista actual es: ");
    imprimirDesdeInicio(cabeza);
    break;
  case 3:
    printf("Ingrese el dato que desea agregar: ");
    scanf("%d", &dato);
    printf("Ingrese la posición donde desea agregar el elemento: ");
    scanf("%d", &posicion);
    agregarEnPosicion(&cabeza, dato, posicion);
    printf("Se agregó el elemento %d en la posición %d de la lista.\n", dato, posicion);
    printf("La lista actual es: ");
    imprimirDesdeInicio(cabeza);
    break;
  case 4:
    eliminarInicio(&cabeza);
    printf("Se eliminó el primer elemento de la lista.\n");
    printf("La lista actual es: ");
    imprimirDesdeInicio(cabeza);
    break;
  case 5:
    eliminarFinal(&cabeza);
    printf("Se eliminó el último elemento de la lista.\n");
    printf("La lista actual es: ");
    imprimirDesdeInicio(cabeza);
    break;
  case 6:
    printf("Ingrese la posición del elemento que desea eliminar: ");
    scanf("%d", &posicion);
    eliminarEnPosicion(&cabeza, posicion);
    printf("Se eliminó el elemento en la posición %d de la lista.\n", posicion);
    printf("La lista actual es: ");
    imprimirDesdeInicio(cabeza);
    break;
  case 7:
    printf("Saliendo del programa...\n");
    break;
  default:
    printf("Opción inválida. Ingrese una opción válida.\n");
    break;
}
}

return 0;
}