#include "questao5.h"

double somatorio(int vetor[], int n) {
	double soma = 0.0;	
	for (int i=0; i < n; i++) {
		soma += vetor[i];
	}
	return soma;
}

double somatorio(int vetor[], int n, int x, int y) {
	double soma = 0.0;	
	for (int i=0; i < n; ) {
		soma += ((double) vetor[i])/(++i*x-y);
	}
	return soma;
}
