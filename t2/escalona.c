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
	struct line_t* transactionsOps = (struct line_t*) malloc(sizeof(struct line_t)*LINESIZE);

	int qtdTransacoes = 0;

	// le arquivo de transações e coloca no vetor transactionsOps
	while (fgets(line, LINESIZE, stdin) != NULL) 
	{
		t = retiraEspacos(line);
		transactionsOps[qtdTransacoes].startTime =  t->startTime;
		transactionsOps[qtdTransacoes].transaction_id =  t->transaction_id;
		transactionsOps[qtdTransacoes].operation =  t->operation;
		transactionsOps[qtdTransacoes].attribute =  t->attribute;
		qtdTransacoes++;

		// printf("t->time %d\n", t->startTime);
		// printf("t->transaction_id %d\n", t->transaction_id);
		// printf("t->op %c\n", t->operation);
		// printf("t->at %c\n", t->attribute);
		// printf("\n");
	}

	int qtdTransacoesUnicas = getTransacoesUnicas(transactionsOps, qtdTransacoes);
	struct transaction_t* transactions =  (struct transaction_t*) malloc(sizeof(struct transaction_t)*qtdTransacoesUnicas);

	// Populando vetor de transações
	for (int i = 0; i < qtdTransacoesUnicas; i++){
		transactions[i].transaction_id = i+1;
	}

	int escalonamentoAtual = 1;
	int ativas, commits = 0;
	for (int i = 0; i < qtdTransacoes; i++)
		for (int j = 0; j < qtdTransacoesUnicas; j++)
		{
			if (transactions[j].transaction_id == transactionsOps[i].transaction_id)
			{
				if (!(transactions[j].startTime))
				{
					transactions[j].startTime = transactionsOps[i].startTime;
					transactions[j].escalonamento = escalonamentoAtual;
					ativas++;
				}
				if (transactionsOps[i].operation == COMMIT)
				{
					transactions[j].endTime = transactionsOps[i].startTime;
					// adiciona em allOperations
					commits++;
					
					if (commits == ativas)
					{
						escalonamentoAtual++;
						ativas = 0;
						commits = 0;
					}
					
				}
				if (transactionsOps[i].operation == WRITE)
				{
					printf("");
					// adiciona em writeOperations	
					// adiciona em allOperations	
				}
				if (transactionsOps[i].operation == READ)
				{
					printf("");
					// adiciona em readOperations	
					// adiciona em allOperations	
				}
			}
		}

	for (int j = 0; j < qtdTransacoesUnicas; j++){
		printf("id: %d escal:%d\n", transactions[j].transaction_id, transactions[j].escalonamento);
	} 
	// Populando vetor de transações

	// para cada escalonamento, um grafo
	// em cada grafo, faz teste de serialidade (fazer teste na hora de adicionar talvez?)
	// no fim, ve se é visao equivalente

	printf("qtd transacoes:%d\n\n", qtdTransacoesUnicas);
	return(0);
}

