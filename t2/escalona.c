/** @file escalona.c
 *  @brief Arquivo principal do projeto
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 */

#include "utils.h"

/**
 * This is the main function
 * 
*/
int main() {
	char line[100]; 
	// struct transaction_t* t = (struct transaction_t*) malloc(sizeof(struct transaction_t));

	while (fgets(line, 100, stdin) != NULL) 
	{ 
		deblank(line);
		//printf("line: %s", line);
	} 
		
	return(0);
}