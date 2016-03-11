#include "log_util.h"
#include "questao8.h"

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

void test_cases(const char * cases_path);

void assert_test(double esperado, double vetor[], int n);

void assert_test(double esperado, double vetor[], int n, Operation op, double value=0);

int main (int argc, char **argv) {
	std::cout << "Testando funcao faz tudo para ponto flutuante" << std::endl;
	test_cases("test/cases/faztudo_float_cases.txt");
}

void test_cases(const char * cases_path) {
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
		int n;
		double result;
		
		// ler o vetor
		lineStream >> n;
		double vetor[n];
		for (int i = 0; i < n; i++) {
			lineStream >> vetor[i];
		}

		// teste max
		lineStream >> result;
		assert_test(result, vetor, n, OP_MAX);
		// repetindo sem especificar operação
		assert_test(result, vetor, n);

		// teste min
		lineStream >> result;
		assert_test(result, vetor, n, OP_MIN);

		// teste sum
		lineStream >> result;
		assert_test(result, vetor, n, OP_SUM);

		// teste avg
		lineStream >> result;
		assert_test(result, vetor, n, OP_AVG);

		// teste hig
		lineStream >> result;
		assert_test(result, vetor, n, OP_HIG);

		// teste low
		lineStream >> result;
		assert_test(result, vetor, n, OP_LOW);		
//----------------------------------------------------
		// repetindo hig e low com um valor passado
		double value;
		lineStream >> value;

		// teste hig
		lineStream >> result;
		assert_test(result, vetor, n, OP_HIG, value);

		// teste low
		lineStream >> result;
		assert_test(result, vetor, n, OP_LOW, value);		
	}
	cases.close();
}

void assert_test(double esperado, double vetor[], int n, Operation op, double value) {
	if (faztudo_vetor(vetor, n, op, value) == esperado) {
		SUCESSO("%f = %f", esperado, esperado);
	} else {
		ERRO("esperado %f != %f", esperado, faztudo_vetor(vetor, n, op, value));
	}	
}

void assert_test(double esperado, double vetor[], int n) {
	if (std::abs(faztudo_vetor(vetor, n) - esperado) < 0.001) {
		SUCESSO("%f = %f", esperado, esperado);
	} else {
		ERRO("esperado %f != %f", esperado, faztudo_vetor(vetor, n));
	}	
}
