//https://github.com/lautaroronga-u/Trabajos-practicos.git
#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int cuantas_piezas(int);
int rectificable(float, float);
int rechazada(float, float);
void cargar_piezas(float *, int);
int contar(int (*)(float, float), float, float *, int);
float* reserva_memoria(int);
void segregar(int (*)(float, float), float, float *, int, float *);
void mostrar_piezas(char *mensaje, float *p, int n) ;

int main (void) {
	float diametros[TAM] = {0};
	int n;
	float max = 12;
	float min = 10;
	
	n = cuantas_piezas(TAM);
	cargar_piezas(diametros, n);
	
	int n_rectificar = contar(rectificable, max, diametros, n);
	float *p_rectificables = reserva_memoria(n_rectificar);
	segregar(rectificable, max, diametros, n, p_rectificables);
	
	int n_rechazar = contar(rechazada, min, diametros, n);
	float *p_rechazadas = reserva_memoria(n_rechazar);
	segregar(rechazada, min, diametros, n, p_rechazadas);
	
	mostrar_piezas("rectificables", p_rectificables, n_rectificar);
	mostrar_piezas("rechazadas", p_rechazadas, n_rechazar);
	
	free(p_rectificables);
	free(p_rechazadas);
	
	return 0;
}

int cuantas_piezas(int max) {
	int n;
	do {
		printf("Cuántas piezas ingresará? ");
		scanf("%d", &n);
	} while (n < 0 || n > max);
	return n;
}

int rectificable(float diametro, float valor) {
	if (diametro > valor)
		return 1;
	else
		return 0;
}

int rechazada(float diametro, float valor) {
	if (diametro < valor)
		return 1;
	else
		return 0;
}

void cargar_piezas(float *p, int n) {
	int i = 0;
	float val;
	while (i < n) {
		printf("Ingrese diámetro de pieza %d: ", i);
		scanf("%f", &val);
		if (val <= 0) {
			printf("Error: El diámetro debe ser un número positivo.\n");
		} else {
			*(p + i) = val;
			i++;
		}
	}
}

int contar(int (*criterio)(float, float), float valor, float *p, int n) {
	int cantidad = 0;
	for (int i = 0; i < n; i++) {
		if (criterio(*(p + i), valor)) {
			cantidad++;
		}
	}
	return cantidad;
}

float* reserva_memoria(int n) {
	if (n <= 0) {
		return NULL;
	}
	float *ptr = (float *) malloc(n * sizeof(float));
	if (ptr == NULL) {
		printf("Error: No se pudo reservar memoria.\n");
		exit(1);
	}
	return ptr;
}

void segregar(int (*criterio)(float, float), float valor, float *p, int n, float *q) {
	if (q == NULL) return;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (criterio(*(p + i), valor)) {
			*(q + j) = *(p + i);
			j++;
		}
	}
}

void mostrar_piezas(char *mensaje, float *p, int n) {
	printf("Piezas %s:\n", mensaje);
	for (int i = 0; i < n; i++) {
		printf("Diámetro: %.2f\n", *(p + i));
	}
}
