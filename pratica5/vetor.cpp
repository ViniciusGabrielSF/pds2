#include "vetor.h"
#include <string>

using namespace std;

Vetor::Vetor (int inicio, int fim) {
    this->inicio_ = inicio;

    int tamanho = fim - inicio + 1;

    this-> elementos_ = new string[tamanho];
}

void Vetor::atribuir(int i, string valor){
    int indice = i - this->inicio_;

    this->elementos_[indice] = valor;
}

string Vetor::valor(int i) const {
    int indice = i - this->inicio_;

    return this->elementos_[indice];
} 

Vetor::~Vetor(){
    delete [] this->elementos_;
}