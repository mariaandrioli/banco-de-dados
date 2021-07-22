/** @file seriabilityUtils.c
 *  @brief Funções auxiliares de seriabilidade
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */
#include "seriabilityUtils.h"

/*
bool checkForSequencedTransactionPatterns(struct transaction_t* currentTransaction, struct transaction_t* otherTransaction) {
	int i, j = 0;

	while(currentTransaction[i].transaction_id != NULL) {
		while(otherTransaction[j].transaction_id != NULL) {
			if((currentTransaction[i].attribute == otherTransaction[j].attribute) && (currentTransaction[i].startTime > otherTransaction[i].startTime))
				return true;
			j++;                
		}
		i++;
	}

	return false;
}*/
