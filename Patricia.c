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
