#include <iostream>

#include "questao6.h"

void quadrado(int lado, char caracter) {
	for (int i = 0; i < lado; i++) {
		for (int j = 0; j < lado; j++) {
			std::cout << caracter;
		}
		std::cout << std::endl;
	}
}
