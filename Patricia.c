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
Node ** initInternalNode(unsigned int position, Node * lnode, Node * rnode){
  Node ** p;
  p = (Node **)malloc(sizeof(Node));
  (*p)->nt = Internal;
  (*p)->NodeInfo.i.lnode = lnode;
  (*p)->NodeInfo.i.rnode = rnode;
  (*p)->NodeInfo.i.position = position;
  return p;
}

Node ** initExternalNode(Data d){
  Node ** p;
  p = (Node **)malloc(sizeof(Node));
  (*p)->nt = External;
  (*p)->NodeInfo.e = d;
  return p;
}

Node ** insertPatricia(Node ** n, Data d){
  Node ** p;
  int i;
  if(*n == NULL){
    return (initExternalNode(d));
  } else {
      *p = *n;
      while (!IsExternal(*(*p))) {
        if(bit((*p)->NodeInfo.i.position, d) == 1)
          *p = (*p)->NodeInfo.i.rnode;
        else
          *p = (*p)->NodeInfo.i.lnode;
      }
  }
  i = 1 ;
  while ((i <= 8) && (bit(i,d) == bit(i, (*p)->NodeInfo.e))) {
    i++;
    if( i > 8){
      printf("ERRO: CHAVE JÁ ESTÁ NA ARVORE\n");
      return n;
    } else {
      return (_insertPatricia(d, n, i));
    }
  }
  return 0;
}

Node ** _insertPatricia(Data d, Node ** n, int i){
  Node ** p;
  if(IsExternal(*(*n)) || (i < (*n)->NodeInfo.i.position)){
		p = initExternalNode(d);
		if(bit(i,d) == 1)
			return (initInternalNode( i , *n,  *p));
		else
			return (initInternalNode(i,*p, *n));
	}else{
		if(bit((*n)->NodeInfo.i.position, d) == 1)
			(*n)->NodeInfo.i.rnode = _insertPatricia(d, &(*n)->NodeInfo.i.rnode, i);
		else
			(*n)->NodeInfo.i.lnode = _insertPatricia(d, &(*n)->NodeInfo.i.lnode, i);
		return n;
	}

}
