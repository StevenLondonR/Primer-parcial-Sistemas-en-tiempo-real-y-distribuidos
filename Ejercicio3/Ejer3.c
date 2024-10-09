

#include <stdio.h>

void suma(int *a, int *b, int *resultado){
	*resultado = *a + *b;
}

void resta(int *a, int *b, int *resultado){
	*resultado = *a - *b;
}

void mult(int *a, int *b, int *resultado){
	*resultado = *a * *b;
}

void divc(int *a, int *b, int *resultado){
	*resultado = *a / *b;
}


void main(){

	while(1){
		printf("\n");
		printf("Se realizaran las operaciones de suma, resta, multiplicacion y division de 2 numeros: \n");
		printf("\n");
		int num1=0;
		int num2=0;
		int resultado=0;

		printf("Ingrese el primer numero: ");
		scanf("%d", &num1);
		while(getchar() != '\n'); // Limpiar el buffer
		printf("\n");
		printf("Ingrese el segundo numero: ");
		scanf("%d", &num2);
    		while(getchar() != '\n'); // Limpiar el buffer
		printf("\n");
		int op=0;
		
		printf("Que operacion deseaa realizar ( Elija una opcion ): \n");
		printf("1: Suma \n");
		printf("2: Resta \n");
		printf("3: Multiplicacion \n");
		printf("4: Division \n");
		printf("5: Salir \n");
		
		printf("Opcion: ");
		scanf("%d",&op);
		while(getchar() != '\n');
		printf("\n");

		printf("El resultado de la operacion es: \n");
		if(op == 1){
			suma(&num1, &num2, &resultado);
			printf("%d+%d = %d \n", num1, num2,resultado);
		}else if(op == 2){
			resta(&num1, &num2, &resultado);
			printf("%d-%d = %d \n", num1,num2,resultado);
		}else if(op == 3){
			mult(&num1, &num2, &resultado);
			printf("%d*%d = %d \n", num1, num2, resultado);
		}else if(op == 4){
			if(num2!=0){
				divc(&num1, &num2, &resultado);
				printf("%d/%d = %d \n", num1, num2, resultado);
			}else{
				printf("No se puede dividir entre 0: %d/%d \n", num1, num2);
			}
		}else if(op == 5){
			printf("Saliendo \n");
			break;
		}else{
			printf("No existe esta opcion: %d \n", op);
		}


	}

}




