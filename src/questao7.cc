#include "questao7.h"

int faztudo_vetor(int colecao[], int tamanho, Operation operacao, int value) {
	int (*func)(int *, int, int);
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

int max(int colecao[], int tamanho, int reference) {
	int maior = colecao[0];
	for(int i = 1; i < tamanho; i++) {
		maior = maior < colecao[i] ? colecao[i] : maior;
	}
	return maior;
}

int min(int colecao[], int tamanho, int reference) {
	int menor = colecao[0];
	for(int i = 1; i < tamanho; i++) {
		menor = menor > colecao[i] ? colecao[i] : menor;
	}
	return menor;
}

int sum(int colecao[], int tamanho, int reference) {
	int result = 0;
	for (int i = 0; i < tamanho; i++) {
		result += colecao[i];
	}	
	return result;
}

int avg(int colecao[], int tamanho, int reference) {
	return sum(colecao, tamanho, 0)/tamanho;
}
int hig(int colecao[], int tamanho, int reference) {
	int count = 0;
	for(int i = 0; i < tamanho; i++) {
		if (colecao[i] > reference) count++;
	}
	return count;
}

int low(int colecao[], int tamanho, int reference) {
	int count = 0;
	for(int i = 0; i < tamanho; i++) {
		if (colecao[i] < reference) count++;
	}
	return count;
}
