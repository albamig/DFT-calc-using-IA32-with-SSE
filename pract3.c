// Desarrollado por Sergio Delgado y Alberto Amigo

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAM 1024
#define ANGULO(j, k) (((-2*M_PI)/TAM)*(j)*(k)) 

void dftc();
void dftsse();
void imprime_resul();
void genera_num();

double val_complex[TAM][2];
double res_complex[TAM][2];

int main() {
	genera_num();
	clock_t ini_c, fin_c, ini_sse, fin_sse;

	// Calculo de la DFT en ANSI C
	ini_c = clock();
	dftc();
	fin_c = clock();

	imprime_resul();

	// Calculo de la  DFT en IA32
	ini_sse = clock();
	dftsse();
	fin_sse = clock();

	// imprime_resul(); // Descomentar esta linea para comprobar que el cálculo es correcto

	printf ("Resutado C: %f\nResultado SSE: %f\n", ((double)fin_c-ini_c)/CLOCKS_PER_SEC, ((double)fin_sse-ini_sse)/CLOCKS_PER_SEC);

	return 0;
}

void dftc() {
	int i, j;

	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			res_complex[i][0] += val_complex[j][0] * cos(ANGULO(i, j)) - val_complex[j][1] * sin(ANGULO(i, j));
			res_complex[i][1] += val_complex[j][0] * sin(ANGULO(i, j)) + val_complex[j][1] * cos(ANGULO(i, j));
		}
	}
}

void imprime_resul() {
	int i;

	for (i = 0; i < TAM; i++) {
		printf("Indice: %d \t|\t Numero: %lf%+lfi \t|\t Transformada: %lf%+lfi\n", 
				i, val_complex[i][0], val_complex[i][1], res_complex[i][0], res_complex[i][1]);
	}
}

void genera_num() {
	int i;

	srand48(time(NULL));
	for (i = 0; i < TAM; i++) {
	 	val_complex[i][0] = (drand48() * 100) - 50;
		val_complex[i][1] = (drand48() * 100) - 50;
	}
}
