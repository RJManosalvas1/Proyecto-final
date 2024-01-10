#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fpointer;

struct Producto {
    char producto[50];
    int cantidad;
    int precio;
};

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

int main() {
    int opc;
    do {
        printf("\n\t--MENU--\n");
        printf("\n1. Crear");
        printf("\n2. Agregar");
        printf("\n3. Visualizar");
        printf("\n4. Salir");
        printf("\nOpción : ");
        scanf("%i", &opc);

        switch (opc) {
            case 1:
                ingresar_productos();
                break;
        
            case 2:
                
                break;
            case 3:
              
                break;
        }
    } while (opc != 4);

    return 0;
}
