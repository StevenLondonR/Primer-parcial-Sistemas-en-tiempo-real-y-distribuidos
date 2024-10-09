
#include <stdio.h>

// Usando la Serie de Leibniz
void calcular_pi_leibniz_recursivo(double *pi, int termino_actual, int num_terminos) {
    if (termino_actual >= num_terminos) {
        return;
	
    }

	    // Alternar signo
	    double signo = (termino_actual % 2 == 0) ? 1.0 : -1.0;

	    // Calcular el valor del término actual
	    *pi += signo * (4.0 / (2.0 * termino_actual + 1.0));
	    calcular_pi_leibniz_recursivo(pi, termino_actual + 1, num_terminos);
}

void main() {
    int num_terminos;
    double pi=0.0;

    printf("Introduce el número de términos para aproximar pi: ");
    scanf("%d", &num_terminos);

    calcular_pi_leibniz_recursivo(&pi, 0, num_terminos);

    printf("El valor aproximado de pi con %d términos es: %.15f\n", num_terminos, pi);

}

