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

std::map<std::string, unsigned int> Estoque::get_estoque() const{
  return estoque;
}

void Estoque::imprime_estoque() const {
  for (auto const& atual : estoque)
  {
    std::cout << atual.first << ", " << atual.second << std::endl;
  }

}

Estoque& Estoque::operator += (const Estoque& rhs) {
  for (auto const& atual : rhs.get_estoque())
  {
    add_mercadoria(atual.first, atual.second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for (auto const& atual : rhs.get_estoque())
  {
    sub_mercadoria(atual.first, atual.second);
  }
  return *this;
}

bool validarComparaveis(Estoque& lhs, Estoque& rhs){
  auto estoqueRhs = rhs.get_estoque();

  for (auto const& atual : lhs.get_estoque())
  {
    if (estoqueRhs.find(atual.first) == estoqueRhs.end())
      return false;
  }
  return true;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  if(!validarComparaveis(lhs,rhs))
    return false;

  for (auto const& atual : lhs.get_estoque())
  {
    if (rhs.get_qtd(atual.first) <= lhs.get_qtd(atual.first))
      return false;
  }

  return true;

}

bool operator > (Estoque& lhs, Estoque& rhs) {
    if(!validarComparaveis(rhs, lhs))
    return false;

  for (auto const& atual : lhs.get_estoque())
  {
    if (rhs.get_qtd(atual.first) >= lhs.get_qtd(atual.first))
      return false;
  }

  return true;
}

