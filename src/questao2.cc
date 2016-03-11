#include <cmath>
#include "questao2.h"

double soma_sequencia_harmonica_i(int n) {
	double result = 0;
	for(; n > 0; n--) {
		result += 1.0/n;
	}
	return result;
}

double soma_sequencia_b_i(int n) {
	double result = 0;
	for(; n > 0; n--) {
		result += (std::pow((double) n, 2.0) + 1.0) / (n + 3);
	}
	return result;
}
