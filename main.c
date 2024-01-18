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
        fflush(stdin);

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
        fflush(stdin);
        printf("\nProducto : ");
        fgets(datos.producto, sizeof(datos.producto), stdin);
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

void listar_productos() {
    int c;

    fpointer = fopen("Productos.txt", "r");

    if (fpointer == NULL) {
        fprintf(stderr, "Archivo no encontrado.\n");
        return;
    }

    while ((c = fgetc(fpointer)) != EOF) {
        if (c == '\n') {
            printf("\n");
        } else {
            putchar(c);
        }
    }

    fclose(fpointer);
}

void eliminar_producto(const char *nombre) {
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
            printf("\n3. Listar");
            printf("\n4. Eliminar");
            printf("\n5. Salir");
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
                    listar_productos();
                    break;

                case 4:
                    printf("\nIngrese el nombre del producto a eliminar: ");
                    scanf("%s", nombre);
                    eliminar_producto(nombre);
                    break;
            }
        } while (opcion != 5);

        return 0;
    }
