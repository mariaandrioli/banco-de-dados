/** @file seriabilityUtils.c
 *  @brief Funções auxiliares de seriabilidade
 *
 *
 * @author Maria Teresa Kravetz Andrioli (GRR20171602)
 * @author Ana Carolina Faria Magnoni (GRR20166808)
 */
#include "seriabilityUtils.h"

bool checkForSequencedTransactionPatterns(struct operation_t* currentOperationsArray, struct operation_t* otherOperationsArray) {
	int i = 0;
    int j = 0;
    
    while (currentOperationsArray[i].attribute != ' ') {
        while (otherOperationsArray[j].attribute != ' ') {
            if(currentOperationsArray[i].attribute == otherOperationsArray[j].attribute)
                return true;
        }
    }
    
// struct transaction_t
// {
// 	int startTime;
// 	int endTime;
// 	int transaction_id;
// 	struct operation_t *readOperations;
// 	struct operation_t *writeOperations;
// 	struct operation_t *allOperations;
// 	char escalonamento;
// };

    return false;

}

void evaluateSeriability(struct escalonamento_t* escalonamento, struct transaction_t* transactions, struct grafo_t* grafos) {
    for (int i = 0; i < escalonamento->qt_transactions; i++) {
        for (int j = i + 1; i <  escalonamento->qt_transactions; i++) {
            if (checkForSequencedTransactionPatterns(transactions[i].readOperations, transactions[j].writeOperations))
                criaAresta(&grafos[i], grafos[i].transaction_id, grafos[j].transaction_id);
            if (checkForSequencedTransactionPatterns(transactions[i].writeOperations, transactions[j].readOperations))
                criaAresta(&grafos[i], grafos[i].transaction_id, grafos[j].transaction_id);
            if (checkForSequencedTransactionPatterns(transactions[i].writeOperations, transactions[j].writeOperations))
                criaAresta(&grafos[i], grafos[i].transaction_id, grafos[j].transaction_id);

        }
        
    }

    // for(int k = 0, k < escalonamento->qt_transactions; k++) {
    //     if(grafos[i])
    // }
}

int factorial(int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

char * getAtributos(struct line_t* transactions, int tam, int * qtd) {
	char *atributos = malloc(sizeof(char)*(tam+1)); // vetor de ids das transações
	int i,j, qtdAtributos = 0;

	for (i = 0, j = 0; j < tam; j++){
		if (!(isInString(transactions[j].attribute, atributos, tam)) && (transactions[j].attribute != '-')) { 
			atributos[i] = transactions[j].attribute;
			i++;
		}
	}

	while (atributos[qtdAtributos] != 0) {
		qtdAtributos++;
	}
	char *novos = malloc(sizeof(char)*(qtdAtributos));

	for (int i = 0; i < qtdAtributos; i++)
	{
		novos[i] = atributos[i];
	}
	*qtd = qtdAtributos;
	free(atributos);
	return novos;
}

// verifica se c ta em array
int isInString(int c, char* array, int tam) {
	for (int i = 0; i < tam; i++){
		if (c == array[i]){
			return 1;
		}
	}
	
	return 0;
}

void visaoEquivalente(struct escalonamento_t* escalonamentos, int qtdEscalonamentos, struct transaction_t* transactions, int qtdTransacoes){
	for (int i = 0; i < qtdEscalonamentos; i++)
	{
		strcpy(escalonamentos[i].equivalence_result,"NV");
		int * combinacoes = malloc(sizeof(char)*factorial(escalonamentos[i].qt_transactions)*escalonamentos[i].qt_transactions);
		permute(combinacoes, escalonamentos[i].transactions_list, 0, escalonamentos[i].qt_transactions);
		struct operation_t* operacoes = (struct operation_t*) malloc(sizeof(struct operation_t)*OPNUM*2);

		for (int j = 0; j < factorial(escalonamentos[i].qt_transactions)*escalonamentos[i].qt_transactions; j = j + 2)
		{
			int c = 0;
			int n = 0;
			while (transactions[combinacoes[j]-1].allOperations[n].type){
				operacoes[c].type = transactions[combinacoes[j]-1].allOperations[n].type;
				operacoes[c].attribute = transactions[combinacoes[j]-1].allOperations[n].attribute;
				operacoes[c].time = transactions[combinacoes[j]-1].allOperations[n].time;
				c++;
				n++;
			}
			n = 0;
			while (transactions[combinacoes[j+1]-1].allOperations[n].type){
				operacoes[c].type = transactions[combinacoes[j+1]-1].allOperations[n].type;
				operacoes[c].attribute = transactions[combinacoes[j+1]-1].allOperations[n].attribute;
				operacoes[c].time = transactions[combinacoes[j+1]-1].allOperations[n].time;
				c++;
				n++;
			}

			struct operation_t* atual = (struct operation_t*) malloc(sizeof(struct operation_t)*1);
			atual->type = operacoes[0].type;
			atual->attribute = operacoes[0].attribute;
			atual->time = operacoes[0].time;
			for(int n = 1; n < OPNUM*2; n++)
			{
				if ((operacoes[n].type) && (strcmp(escalonamentos[i].equivalence_result,"SV") == 0))
				{
					if (operacoes[n].type == R){
						if ((atual->type == W) && (atual->attribute == operacoes[n].attribute)){
							strcpy(escalonamentos[i].equivalence_result,"NV");
						}
					}
					atual->type = operacoes[n].type;
					atual->attribute = operacoes[n].attribute;
					atual->time = operacoes[n].time;
				}
			}
		}
	}
}

void swap(int* arr, int a, int b) 
{ 
  int tmp = arr[a]; 
  arr[a] = arr[b]; 
  arr[b] = tmp; 
} 
 
 
/* print len elements */ 
void printArray(int*data,  int* a, int len) 
{ 
  size_t i = 0; 
 
  for ( i=0; i< len; i++){
		int c = 0;
			while (data[c] != 0){
				c++;
			}
			data[c] = a[i];
			// printf("data[c] %d ", data[c]);
	}
} 
 
 
 
/* permute an array recursively */ 
void permute(int* data, int *arr, int start, int end) 
{ 
    int i; 
 
    if(start == end) /* this function is done */ 
    { 
      printArray(data, arr, end); 
      return; 
    } 
 
    permute(data, arr, start + 1, end); /* start at next element */ 
 
    /* permute remaining elements recursively */ 
    for(i = start + 1; i < end; i++)  
    { 
        if( arr[start] == arr[i] ) continue; /* skip */ 
  
	    swap(arr, start, i); 
	 
	    permute(data, arr, start + 1, end); 
 
	    swap(arr, start, i); /* restore element order */  
 
    } 
} 
