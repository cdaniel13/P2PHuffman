#include <stdio.h>
#include <stdlib.h>
#include "utilidade.h"



int checarSetado(Byte byte, int posicao){

	return (byte & (1 << posicao));
}


Byte setarBit(Byte byte, int posicao){
	return (byte | (1 << (7 - posicao)));
}







