/** @file seriabilityUtils.c
 *  @brief Funções utilizadas no projeto
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 */
#include "seriabilityUtils.h"

bool checkForSequencedTransactionPatterns(struct transaction_t* currentTransaction, struct transaction_t* otherTransaction) {
    int i, j = 0;

    while(currentTransaction[i].transaction_id != NULL) {
        while(otherTransaction[j].transaction_id != NULL) {
            if((currentTransaction[i].attribute == otherTransaction[j].attribute) && (currentTransaction[i].time > otherTransaction[i].time))
                return true;
            j++;                
        }
        i++;
    }

    return false;
}
