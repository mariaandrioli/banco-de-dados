/** @file escalona.c
 *  @brief Arquivo principal do projeto
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */

#include "graphUtils.h"
#include "transactionUtils.h"
#include "seriabilityUtils.h"

/**
 * Função principal
 * 
*/
int main() {
	char line[LINESIZE]; 
	struct line_t* t;
	// vetor de struct contendo todas as informações das transações
	struct line_t* transactions_ops = (struct line_t*) malloc(sizeof(struct line_t)*LINESIZE);

	int qtdTransacoes = 0;

	// le arquivo de transações e coloca no vetor transactions_ops
	while (fgets(line, LINESIZE, stdin) != NULL) 
	{
		t = retiraEspacos(line);
		transactions_ops[qtdTransacoes].startTime =  t->startTime;
		transactions_ops[qtdTransacoes].transaction_id =  t->transaction_id;
		transactions_ops[qtdTransacoes].operation =  t->operation;
		transactions_ops[qtdTransacoes].attribute =  t->attribute;
		qtdTransacoes++;

		// printf("t->time %d\n", t->startTime);
		// printf("t->transaction_id %d\n", t->transaction_id);
		// printf("t->op %c\n", t->operation);
		// printf("t->at %c\n", t->attribute);
		// printf("\n");
	}

	int qtdTransacoesUnicas = getTransacoesUnicas(transactions_ops, qtdTransacoes);
	struct transaction_t* transactions =  (struct transaction_t*) malloc(sizeof(struct transaction_t)*qtdTransacoesUnicas);

	// Populando vetor de transações
	for (int i = 0; i < qtdTransacoesUnicas; i++){
		transactions[i].transaction_id = i+1;
	}

	for (int j = 0; j < qtdTransacoesUnicas; j++)
		for (int i = 0; i < qtdTransacoes; i++)
		{
			if (transactions[j].transaction_id == transactions_ops[i].transaction_id)
			{
				if (!(transactions[j].startTime))
				{
					transactions[j].startTime = transactions_ops[i].startTime;		
				}
				if (transactions_ops[i].operation == COMMIT)
				{
					transactions[j].endTime = transactions_ops[i].startTime;
					// adiciona em allOperations			
				}
				if (transactions_ops[i].operation == WRITE)
				{
					printf("read");
					// adiciona em writeOperations	
					// adiciona em allOperations	
				}
				if (transactions_ops[i].operation == READ)
				{
					printf("read");
					// adiciona em readOperations	
					// adiciona em allOperations	
				}
			}
		}

	for (int j = 0; j < qtdTransacoesUnicas; j++){
		printf("%d %d %d\n", transactions[j].transaction_id, transactions[j].startTime, transactions[j].endTime);
	} 
	// Populando vetor de transações

	// para cada escalonamento, um grafo
	// em cada grafo, faz teste de serialidade (fazer teste na hora de adicionar talvez?)
	// no fim, ve se é visao equivalente

	printf("%d\n", qtdTransacoesUnicas);
	return(0);
}

