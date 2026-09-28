#include <stdio.h>

int main() {
	float peso, altura, imc;
		
	printf("Ingrese el peso en kg: ");
	scanf("%f", &peso);
	
	printf("Ingrese la altura en metros: ");
	scanf("%f", &altura);
	
	imc = peso / (altura * altura);
	
	printf("\nSu indice de masa corporal es: %.2f\n\n", imc);
	
	if (imc >= 30) {
		printf("Obesidad\n");
	} else if (imc >= 25) {
		printf("Sobrepeso\n");
	} else if (imc >= 18.5) {
		printf("Normal\n");
	} else {
		printf("Bajo peso\n");
	}
	return 0;
}
