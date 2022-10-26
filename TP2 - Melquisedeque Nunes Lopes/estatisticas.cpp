#include <iostream>
#include "concurso.h"
using namespace std;

int main() {
	imprimirLinha('*',50);
	cout << "Concurso de programação\n\n";
	cout << "Qual é o número de participantes? ";
	unsigned short numeroParticipantes;
	cin >> numeroParticipantes;
	cout << "Qual é o número de questões? ";
	unsigned short numeroQuestoes;
	cin >> numeroQuestoes;
	imprimirLinha('*',50);
	
	//Criando vetores dinâmicos de questões e de participantes
	unsigned short tamanhoVetorQuestoes = numeroParticipantes * numeroQuestoes;
	Questoes * questao = new Questoes[tamanhoVetorQuestoes];
	Participantes * participante = new Participantes[numeroParticipantes];
	
	//Perguntando informações dos participantes
	/*Declarando a variável j para auxiliar na obtenção de endereços do início das informações 
	 * no vetor de questões*/
	for(unsigned short i = 0, j = 0; i < numeroParticipantes; i++, j += numeroQuestoes) {
		imprimirLinha('-',15);
		cout << "Participante: ";
		cin.ignore();
		cin.get(participante[i].nome,40);
		imprimirLinha('-',15);
		
		/*Armazenando o endereço onde se iniciam as informações do participante no vetor 
		 * de questões*/
		participante[i].questoes = &questao[j];
		
		/*Armazenando o índice de onde termina o espaço reservado ao participante no vetor
		 * de questões*/
		unsigned short indicePosicaoFinal = j + numeroQuestoes;
		
		 //Preenchendo o vetor de questões
		char ch = 'A';
		for(unsigned short k = j; k < indicePosicaoFinal; k++, ch++) {
			cout << "Questão " << ch << endl;
			cout << "\tDificuldade: ";
			cin >> questao[k].dificuldade;
			cout << "\tInício: ";
			cin >> questao[k].inicio;
			cout << "\tFim: ";
			cin >> questao[k].fim;
		}
		imprimirLinha('-',15);
		cout << endl;
	}
	imprimirLinha('*',50);
	imprimirLinha('-',25);
	cout << "Resumo por Participante\n";
	imprimirLinha('-',25);
	
	for(unsigned short i = 0; i < numeroParticipantes; i++) {
		cout << participante[i].nome << ":\n";
		resumoParticipante(participante[i].questoes, numeroQuestoes);
	}
	imprimirLinha('-',15);
	
	cout << endl;
	imprimirLinha('-',25);
	cout << "Resumo por Questão\n";
	imprimirLinha('-',25);
	char ch = 'A';
	
	//Imprimindo o resumo por questão
	for(unsigned short i = 0; i < numeroQuestoes; i++) {
		cout << "Questão " << ch << ":\n";
		for(unsigned short j = 0; j < numeroParticipantes; j++) {
			//Imprimindo as informações do participante sobre a questão
			cout << '\t' << participante[j].nome;
			cout << " (" << participante[j].questoes[i].dificuldade << ") ";
			cout << participante[j].questoes[i].inicio << " às " << participante[j].questoes[i].fim;
			cout << " (" << participante[j].questoes[i].fim - participante[j].questoes[i].inicio;
			cout << " min)\n";
		}
	}
	imprimirLinha('-',25);
	
	cout << endl;
	imprimirLinha('-',15);
	cout << "Estatísticas\n";
	imprimirLinha('-',15);
	
	//Imprimindo as estatísticas de cada questão
	ch = 'A';
	for(unsigned short i = 0; i < numeroQuestoes; i++, ch++) {
		//Função media(vetor, tamanho do vetor, índice inicial, tamanho do passo)
		Media estatisticasQuestao = media(questao,tamanhoVetorQuestoes,i,numeroParticipantes); 
		cout << "Questão " << ch << ": ";
		cout << "Dificuldade: (" << estatisticasQuestao.dificuldade << ") ";
		cout << "Tempo (" << estatisticasQuestao.tempo << " minutos)\n";
	}
	
	//Imprimindo as estatísticas gerais do concurso 
	cout << "Concurso: ";
	Media estatisticasConcurso = media(questao,tamanhoVetorQuestoes,0,1);
	cout << "Dificuldade: (" << estatisticasConcurso.dificuldade << ") ";
	cout << "Tempo (" << estatisticasConcurso.tempo << " minutos)\n\n";
	
	imprimirLinha('*',50);
	
	delete [] questao;
	delete [] participante;
}