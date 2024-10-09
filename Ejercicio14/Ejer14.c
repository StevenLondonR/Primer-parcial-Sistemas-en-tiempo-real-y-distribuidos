
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 3  // Tamaño de las matrices (NxN)

void main(int argc, char* argv[]) {
    int rank, size;
    int matrixA[N][N], matrixB[N][N], result[N][N];
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    if (rank == 0) {  // Procesador 0: Maestro
        
        printf("Matrices A y B: \n");

        // Matrix A
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrixA[i][j] = i + j + 1;  
            }
        }

        // Matrix B
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrixB[i][j] = (i == j) ? 1 : 0; 
            }
        }

        // Mostrar Matrices A y B
        printf("Matriz A:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", matrixA[i][j]);
            }
            printf("\n");
        }

        printf("Matriz B:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", matrixB[i][j]);
            }
            printf("\n");
        }

        // Distribuir filas de Matrix A los procesadores  1 y 2
        for (int p = 1; p < size; p++) {
            MPI_Send(matrixA[p - 1], N, MPI_INT, p, 0, MPI_COMM_WORLD);
        }

        // Enviar Matrix B completa a los procesadores 1 y 2
        for (int p = 1; p < size; p++) {
            MPI_Send(matrixB, N * N, MPI_INT, p, 1, MPI_COMM_WORLD);
        }

        // Matriz resultante
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] = 0;
            }
        }

        // Recibir resultados de los Procesadores 1 y 2
        for (int p = 1; p < size; p++) {
            MPI_Recv(result[p - 1], N, MPI_INT, p, 2, MPI_COMM_WORLD, &status);
        }

        // Mostrar la matriz resultante
        printf("Resultado de la multiplicación (A x B):\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    else {  // Procesadores 1 y 2: Cálculo de filas
        int rowA[N];
        int matrixB_received[N][N];
        int rowResult[N];

        // Recibir una fila de Matrix A
        MPI_Recv(rowA, N, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        // Recibir Matrix B completa
        MPI_Recv(matrixB_received, N * N, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        // Realizar la multiplicación de la fila
        for (int j = 0; j < N; j++) {
            rowResult[j] = 0;
            for (int k = 0; k < N; k++) {
                rowResult[j] += rowA[k] * matrixB_received[k][j];
            }
        }

        // Enviar el resultado de la fila de vuelta al Procesador 0
        MPI_Send(rowResult, N, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}


