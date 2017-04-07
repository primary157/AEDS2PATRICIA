#include "Patricia.h"
Boolean bit(unsigned int position, Data x){
	unsigned int i;
	if (position == 0) return False;
	else{ 
		for(i = 1; i <= x - position; i++) x = x>>1; return (Boolean)(x&1);
	}
}
Boolean IsExternal(Node n){
	return (Boolean)(n.nt == External);
}
void searchPatricia(Node* n, Data d){
	if(IsExternal(*n) == True){
		if(d == n->NodeInfo.e) printf("Elemento Encontrado\n");
		else printf("Ops nao achei\n");
		return;
	}
	if(bit(n->NodeInfo.i.position, d) == False) searchPatricia(n->NodeInfo.i.lnode,d);
	else searchPatricia(n->NodeInfo.i.rnode,d);
}
void initInternalNode(Node** n, unsigned int position, Node* lnode, Node* rnode){
	  (*n) = (Node *)malloc(sizeof(Node));
	  (*n)->nt = Internal;
	  (*n)->NodeInfo.i.lnode = lnode;
	  (*n)->NodeInfo.i.rnode = rnode;
	  (*n)->NodeInfo.i.position = position;
}

void initExternalNode(Node **n,Data d){
	  (*n) = (Node *)malloc(sizeof(Node));
	  (*n)->nt = External;
	  (*n)->NodeInfo.e = d;
}

void insertPatricia(Node ** n, Data d){
	unsigned int i = 1;
	if(*n == NULL){
		initExternalNode(n,d);
		return;
	} 
	else {
		while (!IsExternal(**n)) {
			if(bit((*n)->NodeInfo.i.position, d) == 1)
			  insertPatricia(&(*n)->NodeInfo.i.rnode,d);
			else
			  insertPatricia(&(*n)->NodeInfo.i.lnode,d);
		}
	}
	while ((i <= 8) && (bit(i,d) == bit(i, (*n)->NodeInfo.e))) {
		if( ++i > 8){
			printf("ERRO: CHAVE JÁ ESTÁ NA ARVORE\n");
			return;
		} 
		else {
			_insertPatricia(d, n, i);
			return;
		}
	}
}

void _insertPatricia(Data d, Node ** n, unsigned int i){
	Node *n_aux1, *n_aux2;
	if(IsExternal(*(*n)) || (i < (*n)->NodeInfo.i.position)){
		initExternalNode(&n_aux1,d);
		if(bit(i,d) == 1){
			initInternalNode(&n_aux2, i , *n,  n_aux1);
			*n = n_aux2;
			return;
		}
		else{
			initInternalNode(&n_aux2, i , n_aux1, *n);
			*n = n_aux2;
			return;
		}
	}else{
		if(bit((*n)->NodeInfo.i.position, d) == 1)
			_insertPatricia(d, &(*n)->NodeInfo.i.rnode, i);
		else
			_insertPatricia(d, &(*n)->NodeInfo.i.lnode, i);
		return;
	}
}
