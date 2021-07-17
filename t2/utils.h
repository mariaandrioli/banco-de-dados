/// @file utils.h
#ifndef __UTILS__
#define __UTILS__
#include <stdio.h>
#include <stdlib.h>

struct line_t
{
	int time;
	int index;
	char operation;
	char attribute;
};

// representa nodo
struct nodo_t
{
	int dest;
	struct nodo_t* next;
	char operation;
	char attribute;
};
 
// representa lista
struct list_t
{
	struct nodo_t *head;
};
 
struct grafo_t
{
	int V;
	struct list_t* array;
};

struct nodo_t* criaNodo(int dest);
 
// Cria grafo de V vertices
struct grafo_t* criaGrafo(int V);

void criaAresta (struct grafo_t* grafo, int src, int dest);

void printGraph(struct grafo_t* grafo);

struct line_t* deblank(char* line);

#endif