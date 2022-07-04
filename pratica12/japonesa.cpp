#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */

  std::string textoQuantidade  = std::to_string(m_qtd) + "X Comida japonesa - ";
  std::string textoCombinado = combinado + ", ";
  std::string textoSushis = std::to_string(sushis) + " sushis, ";
  std::string textoTemakis = std::to_string(temakis) + " temakis e ";
  std::string textoHots = std::to_string(hots) + " hots.";
  
  return textoQuantidade + textoCombinado + textoSushis + textoTemakis + textoHots;
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {

  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;

  this->combinado = combinado;
  this->sushis = sushis;
  this->temakis = temakis;
  this->hots = hots;
}