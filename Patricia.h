#ifndef PATRICIA_H_INCLUDED
#define PATRICIA_H_INCLUDED
#ifdef TEXTUAL_MODE
#include "Textual.h"
#else
#include "Binaria.h"
#endif
typedef enum{False,True} Boolean;
typedef enum{Internal,External} NodeType;
typedef struct _Node{
	NodeType nt;	//Tipo do No
	typedef union _NodeInfo{
		struct {
			Data c;	//binario ou char
			unsigned int offset;	//distancia em index
			_Node *lnode, *rnode;	//nos filhos
		} i;	//No interno
		Data e;	//No externo
	} NodeInfo;	//abstração no para os nos internos e externos
} Node;
void insertPatricia(Node**,Data*);	//Função de Inserção
void searchPatricia(Node*,Data*);	//Função de Busca
void disablePatricia(Node**,Data*);	//Função para desativar
void printPatricia(Node*);	//Imprime valores em ordem
void initPatricia(Node**);	//Inicializa No
Boolean bit(unsigned int offset, Data x);

#endif
