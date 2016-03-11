#include <cmath>

#include "questao1.h"

// Esfa função é um exemplo de recursividade simples
double soma_sequencia_harmonica_r(int n) {
	// passo base soma_sequencia_harmonica(0) => 0
	if (n < 1) return 0;
	return 1.0/n + soma_sequencia_harmonica_r(n -1);
}

// Esta função é um exemplo de recursividade simples
double soma_sequencia_b_r(int n) {
	// passo base soma_sequencia_b(0) => 0
	if (n < 1) return 0;
	return (pow((double) n, 2.0) + 1.0) / (n + 3) + soma_sequencia_b_r(n - 1);
}
