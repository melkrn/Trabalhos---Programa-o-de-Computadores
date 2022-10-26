#include <iostream>
#include "genetico.h"
using namespace std;

#define green "\033[32m"
#define red "\033[31m"
#define default "\033[m"

int main() {
	unsigned short solucoes[6];
	int pesoTotal; //Variável para os pesos
	cout << "Entre com 6 soluções iniciais (números entre 0 e 65535) \n";
	cin >> solucoes[0];
	cin >> solucoes[1];
	cin >> solucoes[2];
	cin >> solucoes[3];
	cin >> solucoes[4];
	cin >> solucoes[5];
	
	cout << endl;
	cout << "Resultado da avaliação" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	for(int i = 0; i <= 5; i++){
		cout << solucoes[i];
		cout << "\t - ";

		pesoTotal = avaliacao(solucoes[i]); //Retorna o peso e imprime o peso e valor
		cout << "\t - ";
	
		if(pesoTotal <= 20) {
			cout << green << "\t OK" << default << endl;
		} else {
			cout << red << "\t X" << default << endl;
		}
	}
	cout << "---------------------------------------------------------------------------" << endl;
	//Obtendo as 4 novas soluções
	unsigned short cruzamentoPonto_Unico =  cruzamentoPontoUnico(solucoes[0], solucoes[1]);
	unsigned short cruzamentoPonto_Aritmetico =  cruzamentoPontoAritmetico(solucoes[2], solucoes[3]);
	unsigned short mutacao_Simples =  mutacaoSimples(solucoes[4]);
	unsigned short mutacao_Dupla = mutacaoDupla(solucoes[5]);
	
	//Imprimindo os resultados de cruzamento de ponto único
	cout << cruzamentoPonto_Unico;
	cout << "\t - ";
	pesoTotal = avaliacao(cruzamentoPonto_Unico); //Retorna o peso e imprime o peso e valor
	cout << "\t - ";
	
	if(pesoTotal <= 20) {
		cout << green << "\t OK" << default << endl;
	} else {
		cout << red << "\t X" << default << endl;
	}
	
	//Imprimindo os resultados de cruzamento de ponto aritmético
	cout << cruzamentoPonto_Aritmetico;
	cout << "\t - ";
	pesoTotal = avaliacao(cruzamentoPonto_Aritmetico); //Retorna o peso e imprime o peso e valor
	cout << "\t - ";
	
	if(pesoTotal <= 20) {
		cout << green << "\t OK" << default << endl;
	} else {
		cout << red << "\t X" << default << endl;
	}
	
	//Imprimindo os resultados de mutação simples
	cout << mutacao_Simples;
	cout << "\t - ";
	pesoTotal = avaliacao(mutacao_Simples); //Retorna o peso e imprime o peso e valor
	cout << "\t - ";
	
	if(pesoTotal <= 20) {
		cout << green << "\t OK" << default << endl;
	} else {
		cout << red << "\t X" << default << endl;
	}
	
	//Imprimindo os resultados de mutação dupla
	cout << mutacao_Dupla;
	cout << "\t - ";
	pesoTotal = avaliacao(mutacao_Dupla); //Retorna o peso e imprime o peso e valor
	cout << "\t - ";
	
	if(pesoTotal <= 20) {
		cout << green << "\t OK" << default << endl;
	} else {
		cout << red << "\t X" << default << endl;
	}
	
	cout << endl;
}