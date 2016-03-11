#ifndef QUESTAO_5_H_
#define QUESTAO_5_H_
/**
 * 
 * @return somatório dos elementos de vetor
 */
double somatorio(int vetor[], int n);

/**
 * @param vetor - vetor qualquer de inteiros
 * @param n - tamanho de vetor
 * @param x
 * @param y (zero por padrão)
 * @return 
 *  v1      v2      v3            vn
 * ----- + ----- + ----- + ··· + -----
 * x - y   2x -y   3x -y         nx -y
 */
double somatorio(int vetor[], int n, int x, int y=0);

#endif // QUESTAO_5_H_
