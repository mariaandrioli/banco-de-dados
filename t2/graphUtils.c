/** @file graphUtils.h
 *  @brief Funções utilizadas para manipular grafos
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */

#include "graphUtils.h"

struct nodo_t* criaNodo(int dest)
{
	struct nodo_t* nodo = (struct nodo_t*) malloc(sizeof(struct nodo_t));
	nodo->dest = dest;
	nodo->next = NULL;
	nodo->operation = '\0';
	nodo->attribute = '\0';

	return nodo;
}
 
// Cria grafo de V vertices
struct grafo_t* criaGrafo(int transaction_id, int V)
{
	struct grafo_t* grafo = (struct grafo_t*) malloc(sizeof(struct grafo_t));
	grafo->V = V;
 
	// Cria array de listas. Array tem tamanho V
	grafo->array = (struct list_t*) malloc(V * sizeof(struct list_t));
 
	// Inicializa cada lista com NULL
	int i;
	for (i = 0; i < V; ++i)
		grafo->array[i].head = NULL;
 
	return grafo;
}

// cria aresta num grafo sem direção
void criaAresta (struct grafo_t* grafo, int src, int dest)
{
	// Cria aresta de src a dest. Adiciona um nodo no começo lista de src
	struct nodo_t* nodo = criaNodo(dest);
	nodo->next = grafo->array[src].head;
	grafo->array[src].head = nodo;
 
	// Cria aresta de dest a src
	nodo = criaNodo(src);
	nodo->next = grafo->array[dest].head;
	grafo->array[dest].head = nodo;
}
 
// Imprime grafo
void imprimeGrafo(struct grafo_t* grafo)
{
	int v;
	for (v = 0; v < grafo->V; ++v)
	{
		struct nodo_t* aux = grafo->array[v].head;
		printf("\n List de vertice %d\n head ", v);
		while (aux)
		{
			printf("-> %d", aux->dest);
			aux = aux->next;
		}
		printf("\n");
	}
}

void criaGrafos(struct transaction_t *transactions, int qtdTransacoes) {
	int i = 0;
	while (transactions[i].transaction_id) {
		criaGrafo(transactions[i].transaction_id, 0);
		i++;
	}
}

