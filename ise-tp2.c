/*
::.Data: 24-08-2017
::.UFAM - IComp - PPGI
::.Introdução a Sistemas Embarcados
::.Márcio André da Costa Alencar - macalencar@gmail.com
::..
::..Trabalho Prático 2 - Deslocamento bit-a-bit

*/


#define _RIGHTBIT 0x1			//máscara para o bit mais à direita		00000000 00000001
#define _LEFTBIT  0x8000 		//máscada para o bit mais à esquerda 	10000000 00000000
#include <stdio.h>
int _LOOPS = 16;				//número de loops

//Imprime  em binário
void binarize(unsigned short n){
	unsigned short r;
	for(short i = (sizeof(short)*8)-1; i >= 0; i--) {
	    r = n >> i;						//'i' shifts no valor n
		printf((i == 7) ? " " : "");	//um espaço à cada byte
    	printf((r & 1) ? "1" : "0");	//obtem o valor do bit mais à direita e imprime.
	}
}

//Shift para esquerda
//retorna o valor modificado pelos shifts
unsigned short int leftShift(unsigned short n){
	unsigned short new = n;
	binarize(new);printf("\t%hu \t0x%X\n",new, new);
	for(int i=0; i<_LOOPS; i++){
		unsigned short lb = ((new & _LEFTBIT) >> 15);	//Extrai o bit à esquerda e movimenta-o para direita
		unsigned short roll = new << 1;						//Shift para esquerda do valor atual
		new = roll ^ lb;								//Concatena valor atual com bit extraído
		binarize(new);
		printf("\t%hu \t0x%X\n",new, new);
	}
	return new;
}

//Shift para direita
//retorna o valor modificado pelos shifts
unsigned short int rightShift(unsigned short n){
	unsigned short new = n;
	binarize(new);printf("\t%hu \t0x%X\n",new, new);
	for(int i=0; i<_LOOPS; i++){
		unsigned short rb = ((new & _RIGHTBIT) << 15);	//Extrai o bit à direita e movimenta-o para esquerda
		unsigned short roll = new >> 1;					//Shift para direita do valor atual
		new = roll ^ rb;						//Concatena valor atual com bit extraído
		binarize(new);
		printf("\t%hu \t0x%X\n",new, new);
	}
	return new;
}


int main(){
	unsigned short val;
	int auxLoops;

	//Inserir valor de entrada
	printf("Insira um valor(unsigned short) de entrada: ");
	scanf("%hu", &val);

	//Inserir numero de shifts
	printf("Insira o número de shifts( > 0): ");
	scanf("%d", &auxLoops);
	if(auxLoops > 0){ _LOOPS = auxLoops ; }
	
	//Impressão do valor em  Binário, Decimal e Hexadecimal
	printf("-----------------------------\n");
	printf("Bin: ");
	binarize(val);
	printf("\nDec: %d \nHex: 0x%X\n",val, val);

	//Chamada da função leftShift()
	printf("-----------------------------\nROTAÇÃO PARA ESQUERDA\n-----------------------------\n");	
	val=leftShift(val);

	//Chamada da função rightShift()
	printf("-----------------------------\nROTAÇÃO PARA DIREITA\n-----------------------------\n");	
	val=rightShift(val);
	printf("-----------------------------\n");
}
