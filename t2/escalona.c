/// @file escalona.c
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/**
 * This is the main function
 * 
*/
int main() {
	char line[100]; 
	// struct line_t* t = (struct line_t*) malloc(sizeof(struct line_t));

	while (fgets(line, 100, stdin) != NULL) 
	{ 
		deblank(line);
		//printf("line: %s", line);
	} 
		
	return(0);
}