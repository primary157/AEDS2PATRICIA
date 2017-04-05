#include <stdio.h>
#include "Patricia.h"
int main(void)
{
	Node *no;	//define arvore
#ifdef TEXTUAL_MODE
	Chave *c = "Marilene";	//define c e atribui valores a ele
#else
	Chave c[10];	//define c e atribui valores a ele
	c[0]=False;
	c[1]=True;
	c[2]=False;
	c[3]=True;
	c[4]=True;
	c[5]=False;
	c[6]=False;
	c[7]=True;
	c[8]=False;
	c[9]=True;
#endif
	initPatricia(&no);	//Inicializa No
	insertPatricia(&no,c);	//Insere Chave c
	searchPatricia(no,c);	//Busca c
	printPatricia(no);	//printa arvore
	disablePatricia(&no,c);	//disativa c
	printPatricia(no);	//printa arvore
	

	return 0;
}
