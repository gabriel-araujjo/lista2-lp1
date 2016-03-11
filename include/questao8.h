#include "questao7.h"
#ifndef QUESTAO_8_H_
#define QUESTAO_8_H_

/**
 * Realiza determinada operação no vetor `colecao`
 * @param colecao - vetor onde as operações devem ser feitas
 * @param tamanho - tamanho do vetor
 * @param operacao - operação a ser realizada
 * @param {value} - referencia para as operações OP_HIG e OP_LOW
 *
 */
double faztudo_vetor(double colecao[], int tamanho, Operation operacao = OP_MAX, double value = 0.0);

double max(double colecao[], int tamanho, double reference);

double min(double colecao[], int tamanho, double reference);

double sum(double colecao[], int tamanho, double reference);

double avg(double colecao[], int tamanho, double reference);

double hig(double colecao[], int tamanho, double reference);

double low(double colecao[], int tamanho, double reference);

#endif // QUESTAO_8_H_
