#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
  std::string textoQuantidade  = std::to_string(m_qtd) + "X ";
  std::string textoTipo = "Hamburguer " + tipo;
  std::string textoArtesanal = " " + std::string(artesanal ? "artesanal." : "simples.");
  return textoQuantidade + textoTipo + textoArtesanal;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;

  this->tipo = tipo;
  this->artesanal = artesanal;
}