#include "vetor.h"
#include <string>

Vetor::Vetor (int inicio, int fim) {
    this->inicio_ = inicio;

    int tamanho = fim - inicio + 1;

    this-> elementos_ = new string[tamanho];
}

void Vetor::atribuir(int i, std::string valor){
    
}

string Vetor::valor(int i) const {

} 

Vetor::~Vetor(){
    delete [] this->elementos_;
}