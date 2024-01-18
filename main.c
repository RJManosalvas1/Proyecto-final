#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fpointer;

struct Producto {
    char producto[50];
    int cantidad;
    int precio;
} datos;

void ingresar_productos() {
    struct Producto producto;
    char continuar;

    fpointer = fopen("Productos.txt", "a");

    if (fpointer == NULL) {
        fprintf(stderr, "Archivo no encontrado.\n");
        return;
    }

    printf("\n\t--Creando lista de productos.--\n");
    fprintf(fpointer, "\t --Lista de productos--\n");

    do {
        printf("Ingrese producto: ");
        scanf("%s", producto.producto);

        printf("Ingrese cantidad : ");
        scanf("%d", &producto.cantidad);

        printf("Ingrese precio : ");
        scanf("%d", &producto.precio);

        fprintf(fpointer, "Producto: %s\nCantidad: %d\nPrecio: %d\n\n",
                producto.producto, producto.cantidad, producto.precio);

        printf("¿Desea continuar? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    fclose(fpointer);

    printf("Datos guardados en el archivo Productos.txt\n");
}

void agregar_productos() {
    char continuar;

    fpointer = fopen("Productos.txt", "a");

    if (fpointer == NULL) {
        fprintf(stderr, "Archivo no encontrado.\n");
        return;
    }

    do {
        printf("\nProducto : ");
        scanf("%s", datos.producto);
        getchar();  // Consumir el carácter de nueva línea pendiente

        printf("\nCantidad : ");
        scanf("%d", &datos.cantidad);

        printf("\nPrecio : ");
        scanf("%d", &datos.precio);

        fprintf(fpointer, "\n\nProducto : %s", datos.producto);
        fprintf(fpointer, "\n\nCantidad : %d", datos.cantidad);
        fprintf(fpointer, "\n\nPrecio : %d", datos.precio);

        printf("\n\t.:Agregar más productos (s/n) :");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    fclose(fpointer);
}

void editar_productos(const char *nombre) {
    FILE *Editados;
    int c;
    int found = 0;

    fpointer = fopen("Productos.txt", "r");
    Editados = fopen("editados.txt", "w");

    if (fpointer == NULL || Editados == NULL) {
        fprintf(stderr, "Error al abrir archivos.\n");
        return;
    }

    while ((c = fgetc(fpointer)) != EOF) {
        if (c == '\n') {
            char buffer[50];
            fgets(buffer, sizeof(buffer), fpointer);

            if (strstr(buffer, nombre) == NULL) {
                fprintf(Editados, "\n%s", buffer);
            } else {
                found = 1;

                printf("\nNuevo valor para la cantidad: ");
                scanf("%d", &datos.cantidad);

                printf("Nuevo valor para el precio: ");
                scanf("%d", &datos.precio);

                fprintf(Editados, "\n\nProducto : %s", nombre);
                fprintf(Editados, "\n\nCantidad : %d", datos.cantidad);
                fprintf(Editados, "\n\nPrecio : %d", datos.precio);
            }
        } else {
            putchar(c);
        }
    }

    fclose(fpointer);
    fclose(Editados);

    remove("Productos.txt");
    rename("editados.txt", "Productos.txt");

    if (found) {
        printf("\nProducto editado exitosamente.\n");
    } else {
        printf("\nProducto no encontrado.\n");
    }
}


void listar_productos() {
    fpointer = fopen("Productos.txt", "r");

    if (fpointer == NULL) {
        fprintf(stderr, "Archivo no encontrado.\n");
        return;
    }

    printf("\n\t-- Lista de Productos --\n");

    char buffer[100];
    fflush(stdin);

    while (fgets(buffer, sizeof(buffer), fpointer) != NULL) {
        printf("%s", buffer);
    }

    fclose(fpointer);
}

void eliminar_productos(const char *nombre) {
    FILE *Eliminados;
    int c;
    int found = 0;

    fpointer = fopen("Productos.txt", "r");
    Eliminados = fopen("temp.txt", "w");

    if (fpointer == NULL || Eliminados == NULL) {
        fprintf(stderr, "Error al abrir archivos.\n");
        return;
    }

    while ((c = fgetc(fpointer)) != EOF) {
        if (c == '\n') {
            char buffer[50];
            fgets(buffer, sizeof(buffer), fpointer);

            if (strstr(buffer, nombre) == NULL) {
                fprintf(Eliminados, "\n%s", buffer);
            } else {
                found = 1;
            }
        } else {
            putchar(c);
        }
    }

    fclose(fpointer);
    fclose(Eliminados);

    remove("Productos.txt");
    rename("temp.txt", "Productos.txt");

    if (found) {
        printf("\nProducto eliminado exitosamente.\n");
    } else {
        printf("\nProducto no encontrado.\n");
    }
}

int main() {
    int opcion;
    char nombre[50];

    do {
        printf("\n\t--MENU--\n");
        printf("\n1. Crear");
        printf("\n2. Agregar");
        printf("\n3. Editar");
        printf("\n4. Listar");
        printf("\n5. Eliminar");
        printf("\n6. Salir");
        printf("\nOpción : ");
        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                ingresar_productos();
                break;

            case 2:
                agregar_productos();
                break;

            case 3:
                printf("\nIngrese el nombre del producto a editar: ");
                scanf("%s", nombre);
                editar_productos(nombre);
                break;

            case 4:
                listar_productos();
                break;

            case 5:
                printf("\nIngrese el nombre del producto a eliminar: ");
                scanf("%s", nombre);
                eliminar_productos(nombre);
                break;
        }
    } while (opcion != 6);

    return 0;
}
