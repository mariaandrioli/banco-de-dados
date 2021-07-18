/** @file utils.c
 *  @brief Funções utilizadas no projeto
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 */
#include "utils.h"

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
struct grafo_t* criaGrafo(int V)
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

// Le linha da transação
struct transaction_t* retiraEspacos(char* line) {
	struct transaction_t* t = (struct transaction_t*) malloc(sizeof(struct transaction_t));
	char delim[] = " ";

	char *ptr = strtok(line, delim);
	int cont = 0;

	while(ptr != NULL)
	{
		switch (cont)
		{
		case 0:
			t->time = atoi(ptr);
			break;
		case 1:
			t->index = atoi(ptr);
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