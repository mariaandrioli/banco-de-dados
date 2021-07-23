/** @file seriabilityUtils.c
 *  @brief Funções auxiliares de seriabilidade
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */

#ifndef __SERIABILITYUTILS__
#define __SERIABILITYUTILS__
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "transactionUtils.h"
#include "graphUtils.h"

/** @brief A partir de dois vetores de operações, avalia se há relação de dependência entre as transações
 *  @param currentOperationsArray: vetor de operações do tipo X da transação Y
 *  @param otherOperationsArray: vetor de operações do tipo Y da transação Z
 */
bool checkForSequencedTransactionPatterns(struct operation_t* currentOperationsArray, struct operation_t* otherOperationsArray);

/** @brief Cria vetor de escalonamentos
 *  @param escalonamentos: vetor de escalonamentos
 *  @param transactions: vetor de transacoes para avaliar seriabilidade
 *  @param grafos: vetor de grafos das transações
 */
void evaluateSeriability(struct escalonamento_t* escalonamento, struct transaction_t* transactions, struct grafo_t* grafos);

/** @brief Função que retorna quantidade de atributos
 *  @param transations: vetor de transações
 *  @param tam: tamanho do vetor de atributos
 *  @param qtd: quantidade de atributos
 *  @return vetor de atributos
 */
char * getAtributos(struct line_t* transactions, int tam, int * qtd);

/** @brief Verifica se c está em array de tamanho tam
 */
int isInString(int c, char* array, int tam);

/** @brief Calcula fatorial de n
 */
int factorial(int n);

/** @brief Troca a e b em array
 */
void swap(int* arr, int a, int b);

/** @brief Função que coloca em data array permutado
 */
void printArray(int*data,  int* a, int len);

/** @brief Função que permuta array
 */
void permute(int* data, int *arr, int start, int end) ;

/** @brief Função que verifica se o escalonamento é visao equivalente
 *  @param escalonamentos: vetor de escalonamentos
 *  @param qtdEscalonamentos: quantidade de escalonamentos
 *  @param transactions: vetor de transações
 *  @param qtdTransacoes: quantidade de transações
 *  @return vetor de atributos
 */
void visaoEquivalente(struct escalonamento_t* escalonamentos, int qtdEscalonamentos, struct transaction_t* transactions, int qtdTransacoes);

#endif