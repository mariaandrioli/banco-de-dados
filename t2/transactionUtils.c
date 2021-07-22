/** @file transactionUtils.c
 *  @brief Funções utilizadas para manipular os dados das transações
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */
#include "transactionUtils.h"

// verifica se c ta em array
bool isInArray(int c, struct escalonamento_t* array, int tam) {
	for (int i = 0; i < tam; i++){
		if (c == array[i].escalonamento_id){
			return true;
		}
	}
	
	return false;
}

int getTransacoesUnicas(struct transaction_t* transactions, int tam) {
	struct escalonamento_t *numTransactions = (struct escalonamento_t*) malloc(sizeof(struct escalonamento_t)*(tam+1)); // vetor de ids das transações
	int i,j, qtdTransacoesUnicas = 0;

	for (i = 0, j = 0; j < tam; j++){
		if (!(isInArray(transactions[j].transaction_id, numTransactions, tam))) { 
			numTransactions[i].escalonamento_id = transactions[j].transaction_id;
			i++;
		}
	}

	while (numTransactions[qtdTransacoesUnicas].escalonamento_id != 0) {
		qtdTransacoesUnicas++;
	}
	
	free(numTransactions);
	return qtdTransacoesUnicas;
}

// Le linha da transação
struct transaction_t* retiraEspacos(char* line) {
	struct transaction_t* t = (struct transaction_t*) malloc(sizeof(struct transaction_t));
	char delim[] = " ";

	char *ptr = strtok(line, delim);
	int cont = 0;

	while(ptr != NULL)
	{
		switch (cont)
		{
		case 0:
			t->time = atoi(ptr);
			break;
		case 1:
			t->transaction_id = atoi(ptr);
			break;
		case 2:
			t->operation = *ptr;
			break;
		case 3:
			t->attribute = *ptr;
			break;
		default:
			break;
		}
		ptr = strtok(NULL, delim);
		cont++;
	}
	
	return t;
}

struct transaction_t* getWriteTransactions(struct transaction_t* writeTransactions, struct transaction_t* transactions, int transactionCount) {
		int i = 0;

		for (i = 0; i < transactionCount; i++) {
				if (transactions[i].operation = WRITE) {
						writeTransactions[i].time =  transactions->time;
						writeTransactions[i].transaction_id =  transactions->transaction_id;
						writeTransactions[i].operation =  transactions->operation;
						writeTransactions[i].attribute =  transactions->attribute;        
				}
		}

		writeTransactions = (struct transaction_t *) realloc(writeTransactions, sizeof(struct transaction_t)*i);

		return writeTransactions;
		
}

struct transaction_t* getReadTransactions(struct transaction_t* readTransactions, struct transaction_t* transactions, int transactionCount) {
		int i = 0;

		for (i = 0; i < transactionCount; i++) {
				if (transactions[i].operation = READ) {
						readTransactions[i].time =  transactions->time;
						readTransactions[i].transaction_id =  transactions->transaction_id;
						readTransactions[i].operation =  transactions->operation;
						readTransactions[i].attribute =  transactions->attribute;        
				}
		}

		readTransactions = (struct transaction_t *) realloc(readTransactions, sizeof(struct transaction_t)*i);

		return readTransactions;
}
