#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fd;

struct datosPersonales {
    char nombres[20];
    char apellidos[20];
    char celular[10];
} datos;

void crear() {
    char direccion[] = "C:\\Users\\rjman\\Programacion 1\\menu archivos\\archivo.txt";
    char rpt;

    fd = fopen(direccion, "wt"); // w (write text) - escribir texto

    if (fd == NULL) {
        printf("Error al tratar de crear archivo");
        return;
    }

    printf("\n\t.: Creando Directorio de contactos:.\n");
    fprintf(fd, "\t .:Directorio Telefonico:.\n");

    do {
        fflush(stdin);
        printf("\nNombre : ");
        fgets(datos.nombres, sizeof(datos.nombres), stdin);
        printf("\nApellido : ");
        fgets(datos.apellidos, sizeof(datos.apellidos), stdin);
        printf("\nCelular : ");
        fgets(datos.celular, sizeof(datos.celular), stdin);

        fprintf(fd, "\n\nNombre : %s", datos.nombres);
        fprintf(fd, "\n\nApellido : %s", datos.apellidos);
        fprintf(fd, "\n\nCelular : %s", datos.celular);

        printf("Desea agregar más contactos (s) :");
        scanf(" %c", &rpt);

    } while (rpt == 's');

    fclose(fd);
}

void agregar() {
    char direccion[] = "C:\\Users\\rjman\\Programacion 1\\menu archivos\\archivo.txt";
    char rpt;

    fd = fopen(direccion, "at"); // at (Add text)

    if (fd == NULL) {
        printf("Error al tratar de crear el archivo");
        return;
    }

    do {
        fflush(stdin);
        printf("\nNombre : ");
        fgets(datos.nombres, sizeof(datos.nombres), stdin);
        printf("\nApellido : ");
        fgets(datos.apellidos, sizeof(datos.apellidos), stdin);
        printf("\nCelular : ");
        fgets(datos.celular, sizeof(datos.celular), stdin);

        fprintf(fd, "\n\nNombre : %s", datos.nombres);
        fprintf(fd, "\n\nApellido : %s", datos.apellidos);
        fprintf(fd, "\n\nCelular : %s", datos.celular);

        printf("\n\t.:Agregar más contactos (s) :");
        scanf(" %c", &rpt);

    } while (rpt == 's');

    fclose(fd);
}

void visualizar() {
    int c;
    char direccion[] = "C:\\Users\\rjman\\Programacion 1\\menu archivos\\archivo.txt";

    fd = fopen(direccion, "r");

    if (fd == NULL) {
        printf("Error al tratar de abrir el archivo");
        return;
    }

    while ((c = fgetc(fd)) != EOF) {
        if (c == '\n') {
            printf("\n");
        } else {
            putchar(c);
        }
    }

    fclose(fd);
}

int main() {
    int opc;

    do {
        printf("\n\t.:MENU:.\n");
        printf("\n1. Crear");
        printf("\n2. Agregar");
        printf("\n3. Visualizar");
        printf("\n4. Salir");
        printf("\nOpción : ");
        scanf("%i", &opc);

        switch (opc) {
            case 1:
                crear();
                break;
            case 2:
                agregar();
                break;
            case 3:
                visualizar();
                break;
        }

    } while (opc != 4);

    return 0;
}
