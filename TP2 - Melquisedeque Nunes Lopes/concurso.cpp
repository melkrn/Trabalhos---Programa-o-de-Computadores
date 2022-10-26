#include <iostream>
#include <iomanip>
#include "concurso.h"
using namespace std;

void resumoParticipante(Questoes* questao, unsigned short numeroQuestoes) {
	//Imprimindo o resumo por participante
	char ch = 'A';
	for(unsigned short i = 0; i < numeroQuestoes; i++, ch++) {
		cout << '\t' << ch;
		cout << " (" << questao[i].dificuldade << ") ";
		cout << questao[i].inicio << " às " << questao[i].fim;
		//Imprimindo o tempo que foi gasto para a solução da questão em minutos
		cout << " (" << questao[i].fim - questao[i].inicio << " min)\n";
	}
}

Media media(Questoes * questao, unsigned short tamanhoVetor, unsigned short indiceInicial, 
unsigned short tamanhoPasso) {
	float mediaDificuldade = 0;
	float mediaTempo = 0;
	
	unsigned short j = 0;
	for(unsigned short i = indiceInicial; i < tamanhoVetor; i += tamanhoPasso, j++) {
		//Somando os valores de dificuldade e de tempo da questão
		mediaDificuldade += questao[i].dificuldade;
		mediaTempo += questao[i].fim - questao[i].inicio;
	}
	//Calculando a média de dificuldade e de tempo da questão
	mediaDificuldade /= j;
	mediaTempo /= j;
	
	Media media = {mediaDificuldade,mediaTempo};
	
	return media;
}
void imprimirLinha(char caractere, unsigned short tamanhoLinha) {
	//Imprimindo a linha que separa as seções do programa
	for(unsigned short i = 0; i < tamanhoLinha; i++) {
		cout << caractere;
	}
	cout << endl;
}

//Funções para ler, exibir e subtrair horários 

istream& operator>>(istream& is, Horario &a) {
	cin >> a.hora;
	cin.ignore();
	cin >> a.minuto;
	
	return is;
}

ostream& operator<<(ostream& os, Horario &a) {
	os << setw(2) << setfill('0') << a.hora;
	os << ':';
	os << setw(2) << setfill('0') << a.minuto;
	
	return os;
}

unsigned int operator-(Horario a, Horario b) {
	//Convertendo os horários para minutos
	unsigned int horarioA = a.hora * 60 + a.minuto;
	unsigned int horarioB = b.hora * 60 + b.minuto;
	
	//Retorna a diferença entre os horários em minutos
	return horarioA - horarioB;
}