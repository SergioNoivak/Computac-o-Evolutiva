
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <math.h>
#define TAM_POP 10
#define PI           3.14159265358979323846  /* pi */
#define REPETICOES 100 // para definir uma nova populacao
#define TAXA_PERTURBACAO 1E8

using namespace std;

double fitness(double x){
	return x * sin(10*PI*x) + 5;
}

int main(){
	srand (time(NULL));
	double* populacao = NULL;
	double* nova_populacao = NULL;
	double* avaliacao = NULL;
	double perturbacao = 0;

	populacao = (double *) malloc(sizeof(double) * TAM_POP);
	nova_populacao = (double *) malloc(sizeof(double) * TAM_POP);
	avaliacao = (double *) malloc(sizeof(double) * TAM_POP);

	cout << "População: " << endl;
	for(int i=0; i<TAM_POP; i++){
		populacao[i] = ((rand() % 4000000) / 4000000.0 ) * 4;
		avaliacao[i] = fitness(populacao[i]);
		cout << "( " << populacao[i] << ", " << avaliacao[i] << ") ";
	}
	cout << endl << endl;

	for(int j=0; j<REPETICOES; j++){
		//cout << "Geração " << j <<endl;
		for(int i = 0; i<TAM_POP; i++){
			perturbacao = ((rand() % (int) TAXA_PERTURBACAO) /(1.0* TAXA_PERTURBACAO)) - 0.5;
			nova_populacao[i] = populacao[i] + perturbacao;
			if(nova_populacao[i] > 4){
				nova_populacao[i] = 4;
			}

			if (nova_populacao[i] < 0)
			{
				nova_populacao[i] = 0;
			}

			if(avaliacao[i] < fitness(nova_populacao[i])){
				populacao[i] = nova_populacao[i];
				avaliacao[i] = fitness(nova_populacao[i]);
			}
		}
		//cout << endl << endl;
	}

	for(int i = 0; i<TAM_POP; i++){
			cout << "( " << populacao[i] << ", " << avaliacao[i] << ") ";
	}
	cout << endl << endl;

}
