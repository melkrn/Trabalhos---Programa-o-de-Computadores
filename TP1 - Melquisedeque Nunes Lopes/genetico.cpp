#include <iostream>
#include "binario.h"
using namespace std;

unsigned short cruzamentoPontoUnico(unsigned short numero1, unsigned short numero2) {
	//Obtendo os bits altos e altos dos números
	unsigned short bAltos = bitsAltos(numero1);
	unsigned short bBaixos = bitsBaixos(numero2);
	/*Movendo os bits altos do número 1 para obter o cruzamento de ponto único através de um OR 
	entre os bits altos e os bits baixos*/
	bAltos = bAltos << 8;
	return orBinario(bAltos, bBaixos);
}

unsigned short cruzamentoPontoAritmetico(unsigned short numero1, unsigned short numero2) {
	return andBinario(numero1, numero2);
}

unsigned short mutacaoSimples(unsigned short numero) {
	//Testando se o bit na posição 9 é 1 ou 0
	int posicaoBit = 9;
	if(testarBit(numero, posicaoBit)) {
		//Desligando o bit
		numero = desligarBit(numero, posicaoBit);
	} else {
		//Ligando o bit
		numero = ligarBit(numero, posicaoBit);
	}
	return numero;
}

unsigned short mutacaoDupla(unsigned short numero) {
	//Testando se o bit na posição 3 é 1 ou 0
	int posicaoBit1 = 3;
	if(testarBit(numero, posicaoBit1)) {
		//Desligando o bit
		numero = desligarBit(numero, posicaoBit1);
	} else {
		numero = ligarBit(numero, posicaoBit1);
	}
	
	//Testando se o bit na posição 12 é 1 ou 0
	int posicaoBit2 = 12;
	if(testarBit(numero, posicaoBit2)) {
		//Desligando o bit
		numero = desligarBit(numero, posicaoBit2);
	} else {
		numero = ligarBit(numero, posicaoBit2);
	}
	return numero;
}

int avaliacao(unsigned short numero) {
	//Array com os pesos possíveis e uma variável auxiliar para calcular o peso total
	int pesos[16] = {1,4,2,5,4,2,1,4,3,2,1,9,4,5,3,12};
	int pesoTotal = 0;
	//Array com os pesos possíveis e uma variável auxiliar para calcular o valor total da bolsa
	int valores[16] = {12,4,3,10,15,20,10,2,1,1,3,15,10,8,4,4};
	int valorTotal = 0;
	
	//Percorrendo todos os bits do número e testando se cada bit é igual a 1 ou a 0
	for(int i = 0; i <= 15; i++) {
		if(testarBit(numero, i)) {
			/*Se o bit é igual a 1, devemos somar o peso e o valor correspondente à posição desse 
			* bit*/
			pesoTotal += pesos[i];
			valorTotal += valores[i];
		}
	}
	
	//Imprime o valor total e o peso total
	cout << "\t $" << valorTotal;
	cout << "\t - \t" << pesoTotal << "Kg";
	
	return pesoTotal; //Retorna o peso da bolsa para dizer se a bolsa está OK ou não
}