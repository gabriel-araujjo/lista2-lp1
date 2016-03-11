#include <iostream>
#include "questao6.h"

int main(int argc, char ** argv) {
	std::cout << "resultado para qudrado(3)" << std::endl;
	quadrado(3);

	std::cout << std::endl << "resultado para qudrado(5, 'a')" << std::endl;
	quadrado(5, 'a');

	std::cout << std::endl << "resultado para qudrado(5, 'b')" << std::endl;
	quadrado(3, 'b');
}
