#include <stdio.h>
#include <stdlib.h>

struct Paciente {
    char nombre[50];
    char apellido[50];
    char telefono[15];
    int edad;
};

int main() {

    FILE *fpointer; 
    struct Paciente paciente;
    char continuar;

    fpointer = fopen("Pacientes.txt", "w");  // Cambiado a modo de texto "w"

    if (fpointer == NULL) {
        fprintf(stderr, "Archivo no encontrado.\n");
        return 1;
    }
    
    do {
        printf("Ingrese nombre: ");
        scanf("%s", paciente.nombre);

        printf("Ingrese apellido : ");
        scanf("%s", paciente.apellido);

        printf("Ingrese telefono : ");
        scanf("%s", paciente.telefono);

        printf("Ingrese edad : ");
        scanf("%d", &paciente.edad);

        fprintf(fpointer, "Nombre: %s\nApellido: %s\nTeléfono: %s\nEdad: %d\n\n",
                paciente.nombre, paciente.apellido, paciente.telefono, paciente.edad);

        printf("¿Desea continuar? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    fclose(fpointer);

    printf("Datos guardados en el archivo Pacientes.txt\n");

    return 0;
}
