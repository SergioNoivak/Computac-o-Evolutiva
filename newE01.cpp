#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <math.h>
#define TAM_POP 10
#define PI           3.14159265358979323846  /* pi */
#define REPETICOES 100 // para definir uma nova populacao
#define TAXA_PERTURBACAO 1E8
#include<iostream>
#include<random> /*Gerador*/
#include<time.h>
#include<math.h>
#include<stdlib.h>
using namespace std;





default_random_engine gerador((unsigned) time(NULL));

using namespace std;

class individuo {
private:
    double valor;
    double aptidao;


public:
    individuo() {
    }

    void RefreshAptidao() {
        this->aptidao= this->valor * sin(10*PI*this->valor) + 5;
    }



    double GetAptidao() {
        return aptidao;
    }

    void SetValor(double valor) {
        this->valor = valor;
    }

    void RefreshValor() {
        uniform_real_distribution<double> distribuicao(0,4);
        this->valor=distribuicao(gerador);
        this->RefreshAptidao();
    }


    double GetValor() {
        return this->valor;
    }
};


int main() {

    individuo* populacao;
    individuo* nova_populacao;
    populacao = new individuo[TAM_POP];
    nova_populacao =new individuo[TAM_POP];

    for(int i=0; i<TAM_POP; i++) {
        populacao[i].RefreshValor();
        populacao[i].RefreshAptidao();
        printf("(%.5f , %.5f)\n",populacao[i].GetValor(),populacao[i].GetAptidao());
    }

    for(int j=0; j<REPETICOES; j++) {
        for(int i = 0; i<TAM_POP; i++) {
            uniform_real_distribution<double> distribuicao(-TAXA_PERTURBACAO,+TAXA_PERTURBACAO);
            double perturbacao =distribuicao(gerador);
            nova_populacao[i].SetValor(populacao[i].GetValor()+perturbacao);
            if(nova_populacao[i].GetValor()> 4) {
                nova_populacao[i].SetValor(4);
                nova_populacao[i].RefreshAptidao();
            }

            if (nova_populacao[i].GetValor()< 0) {
                nova_populacao[i].SetValor(0);
                nova_populacao[i].RefreshAptidao();
            }

            if(populacao[i].GetAptidao() < nova_populacao[i].GetAptidao()) {
                populacao[i].SetValor(nova_populacao[i].GetValor());
                populacao[i].RefreshAptidao();
            }
        }
    }

    cout<<endl;
    for(int i = 0; i<TAM_POP; i++) {

        printf("(%.5f , %.5f)\n",populacao[i].GetValor(),populacao[i].GetAptidao());
    }
    cout << endl << endl;

}
