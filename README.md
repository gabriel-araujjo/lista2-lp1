Versão mais recente encontrada no [github](https://github.com/gabriel-araujjo/lista2-lp1)

# Lista 1 - Algoritmos de busca #

## 1. Organização ##

1. `include` contem os arquivos de cabeçalho
2. `src` contem os códigos fonte em c++
3. `test` contem os códigos que foram usados para validar o funcionamento dos
    demais códigos
4. `test/cases` contem casos de teste

## 2. Respostas ##

Para cada questão, quando é o caso, os códigos estão dispostos em
* `include/questao#.h` - cabeçalho
* `src/questao#.cc` - implementação
* `test/src/questao#_teste.h` - classe de teste

onde &#35; é número da questão

### Resposta à questão 4 ###

a) o valor final de `arg1` é alterado na linha 11 para 14, pois o parâmetro `a`
da `funcaoA` é uma referência para `arg1`.

b) `arg2` é passado por valor para `funcaoA`, logo qualquer alteração feita no
parâmetro `b` dessa função não é refletida em `arg2`.

c) A tabela a seguir apresenta os valores de `a` e `b` em cada função

|         |  funcaoA  |  funcaoB  |  funcaoC  |
|:-------:|:---------:|:---------:|:---------:|
|   `a`   |    14     |    15     |    16     |
|   `b`   |    16     |    18     |    18     |

### Resposta à questão 9 ###
O primeiro valor impresso é resultado da função `somaA(arg1, arg2)`. `arg1` e `arg2`
recebem os valores 5 e 6, respectivamente nas linhas 42 e 43.
```c++
int somaA(int a, int b) { // a=5, b=6, arg1=5, arg2=6
    a++; // a=6, b=6, arg1=5, arg2=6
    int result = a + b; // result=12, a=6, b=6, arg1=5, arg2=6
    return result;
} // arg1=5, arg2=6
```
A função `somaA` retorna 12, que é, pois, o primeiro valor impresso.

Em seguida a função `somaB` é chamada tomando `arg1` e `arg2` como argumentos e seu
retorno é impresso em tela. `somaB` recebe o parâmetro `a` por referência, assim
a alteração no valor de `a` que acontece na linha 15 é também refletida em `arg1`.
Logo depois de executada `arg1 = 6` e `arg2 = 6`.

O segundo valor impresso em tela é também 12, uma vez que a aritmética de `somaB`é 
idêntica a realizada em `somaA`.

O terceiro valor impresso em tela é o valor da variável `resultado` depois de
executar o comando `somaC(arg1, arg2, &resultado)` que está com o valor 13.

```c++
void somaC(int a, int b, int * result) { // a=6, b=6, arg1=6, arg2=6
    a++; // a=7, b=6, arg1=6, arg2=6
    (*result) += a+b; // resultado=13
}
```
Note que `result` é o endereço de `resultado`.

O quarto valor a ser impresso está em `resultado` logo após a função `somaD` ser
chamada. `somaD` é análoga a `somaC`, a diferença está somente no parâmetro `result`,
que em C é um ponteiro para inteiro e em D é uma inteiro passado por referência.
As linhas 24 e 31 resultam na mesma alteração em `resultado`.

Então 13 é impresso novamente

O último valor a ser impresso é também um 13, pois a função `somaE` chamada na
linha 55 recebe `resultado` por valor, não havendo nenhuma alteração nesta
variável antes de ela ser impressa pelo comando na linha 56.


## 3. Compilação ##

A compilação foi feita no sistema operacional Ubuntu 14.04 com gcc versão 4.8.4
e GNU Make 3.81

Para executar os testes rode

```bash
make
```

Para somente compilar os testes rode

```bash
make compile_tests
```
