/** @file escalona.c
 *  @brief Arquivo principal do projeto
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 */

#include "utils.h"

/**
 * Função principal
 * 
*/
int main() {
	char line[LINESIZE]; 
	struct transaction_t* t;
	// vetor de struct contendo todas as informações das transações
	struct transaction_t* transactions = (struct transaction_t*) malloc(sizeof(struct transaction_t)*LINESIZE); 

	int qtdTransacoes = 0;

	// le arquivo de transações e coloca no vetor transactions
	while (fgets(line, LINESIZE, stdin) != NULL) 
	{
		t = retiraEspacos(line);
		transactions[qtdTransacoes].time =  t->time;
		transactions[qtdTransacoes].index =  t->index;
		transactions[qtdTransacoes].operation =  t->operation;
		transactions[qtdTransacoes].attribute =  t->attribute;
		qtdTransacoes++;
		printf("t->time %d\n", t->time);
		printf("t->index %d\n", t->index);
		printf("t->op %c\n", t->operation);
		printf("t->at %c\n", t->attribute);
	}

	int qtdTransacoesUnicas = getTransacoesUnicas(transactions, qtdTransacoes);
	struct escalonamento_t *transacoesUnicas = (struct escalonamento_t*) malloc(sizeof(struct escalonamento_t)*qtdTransacoesUnicas);
	
	int escalonamento = 1;

	for (int i = qtdTransacoes; i > 0; i--){
		if (transactions[i].operation ==  COMMIT){
			transacoesUnicas[transactions[i].operation-1].escalonamento = escalonamento;
		}
	}
	// printf("\n\n");
	return(0);
}

