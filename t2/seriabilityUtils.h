/** @file seriabilityUtils.c
 *  @brief Funções auxiliares de seriabilidade
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */

#ifndef __SERIABILITYHUTILS__
#define __SERIABILITYHUTILS__
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "transactionUtils.h"

bool checkForSequencedTransactionPatterns(struct transaction_t* currentTransaction, struct transaction_t* otherTransaction);

#endif