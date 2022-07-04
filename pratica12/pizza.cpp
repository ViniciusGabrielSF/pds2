#include "pizza.hpp"


std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */

  std::string textoQuantidade  = std::to_string(m_qtd) + "X ";
  std::string textoSabor = "Pizza " + sabor;
  std::string textoPedacos = ", " +  std::to_string(pedacos) + " pedacos e ";
  std::string textoBorda =  (borda_recheada ? "" : "sem ") +  std::string("borda recheada.");

  return textoQuantidade + textoSabor + textoPedacos + textoBorda;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario){
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;

  this->sabor = sabor;
  this->pedacos = pedacos;
  this->borda_recheada = borda_recheada;

}