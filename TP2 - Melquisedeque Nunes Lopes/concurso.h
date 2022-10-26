#include <iostream>
using namespace std;

struct Horario {
	unsigned short hora;
	unsigned short minuto;
};

struct Questoes {
	unsigned short dificuldade;
	Horario inicio;
	Horario fim;
};

struct Media {
	float dificuldade;
	float tempo;
};

struct Participantes {
	char nome[40];
	Questoes * questoes;
};

void resumoParticipante(Questoes*, unsigned short);
Media media(Questoes*, unsigned short, unsigned short, unsigned short);
void imprimirLinha(char, unsigned short);
ostream& operator<<(ostream&, Horario&);
istream& operator>>(istream&, Horario&);
unsigned int operator-(Horario, Horario);

