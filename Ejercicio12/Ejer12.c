
#include <stdio.h>
#include <omp.h>



void main() {
    int N=0;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &N);

    int f[N];

    // Inicialización de los primeros 2 terminos
    f[0] = 0;
    f[1] = 1;

    #pragma omp parallel shared(f)
    {
        int i;

        for (i = 2; i < N; i++) {
            f[i] = f[i-1] + f[i-2];
        }
    }

    // Imprimir ls serie de fibonaci
    printf("Serie de Fibonacci:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

}
