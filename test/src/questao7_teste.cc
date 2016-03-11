#include "log_util.h"
#include "questao7.h"

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

void test_cases(const char * cases_path);

void assert_test(int esperado, int vetor[], int n, Operation op, int value=0);

int main (int argc, char **argv) {
	std::cout << "Testando funcao faz tudo" << std::endl;
	test_cases("test/cases/faztudo_cases.txt");
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
		int n, result;
		
		// ler o vetor
		lineStream >> n;
		int vetor[n];
		for (int i = 0; i < n; i++) {
			lineStream >> vetor[i];
		}

		// teste max
		lineStream >> result;
		assert_test(result, vetor, n, OP_MAX);

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
		int value;
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

void assert_test(int esperado, int vetor[], int n, Operation op, int value) {
	if (faztudo_vetor(vetor, n, op, value) == esperado) {
		SUCESSO("%d = %d", esperado, esperado);
	} else {
		ERRO("esperado %d != %d", esperado, faztudo_vetor(vetor, n, op, value));
	}	
}
