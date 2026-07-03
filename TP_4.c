#include <stdio.h>

int main() {
	float calificacion;
	
	printf("Ingrese la calificación: ");
	scanf("%f", &calificacion);
	
	if (calificacion >= 90) {
		printf("Calificación: A\n");
	} else if (calificacion >= 80) {
		printf("Calificación: B\n");
	} else if (calificacion >= 70) {
		printf("Calificación: C\n");
	} else if (calificacion >= 60) {
		printf("Calificación: D\n");
	} else {
		printf("Calificación: F\n");
	}
	
	return 0;
}
