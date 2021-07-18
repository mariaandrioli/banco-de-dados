/** @file escalona.c
 *  @brief Arquivo principal do projeto
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 */

#include "utils.h"

/**
 * Função principal
 * 
*/
int main() {
	char line[100]; 
	struct transaction_t* t;
	struct transaction_t* aux = (struct transaction_t*) malloc(sizeof(struct transaction_t)*128);
	struct grafo_t* grafo;

	int cont = 0;

	while (fgets(line, 100, stdin) != NULL) 
	{
		t = retiraEspacos(line);
		aux[cont].time =  t->time;
		aux[cont].index =  t->index;
		aux[cont].operation =  t->operation;
		aux[cont].attribute =  t->attribute;
		cont++;
		// printf("aux[cont]->time %d\n", aux[cont].time);
		// printf("t->index %d\n", t->index);
		// printf("t->op %c\n", t->operation);
		// printf("t->at %c\n", t->attribute);
	} 

	grafo = criaGrafo(cont);
	return(0);
}