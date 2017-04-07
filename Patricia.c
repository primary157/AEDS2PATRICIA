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
