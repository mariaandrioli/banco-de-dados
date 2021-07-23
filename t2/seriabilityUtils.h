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

#endif