#include "questao8.h"

double faztudo_vetor(double colecao[], int tamanho, Operation operacao, double value) {
	double (*func)(double *, int, double);
	switch (operacao) {
		case OP_MAX:
			func = max;
			break;
		case OP_MIN:
			func = min;
			break;
		case OP_SUM:
			func = sum;
			break;
		case OP_AVG:
			func = avg;
			break;
		case OP_HIG:
			func = hig;
			break;
		case OP_LOW:
			func = low;
			break;
	}
	func(colecao, tamanho, value);
}

double max(double colecao[], int tamanho, double reference) {
	double maior = colecao[0];
	for(int i = 1; i < tamanho; i++) {
		maior = maior < colecao[i] ? colecao[i] : maior;
	}
	return maior;
}

double min(double colecao[], int tamanho, double reference) {
	double menor = colecao[0];
	for(int i = 1; i < tamanho; i++) {
		menor = menor > colecao[i] ? colecao[i] : menor;
	}
	return menor;
}

double sum(double colecao[], int tamanho, double reference) {
	double result = 0.0;	
	for (int i = 0; i < tamanho; i++){
		result+=colecao[i];
	}
	return result;
}

double avg(double colecao[], int tamanho, double reference) {
	return sum(colecao, tamanho, 0.0)/tamanho;
}
double hig(double colecao[], int tamanho, double reference) {
	int count = 0;
	for(int i = 0; i < tamanho; i++) {
		if (colecao[i] > reference) count++;
	}
	return count;
}

double low(double colecao[], int tamanho, double reference) {
	int count = 0;
	for(int i = 0; i < tamanho; i++) {
		if (colecao[i] < reference) count++;
	}
	return count;
}
