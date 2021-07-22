/** @file transactionUtils.h
 *  @brief Funções utilizadas para manipular os dados das transações
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */
#ifndef __SERIABILITYUTILS__
#define __SERIABILITYUTILS__
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define LINESIZE 128
#define OPNUM 8
#define READ 'R'
#define WRITE 'W'
#define COMMIT 'C'
#define R 1
#define W 2
#define C 3

/**
 * Representa um id e respectivo escalonamento
*/
struct escalonamento_t
{
	int escalonamento_id;
	int *transactions_list;
	int qt_transactions;
	char seriability_result[2];
	char equivalence_result[2];
};

/**
 * Representa uma operação
*/
struct operation_t
{
	int type;
	char attribute;
};

/**
 * Representa uma das operações da transação na leitura
*/
struct line_t
{
	int startTime;
	int transaction_id;
	char operation;
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
	char escalonamento;
};

/** @brief Função que remove espaços na linha de transação e coloca no struct
 *  @param line: string da transação
 *  @return Struct do tipo transaction_t
 */
struct line_t* retiraEspacos(char* line);

/** @brief Verifica se c ta em array
 *  @param c: inteiro 
 *  @param array: struct do tipo escalonamento_t 
 *  @param tam: tamanho do array 
 *  @return Booleano
 */
int isInArray(int c, struct escalonamento_t* array, int tam);

/** @brief Verifica quantas transações unicas existem em um vetor
 *  @param transactions: vetor de transaction_t  
 *  @param tam: tamanho do vetor de transaction_t 
 *  @return quantidade de transaçoes unicas
 */
int getTransacoesUnicas(struct line_t* transactions, int tam);

/** @brief Adiciona operaçao em um array
 *  @param array: vetor de operation_t  
 *  @param type: tipo da operacao
 *  @param atribute: atributo da operacao
 *  @return vetor modificado
 */
int addsToOpsArray(struct operation_t* array, int type, char attribute);

/** @brief Cria vetor de escalonamentos e imprime na saida padrao
 *  @param transactions: vetor de operation_t  
 *  @param qtdEscalonamentos: quantidade de escalonamentos
 *  @param unicas: quantidade de transacoes unicas
 */
void imprimeSaida(struct transaction_t* transactions, int qtdEscalonamentos, int unicas);

#endif