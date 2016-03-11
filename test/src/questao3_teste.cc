#include "log_util.h"
#include "questao3.h"

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

enum ComparationType {CARACTER, INTEIRO, PONTO_FLUTUANTE};

void test_cases(const char * cases_path, ComparationType type, const char * mensagem_sucesso, const char * mensagem_erro);

template <class T>
void assert_test(T a, T b, T esperado, const char * mensagem_sucesso, const char * mensagem_erro) {
	if (min(a, b) == esperado) {
		SUCESSO(mensagem_sucesso, esperado, a, b);
	} else {
		ERRO(mensagem_erro, esperado, a, b, min(a,b));
	}
}

int main (int argc, char **argv) {
	std::cout << "Testando min caracteres " << std::endl;
	test_cases("test/cases/min_caracteres_cases.txt", CARACTER, "'%c' é o menor entre '%c' e '%c'", "'%c' é o menor entre '%c' e '%c', mas '%c' for retornado");

	std::cout << std::endl << "Testando min inteiros " << std::endl;
	test_cases("test/cases/min_inteiros_cases.txt", INTEIRO, "%d é o menor entre %d e %d", "%d é o menor entre %d e %d, mas %d for retornado");

	std::cout << std::endl << "Testando min ponto flutuante " << std::endl;
	test_cases("test/cases/min_floats_cases.txt", PONTO_FLUTUANTE, "%f é o menor entre %f e %f", "%f é o menor entre %f e %f, mas %f for retornado");
}

void test_cases(const char * cases_path, ComparationType type, const char * mensagem_sucesso, const char * mensagem_erro) {
	std::ifstream cases;
	cases.open(cases_path);
	if(!cases.is_open( ))
    {
        std::cout << "Não foi possível abrir arquivo " << cases_path << "Programa será terminado!" << std::endl;
        cases.clear( );
		exit(1);
    }
	switch(type) {
		case CARACTER: {
			char a, b, esperado;
			std::string line;
			while (std::getline(cases, line)) {
				std::stringstream lineStream(line);

				lineStream >> a >> b >> esperado;
		
				assert_test(a, b, esperado, mensagem_sucesso, mensagem_erro);
			}
			break;
		}
		case INTEIRO: {
			int a, b, esperado;
			std::string line;
			while (std::getline(cases, line)) {
				std::stringstream lineStream(line);

				lineStream >> a >> b >> esperado;
		
				assert_test(a, b, esperado, mensagem_sucesso, mensagem_erro);
			}
			break;
		}
		case PONTO_FLUTUANTE: {
			float a, b, esperado;
			std::string line;
			while (std::getline(cases, line)) {
				std::stringstream lineStream(line);

				lineStream >> a >> b >> esperado;
		
				assert_test(a, b, esperado, mensagem_sucesso, mensagem_erro);
			}
			break;
		}
	}
	cases.close();
}
