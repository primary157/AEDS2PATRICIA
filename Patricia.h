#ifndef PATRICIA_H_INCLUDED
#define PATRICIA_H_INCLUDED
#ifdef TEXTUAL_MODE
#include "Textual.h"
#else
#include "Binaria.h"
#endif
union Node;
typedef struct _IntNode{
	Chave c;	//binario ou char
	unsigned int offset;	//distancia em index
	Node *lnode, *rnode;	//nos filhos
} IntNode;
typedef struct _ExtNode{
	Chave *c;	//Cadeia de bits ou string
} ExtNode;
union Node{ IntNode i; ExtNode e;};	//abstração para o ponteiro para Nos
void insertPatricia(Node**,Chave*);	//Função de Inserção
void searchPatricia(Node*,Chave*);	//Função de Busca
void disablePatricia(Node**,Chave*);	//Função para desativar
void printPatricia(Node*);	//Imprime valores em ordem
void initPatricia(Node**);	//Inicializa No

#endif
