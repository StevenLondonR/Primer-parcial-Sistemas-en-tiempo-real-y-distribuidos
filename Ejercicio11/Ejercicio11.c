
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10  // Tamaño de los vectores

void main(int argc, char* argv[]) {
    int rank, size;
    int vector1[] = {1,2,3,4,5,6,7,8,9,10};
    int vector2[] = {1,2,3,4,5,6,7,8,9,10};

    int  result1[N];
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {  // Maestro
        

        // Enviar vectores a Procesadores 1 y 2
        // Enviar a Procesador 1 (impares)
        for (int i = 1; i < N; i += 2) {
            int nums[2] = {vector1[i], vector2[i]};
            MPI_Send(nums, 2, MPI_INT, 1, i, MPI_COMM_WORLD);
        }

        // Enviar a Procesador 2(pares)
        for (int i = 0; i < N; i += 2) {
            int data[2] = {vector1[i], vector2[i]};
            MPI_Send(data, 2, MPI_INT, 2, i, MPI_COMM_WORLD);
        }

        // Vector resultante
        for (int i = 0; i < N; i++) {
            result1[i] = 0;
        }

        // Recibir resultados de los procesadores  1 y 2
        // Procesador 1 (impares)
        for (int i = 1; i < N; i += 2) {
            int sum;
            MPI_Recv(&sum, 1, MPI_INT, 1, i, MPI_COMM_WORLD, &status);
            result1[i] = sum;
        }

        // Procesador 2  (pares)
        for (int i = 0; i < N; i += 2) {
            int sum;
            MPI_Recv(&sum, 1, MPI_INT, 2, i, MPI_COMM_WORLD, &status);
            result1[i] = sum;
        }

       	
	printf("Vector1 :\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", vector1[i]);
        }
	printf("\n");

	
	printf("Vector 2:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", vector2[i]);
        }
	printf("\n");
	
	
	

        printf("Resultado de la suma de los vectores:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", result1[i]);
        }
        printf("\n");
    }
    else if (rank == 1) {  // Procesador 1: impares
        for (int i = 1; i < N; i += 2) {
            int data[2];
            MPI_Recv(data, 2, MPI_INT, 0, i, MPI_COMM_WORLD, &status);
            int sum = data[0] + data[1];
            MPI_Send(&sum, 1, MPI_INT, 0, i, MPI_COMM_WORLD);
        }
    }
    else if (rank == 2) {  // Procesador 2: pares
        for (int i = 0; i < N; i += 2) {
            int data[2];
            MPI_Recv(data, 2, MPI_INT, 0, i, MPI_COMM_WORLD, &status);
            int sum = data[0] + data[1];
            MPI_Send(&sum, 1, MPI_INT, 0, i, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
}



