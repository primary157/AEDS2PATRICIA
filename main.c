#include <stdio.h>
#include "Patricia.h"
int main(void)
{
	Node *no;	//define arvore
#ifdef TEXTUAL_MODE
	Data *c = "Marilene";	//define c e atribui valores a ele
#else
	unsigned char a = ('a');	//define c e atribui valores a ele
	Data c[8];
	c[0]=(a&1);
	a = a>>1;
	c[1]=(a&1);
	a = a>>1;
	c[2]=(a&1);
	a = a>>1;
	c[3]=(a&1);
	a = a>>1;
	c[4]=(a&1);
	a = a>>1;
	c[5]=(a&1);
	a = a>>1;
	c[6]=(a&1);
	a = a>>1;
	c[7]=(a&1);
#endif
	initExternalNode(&no, c); //Inicializa arvore e insere primero valor
	searchPatricia(no,a);	//Busca c
	printPatricia(no);	//printa arvore
	disablePatricia(&no,c);	//disativa c
	printPatricia(no);	//printa arvore
	

	return 0;
}
