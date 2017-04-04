#ifndef PATRICIA_H_INCLUDED
#define PATRICIA_H_INCLUDED
#ifdef TEXTUAL_MODE
#include "Textual.h"
#else
#include "Binaria.h"
#endif
typedef struct _IntNode{
	Chave c;
} IntNode;
typedef struct _ExtNode{
	Chave c;
} ExtNode;
union Node{ IntNode i; ExtNode e;};

#endif
