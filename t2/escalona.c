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

	// transactions é o vetor de transacoes, tem que primeiro popular ele com as infos
	// de transactions_ops, ou seja start time, id, primeira operacao, depois com as operacoes
	// seguintes; quando chegar no commit, coloca end time

	// para cada escalonamento, um grafo
	// em cada grafo, faz teste de serialidade (fazer teste na hora de adicionar talvez?)
	// no fim, ve se é visao equivalente

	printf("%d\n", qtdTransacoesUnicas);
	return(0);
}

