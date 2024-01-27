#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 1000
#define chunk 20
#define imprimir 30

void imprimeArreglo(float *d);

int main(int argc, char *argv[]) {
	printf("Sumando Arreglos en Paralelo! \n");

	// Utilizar una semilla diferente para obtener valores aleatorios diferentes cada vez
	srand((unsigned int)time(NULL));

	float a[N], b[N], c[N];
	int i;

	// Inicialización de arreglos con valores aleatorios
	for (i = 0; i < N; i++) {
		a[i] = rand() % 100;
		b[i] = rand() % 100;
	}

	int  secciones= chunk;

#pragma omp parallel for shared(a, b, c, secciones) private(i) schedule(static, secciones)
	for (i = 0; i < N; i++) {
		c[i] = a[i] + b[i];
	}

	printf("Imprimiendo los primeros %d valores del arreglo a: \n", imprimir);
	imprimeArreglo(a);
	printf("Imprimiendo los primeros %d valores del arreglo b: \n", imprimir);
	imprimeArreglo(b);
	printf("Imprimiendo los primeros %d valores del arreglo c: \n", imprimir);
	imprimeArreglo(c);

	return 0;
}

void imprimeArreglo(float *d) {
	for (int x = 0; x < imprimir; x++) {
		printf(" %f - ", d[x]);
	}
	printf("\n");
}