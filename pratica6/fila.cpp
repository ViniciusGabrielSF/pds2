#include "fila.h"

Fila::Fila () {
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
    this->tamanho_ = 0;
}

string Fila::primeiro () {
    return this->primeiro_->chave;
}

string Fila::ultimo () {
    return  this->ultimo_->chave;
}

bool Fila::vazia() {
    return this->primeiro_ == nullptr && this->ultimo_ == nullptr && this->tamanho_ == 0;
}


void Fila::Inserir(string k) {
    No *novo = new No{k, nullptr};

    if(this->tamanho_ == 0)
        this->primeiro_ = novo;
     else 
        this->ultimo_->proximo = novo;

    this->ultimo_ = novo;
    this->tamanho_++;      
}

void Fila::Remover() {
    No* primeiro = this->primeiro_;
    
    if(this->tamanho_ == 1)
        this->ultimo_ = nullptr;

    this->primeiro_ = primeiro->proximo;
    this->tamanho_--;

    delete primeiro;
}

int Fila::tamanho() {
    return this->tamanho_;
}

Fila::~Fila() {
    while(!vazia()){
        Remover();
    }
}