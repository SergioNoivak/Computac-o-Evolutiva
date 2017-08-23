#include<iostream>
#include<random>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415927
using namespace std;
/**
1.	Gerar população inicial.
2.	Avaliar população inicial
3.	Repita
    Selecione 1 individuo
    Mute o individuo selecionado
    Avalie o indivíduo
    Se(aptidão>=pai)
          Copie este individuo i para o pai
Senão, copie seu pai.
                   Até completar a nova geração
             Até parada
*/


default_random_engine generator((unsigned) time(NULL));

typedef struct ind {
    double valor;
    double aptidao;
} individuo;

double fitness(double x) {

    return x*sin(10*PI*x)+5;
}


void criar_populacao_inicial(individuo* vetor, int size_v) {


    for(int i=0; i<size_v; i++) {
        uniform_real_distribution<double> distribution(0,4);
        vetor[i].valor=distribution(generator);
        vetor[i].aptidao=fitness(vetor[i].valor);

    }
}


double soma_aptidoes(individuo* vetor, int size_v) {

    double ac=0;
    for(int i=0; i<size_v; i++)
        ac+=vetor[i].aptidao;

    return ac;

}
int selecionar(individuo* vetor, int size_v, double soma) {

    uniform_real_distribution<double> distribution(0,soma);
    double p = distribution(generator);
    double Tparcial=0;
    int i=-1;
    while((i<size_v) &&(Tparcial<p)) {
        i++;
        Tparcial+=vetor[i].aptidao;
    }
    return i;

}


double mutar(double valor) {

    uniform_real_distribution<double> distribution(-0.5,0.5);
    double perturbacao= distribution(generator);
    valor+=perturbacao;
    if (valor >= 4){
        valor = 4;
    }
    else if (valor <= 0) {
        valor = 0;
    }

    return valor;
}


void print_vetor(individuo* vetor,int size_v){

cout<<endl;
cout<<"{";
    for(int i=0;i<size_v;i++)
        cout<<"("<<vetor[i].valor<<" , "<<vetor[i].aptidao<<" )"<<endl;

}


int main() {
    individuo vetor[10];
    individuo novo_vetor[10];
    int i=0;
    int contador_de_geracoes=0;
    criar_populacao_inicial(vetor,10);
    //print_vetor(vetor,10);
    do {
        double soma= soma_aptidoes(vetor,10);
        i=0;
        do {

            int index=selecionar(vetor,10,soma);
            double novo_valor=mutar(vetor[index].valor);
            double nova_aptidao=fitness(novo_valor);
            if(nova_aptidao>=vetor[index].aptidao) {
                novo_vetor[i].valor=novo_valor;
                novo_vetor[i].aptidao = nova_aptidao;

            } else {
                novo_vetor[i].valor=vetor[index].valor;
                novo_vetor[i].aptidao = vetor[index].aptidao;
            }
            i++;
        } while(i<10);
        //print_vetor(novo_vetor,10);

        ///passar pro antigo o vetor novo
        for(int coun=0;coun<10;coun++){
         vetor[coun].valor=novo_vetor[coun].valor;
         vetor[coun].aptidao=novo_vetor[coun].aptidao;
        }
        contador_de_geracoes++;
    }
    while(contador_de_geracoes<400);

    print_vetor(vetor,10);
    return 0;
}
/**

    (3.85026 , 8.85013)

*/
