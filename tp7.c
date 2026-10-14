#include <stdio.h>
//https://github.com/lautaroronga-u/Trabajos-practicos.git
#define TAM 5

int main() {
	long int codigos[TAM];
	float precios[TAM];
	int i;
	int pos_mayor = 0;
	int pos_menor = 0;
	
	printf("Ingrese %d productos, se solicitara el codigo y precio:\n", TAM);
	
	for (i = 0; i < TAM; i++) {

		do {
			printf("Ingrese el codigo de barras (1-999999999): ");
			if (scanf("%ld", &codigos[i]) != 1) {
				while (getchar() != '\n');
				codigos[i] = -1;
			}
			
			if (codigos[i] < 1 || codigos[i] > 999999999) {
				printf("Error. El codigo de barras debe estar entre 1 y 999999999\n");
			}
		} while (codigos[i] < 1 || codigos[i] > 999999999);
		
		do {
			printf("Ingrese el precio: ");
			if (scanf("%f", &precios[i]) != 1) {
				while (getchar() != '\n');
				precios[i] = -1.0f; 
			}
			
			if (precios[i] < 0) {
				printf("Error. El precio no puede ser negativo\n");
			}
		} while (precios[i] < 0);
	}
	
	for (i = 1; i < TAM; i++) {
		if (precios[i] > precios[pos_mayor]) {
			pos_mayor = i;
		}
		if (precios[i] < precios[pos_menor]) {
			pos_menor = i;
		}
	}
	
	printf("\nCodigo\tPrecio\n");
	for (i = 0; i < TAM; i++) {
		printf("%8ld\t%.2f\n", codigos[i], precios[i]);
	}

	printf("\nMas caro: [%ld] %.2f\n", codigos[pos_mayor], precios[pos_mayor]);
	printf("Mas barato: [%ld] %.2f\n", codigos[pos_menor], precios[pos_menor]);
	
	return 0;
}
