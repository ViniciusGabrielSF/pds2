#include "pedido.hpp"


Pedido::~Pedido() {
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
    while (!m_produtos.empty())
    {
      delete m_produtos.back();
      m_produtos.pop_back();
    }

}

void Pedido::setEndereco(const std::string& endereco) {
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float total = 0;

    for (auto const& atual : m_produtos)
    {
      total += atual->getValor() * atual->getQtd();
    }

  return total;
}

void Pedido::adicionaProduto(Produto* p) {
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
    std::string resumo = "";

    for (auto const& atual : m_produtos)
    {
      resumo += atual->descricao() + "\n";
    }
    resumo += "Endereco: " + m_endereco;
    
  return resumo;
}