
#include <stdio.h>
#include <mpi.h>
#include <string.h>

void main(int argc, char** argv) {
    int rank, size;
    char cadena[] = "Hola , como estas";  // Cadena
    int longitud = strlen(cadena); // Longitud de la cadena


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    if (rank == 0) {
        

        for (int i = 0; i < longitud; i++) {
            if (i % 2 == 0) {
                // Posiciones pares para el procesador 1
                MPI_Send(&cadena[i], 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
            } else {
                // Posiciones impares para el procesador 2
                MPI_Send(&cadena[i], 1, MPI_CHAR, 2, 0, MPI_COMM_WORLD);
            }
        }

        
        char end = '\0'; // Caracter de terminacion
        MPI_Send(&end, 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&end, 1, MPI_CHAR, 2, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        // El procesador 1 recibe e imprime las posiciones pares
        char ch;
        while (1) {
            MPI_Recv(&ch, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            if (ch == '\0') break; // Terminar cuando recibe el carácter de terminación
            printf("Procesador 1 (posiciones pares): %c\n", ch);
        }
    } else if (rank == 2) {
        // El procesador 2 recibe e imprime las posiciones impares
        char ch;
        while (1) {
            MPI_Recv(&ch, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            if (ch == '\0') break; // Terminar cuando recibe el carácter de terminación
            printf("Procesador 2 (posiciones impares): %c\n", ch);
        }
    }

    MPI_Finalize();
}


