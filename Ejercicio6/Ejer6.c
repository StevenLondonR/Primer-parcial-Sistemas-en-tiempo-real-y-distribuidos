
#include <stdio.h>

void fibonacci(int n) {
    int f[n];

    f[0] = 0;
    f[1] = 1;


    for (int i = 2; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    // Imprimir Fibonacci
    printf("Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");
}

void main() {
    int n;

    printf("Ingrese la cantidad de términos de Fibonacci que a calcular: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("El número de términos debe ser mas de 2.\n");
    } else {
        fibonacci(n);
    }

}
