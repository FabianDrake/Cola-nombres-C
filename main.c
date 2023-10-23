#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura de nodo para la cola
struct Nodo {
    char nombre[50];
    struct Nodo* siguiente;
};

struct Nodo* frente = NULL; // Inicializamos la cola como vacía
struct Nodo* final = NULL;  // Inicializamos el puntero al final de la cola

// Función para insertar un elemento en la cola
void encolar(char nombre[]) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: Memoria insuficiente\n");
        exit(1);
    }
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevoNodo;
        final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }

    printf("Nombre '%s' agregado a la cola.\n", nombre);
}

// Función para eliminar un elemento de la cola (el primero que entró)
void desencolar() {
    if (frente == NULL) {
        printf("La cola está vacía.\n");
    } else {
        struct Nodo* temp = frente;
        printf("Nombre '%s' eliminado de la cola.\n", frente->nombre);
        frente = frente->siguiente;
        free(temp);
    }
}

// Función para mostrar todos los nombres en la cola
void mostrar() {
    if (frente == NULL) {
        printf("La cola está vacia.\n");
    } else {
        struct Nodo* actual = frente;
        printf("Nombres en la cola:\n");
        while (actual != NULL) {
            printf("%s\n", actual->nombre);
            actual = actual->siguiente;
        }
    }
}

int main() {
    int eleccion;
    char nombre[50];

    while (1) {
        printf("\n1. Agregar nombre a la cola\n");
        printf("2. Eliminar nombre de la cola\n");
        printf("3. Mostrar nombres en la cola\n");
        printf("4. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &eleccion);

        switch (eleccion) {
            case 1:
                printf("Ingrese un nombre: ");
                scanf("%s", nombre);
                encolar(nombre);
                break;
            case 2:
                desencolar();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                printf("Saliendo del programa.\n");
                exit(0);
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }

    return 0;
}
