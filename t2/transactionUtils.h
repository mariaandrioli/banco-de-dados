/** @file transactionUtils.h
 *  @brief Funções utilizadas para manipular os dados das transações
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define LINESIZE 128
#define READ "R"
#define WRITE "W"
#define COMMIT "C"


/**
 * Representa um id e respectivo escalonamento
*/
struct escalonamento_t
{
	int escalonamento_id;
	int *transactions_list;
	char seriability_result[2];
	char equivalence_result[2];
};

/**
 * Representa uma operação
*/
struct operation_t
{
	int name;
	char attribute;
};


/**
 * Representa uma transação
*/
struct transaction_t
{
	int startTime;
	int endTime;
	int transaction_id;
	struct operation_t *readOperations;
	struct operation_t *writeOperations;
	struct operation_t *allOperations;
	char attribute;
};

/** @brief Função que remove espaços na linha de transação e coloca no struct
 *  @param line: string da transação
 *  @return Struct do tipo transaction_t
 */
struct transaction_t* retiraEspacos(char* line);

bool isInArray(int c, struct escalonamento_t* array, int tam);

int getTransacoesUnicas(struct transaction_t* transactions, int tam);

struct transaction_t* getWriteTransactions(struct transaction_t* writeTransactions, struct transaction_t* transactions, int transactionCount);

struct transaction_t* getReadTransactions(struct transaction_t* readTransactions, struct transaction_t* transactions, int transactionCount);