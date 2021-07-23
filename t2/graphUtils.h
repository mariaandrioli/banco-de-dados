/** @file graphUtils.h
 *  @brief Funções utilizadas para manipular grafos
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */

#ifndef __GRAPHUTILS__
#define __GRAPHUTILS__
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include "transactionUtils.h"

/**
 * Representa um nodo
*/
struct nodo_t
{
	int dest;
	struct nodo_t* next;
	char operation;
	char attribute;
};
 
/**
 * Representa uma lista
*/
struct list_t
{
	struct nodo_t *head;
};

/**
 * Representa um grafo
*/
struct grafo_t
{
	int transaction_id;
	int V;
	struct list_t* array;
};

/** @brief Função que cria um Nodo
 *  @param dest: indice
 *  @return nodo criado
 */
struct nodo_t* criaNodo(int dest);
 
/** @brief Função que cria um grafo
 *  @param V: quantidade de vértices do grafo
 *  @return Grafo criado 
 */
struct grafo_t* criaGrafo(int V, int transaction_id);

/** @brief Função que cria aresta no grafo
 *  @param grafo: grafo no qual será colocada a aresta
 *  @param src: vértice origem
 *  @param dest: vértice destino
 */
void criaAresta (struct grafo_t* grafo, int src, int dest);

/** @brief Função que imprime grafo
 *  @param grafo: grafo que será impresso
 */
void imprimeGrafo(struct grafo_t* grafo);

/** @brief Função para criar os grafos a partir das transações
 *  @param transactions: array com todas as transações 
 */
void criaGrafos(struct transaction_t *transactions, int qtdTransacoes);

#endif