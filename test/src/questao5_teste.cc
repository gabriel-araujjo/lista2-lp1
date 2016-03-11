#include "log_util.h"
#include "questao5.h"

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

enum DataType {TWO_ARGS, THREE_ARGS, FOUR_ARGS};

void test_cases(const char * cases_path, DataType type);

void assert_test(double esperado, int vetor[], int n, const char * mensagem_sucesso, const char * mensagem_erro);

void assert_test(double esperado, int vetor[], int n, const char * mensagem_sucesso, const char * mensagem_erro, int x, int y=0);

int main (int argc, char **argv) {
	std::cout << "Testando somatorio com dois argumentos" << std::endl;
	test_cases("test/cases/somatorio_2args_cases.txt", TWO_ARGS);

	std::cout << "Testando somatorio com três argumentos" << std::endl;
	test_cases("test/cases/somatorio_3args_cases.txt", THREE_ARGS);

	std::cout << "Testando somatorio com quatro argumentos" << std::endl;
	test_cases("test/cases/somatorio_4args_cases.txt", FOUR_ARGS);
}

void test_cases(const char * cases_path, DataType type) {
	std::ifstream cases;
	cases.open(cases_path);
	if(!cases.is_open( ))
    {
        std::cout << "Não foi possível abrir arquivo " << cases_path << "Programa será terminado!" << std::endl;
        cases.clear( );
		exit(1);
    }
	std::string line;
	while(std::getline(cases, line)) {
		std::stringstream lineStream(line);
		int y, x, n;
		double result;
		switch(type) {
			case FOUR_ARGS:
				lineStream >> y;
			case THREE_ARGS:
				lineStream >> x;
			case TWO_ARGS: {
				lineStream >> n;
			}
		}
		int vetor[n];
		for (int i = 0; i < n; i++) {
			lineStream >> vetor[i];
		}
		lineStream >> result;
		switch(type) {
			case TWO_ARGS:
				assert_test(result, vetor, n, 
				"somatorio(vetor, n) = %f",
				"somatorio(vetor, n) deveria ser %f, mas retornou %f");
				break;
			case THREE_ARGS:
				assert_test(result, vetor, n, 
				"somatorio(vetor, %d, %d) = %f",
				"somatorio(vetor, %d, %d) deveria ser %f, mas retornou %f", x);
				break;
			case FOUR_ARGS:
				assert_test(result, vetor, n, 
				"somatorio(vetor, %d, %d) = %f",
				"somatorio(vetor, %d, %d) deveria ser %f, mas retornou %f", x, y);
				break;
		}
	}
	cases.close();
}

void assert_test(double esperado, int vetor[], int n, const char * mensagem_sucesso, const char * mensagem_erro) {
	if (std::abs(somatorio(vetor, n) - esperado) < 0.001) {
		SUCESSO(mensagem_sucesso, esperado);
	} else {
		ERRO(mensagem_erro, esperado, somatorio(vetor, n));
	}
}

void assert_test(double esperado, int vetor[], int n, const char * mensagem_sucesso, const char * mensagem_erro, int x, int y) {
	if (std::abs(somatorio(vetor, n, x, y) - esperado) < 0.001) {
		SUCESSO(mensagem_sucesso, n, x, esperado);
	} else {
		ERRO(mensagem_erro, n, x, esperado, somatorio(vetor, n));
	}
}
