#ifndef QUESTAO_7_H_
#define QUESTAO_7_H_

enum Operation {
	/** Retorna o elemento de maior valor na coleção */
	OP_MAX,

	/** Retorna o elemento de menor valor na coleção */
	OP_MIN,

	/** Retorna a soma de todos os elementos da função */
	OP_SUM,

	/** Retorna a média aritimética de todos os elementos da coleção */
	OP_AVG,

	/** Retórna a quantidade de elementos maiores que `value` */
	OP_HIG,

	/** Retórna a quantidade de elementos menores que `value` */
	OP_LOW
};

/**
 * Realiza determinada operação no vetor `colecao`
 * @param colecao - vetor onde as operações devem ser feitas
 * @param tamanho - tamanho do vetor
 * @param operacao - operação a ser realizada
 * @param {value} - referencia para as operações OP_HIG e OP_LOW
 *
 */
int faztudo_vetor(int colecao[], int tamanho, Operation operacao, int value = 0);

int max(int colecao[], int tamanho, int reference);

int min(int colecao[], int tamanho, int reference);

int sum(int colecao[], int tamanho, int reference);

int avg(int colecao[], int tamanho, int reference);

int hig(int colecao[], int tamanho, int reference);

int low(int colecao[], int tamanho, int reference);

#endif // QUESTAO_7_H_
