#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAM 1024
#define PI 3.14
#define ANGULO(j, k) (((-2*PI)/TAM)*(j)*(k)) 

void dftc();
double dftsse();
void imprime_resul();

double val_complex[TAM][2];
double res_complex[TAM][2];

int main() {
	int i;
	srand48(time(NULL));
	for (i = 0; i < TAM; i++) {
		val_complex[i][0] = (drand48() * 100) - 50;
		val_complex[i][1] = (drand48() * 100) - 50;
	}
	time_t inicioa, finala, iniciob, finalb;
	
	inicioa = time(NULL);
	dftc();
	finala = time(NULL);
	//double enc = difftime (final, inicio);
	imprime_resul();
	iniciob = time(NULL);
	dftsse();
	finalb = time(NULL);
printf("%llu\n", (unsigned long long)inicioa);
printf("%llu\n", (unsigned long long)finala);
printf("%llu\n", (unsigned long long)iniciob);
printf("%llu\n", (unsigned long long)finalb);
	//printf("%f, %f\n", difftime (final, inicio), enc);
	//imprime_resul();

	return 0;
}

void dftc() {
	int i, j;
	double res_real, res_imagin;

	for (i = 0; i < TAM; i++) {
		res_real = 0;
		res_imagin = 0;

		for (j = 0; j < TAM; j++) {
			res_real += val_complex[j][0] * cos(ANGULO(i, j)) - val_complex[j][1] * sin(ANGULO(i, j));
			res_imagin += val_complex[j][0] * sin(ANGULO(i, j)) + val_complex[j][1] * cos(ANGULO(i, j));
		}

		res_complex[i][0] = res_real;
		res_complex[i][1] = res_imagin;
	}
}

void imprime_resul() {
	int i;

	for (i = 0; i < TAM; i++) {
		printf("Indice: %d \t|\t Numero: %lf%+lfi \t|\t Transformada: %lf%+lfi\n", 
				i, val_complex[i][0], val_complex[i][1], res_complex[i][0], res_complex[i][1]);
	}
}
