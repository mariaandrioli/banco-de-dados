/** @file transactionUtils.c
 *  @brief Funções utilizadas para manipular os dados das transações
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */
#include "transactionUtils.h"

// verifica se c ta em array
int isInArray(int c, struct escalonamento_t* array, int tam) {
	for (int i = 0; i < tam; i++){
		if (c == array[i].escalonamento_id){
			return 1;
		}
	}
	
	return 0;
}

int getTransacoesUnicas(struct line_t* transactions, int tam) {
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
struct line_t* retiraEspacos(char* line) {
	struct line_t* t = (struct line_t*) malloc(sizeof(struct line_t));
	char delim[] = " ";

	char *ptr = strtok(line, delim);
	int cont = 0;

	while(ptr != NULL)
	{
		switch (cont)
		{
		case 0:
			t->startTime = atoi(ptr);
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

int addsToOpsArray(struct operation_t *array, int type, char attribute){
	int c = 0;
	while (array[c].type) {
		c++;
	}
	array[c].type = type;
	array[c].attribute = attribute;

	return 1;
}

void fazEscalonamento(struct escalonamento_t* escalonamentos, struct transaction_t* transactions, int qtdEscalonamentos, int unicas){
	for (int j = 0; j < unicas; j++){
		escalonamentos[transactions[j].escalonamento-1].qt_transactions++;
	} 

	for (int i = 0; i < qtdEscalonamentos; i++){
		escalonamentos[i].escalonamento_id = i+1;
		escalonamentos[i].transactions_list =  malloc(sizeof(int)*escalonamentos[i].qt_transactions);
	} 

	for (int i = 0; i < qtdEscalonamentos; i++){
		int qtd = 0;
		for (int m = 0; m < unicas; m++)
			if (transactions[m].escalonamento == escalonamentos[i].escalonamento_id)
			{
				escalonamentos[i].transactions_list[qtd] = transactions[m].transaction_id;
				qtd++;
			}
	} 
}

void imprimeSaida(struct escalonamento_t* escalonamentos, int qtdEscalonamentos) {
	for (int i = 0; i < qtdEscalonamentos; i++)
	{
		printf("%d ", escalonamentos[i].escalonamento_id);

		for (int j = 0; j < escalonamentos[i].qt_transactions; j++)
		{
			if (j == escalonamentos[i].qt_transactions-1)
			{
				printf("%d", escalonamentos[i].transactions_list[j]);
			}
			else {
				printf("%d,", escalonamentos[i].transactions_list[j]);
			}
		}
		printf(" ");

		// printf("%s ", escalonamentos[i].seriability_result);
		// printf("%s", escalonamentos[i].equivalence_result);
		printf("\n");
	}
}