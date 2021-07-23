/** @file seriabilityUtils.c
 *  @brief Funções auxiliares de seriabilidade
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */
#include "seriabilityUtils.h"

bool checkForSequencedTransactionPatterns(struct operation_t* currentOperationsArray, struct operation_t* otherOperationsArray) {
	int i = 0;
    int j = 0;
    
    while (currentOperationsArray[i].attribute != NULL) {
        while (otherOperationsArray[j].attribute != NULL) {
            if(currentOperationsArray[i].attribute == otherOperationsArray[j].attribute)
                return true;
        }
    }
    
// struct transaction_t
// {
// 	int startTime;
// 	int endTime;
// 	int transaction_id;
// 	struct operation_t *readOperations;
// 	struct operation_t *writeOperations;
// 	struct operation_t *allOperations;
// 	char escalonamento;
// };

    return false;

}

void evaluateSeriability(struct escalonamento_t* escalonamento, struct transaction_t* transactions, struct grafo_t* grafos) {
    for (int i = 0; i < escalonamento->qt_transactions; i++) {
        for (int j = i + 1; i <  escalonamento->qt_transactions; i++) {
            if (checkForSequencedTransactionPatterns(transactions[i].readOperations, transactions[j].writeOperations))
                criaAresta(&grafos[i], grafos[i].transaction_id, grafos[j].transaction_id);
            if (checkForSequencedTransactionPatterns(transactions[i].writeOperations, transactions[j].readOperations))
                criaAresta(&grafos[i], grafos[i].transaction_id, grafos[j].transaction_id);
            if (checkForSequencedTransactionPatterns(transactions[i].writeOperations, transactions[j].writeOperations))
                criaAresta(&grafos[i], grafos[i].transaction_id, grafos[j].transaction_id);

        }
        
    }

    // for(int k = 0, k < escalonamento->qt_transactions; k++) {
    //     if(grafos[i])
    // }
}
