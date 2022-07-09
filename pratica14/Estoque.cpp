#include <string>
#include <iostream>
#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {

  if(estoque.find(mercadoria) != estoque.end())
      estoque[mercadoria] += qtd;
  else 
      estoque[mercadoria] = qtd;
    
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  auto parMercadoria = estoque.find(mercadoria);

  if(parMercadoria == estoque.end()){
    std::cout << mercadoria << " inexistente" << std::endl;
    return;
  }

  if(parMercadoria->second < qtd ){
    std::cout << mercadoria << " insufisciente" << std::endl;
    return;
  }

  parMercadoria->second -= qtd;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
   auto parMercadoria = estoque.find(mercadoria);

  if(parMercadoria == estoque.end())
    return 0;
  
  return parMercadoria->second;
}


void Estoque::imprime_estoque() const {
  for (auto const& atual : estoque)
  {
    std::cout << atual.first << ", " << atual.second << std::endl;
  }

}

Estoque& Estoque::operator += (const Estoque& rhs) {
  for (auto const& atual : rhs.estoque)
  {
    add_mercadoria(atual.first, atual.second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for (auto const& atual : rhs.estoque)
  {
    sub_mercadoria(atual.first, atual.second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  for (auto const& atual : lhs.estoque)
  {
    std::string nomeMercadoria = atual.first; 

    if (rhs.estoque.find(nomeMercadoria) == rhs.estoque.end())
      return false;

    if (rhs.get_qtd(nomeMercadoria) <= lhs.get_qtd(nomeMercadoria))
      return false;
  }

  return true;

}

bool operator > (Estoque& lhs, Estoque& rhs) {

  for (auto const& atual : rhs.estoque)
  {
    std::string nomeMercadoria = atual.first; 

    if (lhs.estoque.find(nomeMercadoria) == lhs.estoque.end())
      return false;

    if (rhs.get_qtd(nomeMercadoria) >= lhs.get_qtd(nomeMercadoria))
      return false;
  }

  return true;
}

