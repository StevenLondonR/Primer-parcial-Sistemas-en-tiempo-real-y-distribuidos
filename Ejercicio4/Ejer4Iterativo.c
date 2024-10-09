
#include <stdio.h>

//Usando la Serie de Leibniz
void calcular_pi_leibniz(double *pi,int num_terminos) {
    int signo = 1;

    for (int i = 0; i < num_terminos; i++) {
        *pi += signo * (4.0 / (2.0 * i + 1.0));
        signo *= -1;  // Alternar signo 
    }

}

void main() {
    int num_terminos;
    double pi=0.0;

    printf("Introduce el número de términos para aproximar pi: ");
    scanf("%d", &num_terminos);

    calcular_pi_leibniz(&pi, num_terminos);

    printf("El valor aproximado de pi con %d términos es: %.15f\n", num_terminos, pi);


}


