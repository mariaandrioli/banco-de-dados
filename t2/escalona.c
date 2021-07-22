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
		transactions[i].readOperations = (struct operation_t*) malloc(sizeof(struct operation_t)*OPNUM);
		transactions[i].writeOperations = (struct operation_t*) malloc(sizeof(struct operation_t)*OPNUM);
		transactions[i].allOperations = (struct operation_t*) malloc(sizeof(struct operation_t)*OPNUM*2);
		
		for (int m = 0; m < OPNUM; m++)
		{
			transactions[i].readOperations[m].type = 0;
			transactions[i].readOperations[m].attribute = ' ';
			transactions[i].writeOperations[m].type = 0;
			transactions[i].writeOperations[m].attribute = ' ';
		}

		for (int m = 0; m < OPNUM*2; m++)
		{
			transactions[i].allOperations[m].type = 0;
			transactions[i].allOperations[m].attribute = ' ';
		}
	}
	
	int escalonamentoAtual = 1;
	int ativas = 0;
	int commits = 0;
	for (int i = 0; i < qtdTransacoes; i++)
	{
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

					addsToOpsArray(transactions[j].allOperations, C, transactionsOps[i].attribute);
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
					addsToOpsArray(transactions[j].writeOperations, W, transactionsOps[i].attribute);
					addsToOpsArray(transactions[j].allOperations, W, transactionsOps[i].attribute);
				}
				if (transactionsOps[i].operation == READ)
				{
					addsToOpsArray(transactions[j].writeOperations, R, transactionsOps[i].attribute);
					addsToOpsArray(transactions[j].allOperations, R, transactionsOps[i].attribute);	
				}
			}
		}
	}
	escalonamentoAtual--;
	struct escalonamento_t* escalonamentos = (struct escalonamento_t*) malloc(sizeof(struct escalonamento_t)*escalonamentoAtual);
	fazEscalonamento(escalonamentos, transactions, escalonamentoAtual, qtdTransacoesUnicas);
	// for (int j = 0; j < qtdTransacoesUnicas; j++){
	// 	printf("id: %d escal:%d\n", transactions[j].transaction_id, transactions[j].escalonamento);
	// } 

	imprimeSaida(escalonamentos, escalonamentoAtual);
	return(0);
}

