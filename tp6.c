#include <stdio.h>

#define PI 3.14159265358979323846


float calcularAreaRectangulo(float longitud, float altura) {
	return longitud * altura;
}

float calcularPerimetroRectangulo(float longitud, float altura) {
	return 2 * (longitud + altura);
}

float calcularAreaCirculo(float radio) {
	return 3.14 * radio * radio;
}

float calcularPerimetroCirculo(float radio) {
	return 2 * 3.14 * radio;
}

void imprimirResultados(float area, float perimetro) {
	printf("El área es: %.2f\n", area);
	printf("El perímetro es: %.2f\n", perimetro);
}

int main() {
	int opcion;
	float longitud, altura, radio;
	float area, perimetro;
	
	do {
		printf("Ingrese la figura que desea calcular (1: rectángulo, 2: círculo): ");
		if (scanf("%d", &opcion) != 1) {
			while (getchar() != '\n');
			opcion = 0;
		}
		
		if (opcion != 1 && opcion != 2) {
			printf("Opción inválida. Intente nuevamente.\n\n");
		}
	} while (opcion != 1 && opcion != 2);
	
	if (opcion == 1) {
		printf("Opción de rectángulo seleccionada\n");
		
		printf("Ingrese la longitud del rectángulo: ");
		scanf("%f", &longitud);
		
		printf("Ingrese la altura del rectángulo: ");
		scanf("%f", &altura);
	
		area = calcularAreaRectangulo(longitud, altura);
		perimetro = calcularPerimetroRectangulo(longitud, altura);
		
	} else {
		printf("Opción de círculo seleccionada\n");
		
		printf("Ingrese el radio del círculo: ");
		scanf("%f", &radio);
	
		area = calcularAreaCirculo(radio);
		perimetro = calcularPerimetroCirculo(radio);
	}
	
	imprimirResultados(area, perimetro);
	
	return 0;
}
