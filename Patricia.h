#ifndef PATRICIA_H_INCLUDED
#define PATRICIA_H_INCLUDED
#ifdef TEXTUAL_MODE
#include "Textual.h"
#else
#include "Binaria.h"
#endif
#include <stdio.h>
#include <stdlib.h>
typedef enum{False,True} Boolean;
typedef enum{Internal,External} NodeType;
typedef struct _Node{
	NodeType nt;	//Tipo do No
	union {
		struct {
			Boolean enabled; //Disableable
			unsigned int position;	//distancia em index
			_Node *lnode, *rnode;	//nos filhos
		} i;	//No interno
		Data e;	//No externo
	} NodeInfo;	//abstração no para os nos internos e externos
} Node;
void insertPatricia(Node**,Data);	//Função de Inserção
void searchBitsPatricia(Node*,Data);	//Função de Busca
void searchPatricia(Node*,unsigned char);	//Função de Busca
void disablePatricia(Node**,Data*);	//Função para desativar
void printPatricia(Node*);	//Imprime valores em ordem
void initInternalNode(Node** n, unsigned int position, Node* lnode, Node* rnode); //Inicializa No Interno
void initExternalNode(Node** n, Data d);	//Inicializa No Externo e Arvore
Boolean bit(unsigned int position, Data x);
Boolean IsExternal(Node n);
void _insertPatricia(Data d, Node ** n, unsigned int i);

#endif
