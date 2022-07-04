#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
    while (!m_pedidos.empty())
    {
      delete m_pedidos.back();
      m_pedidos.pop_back();
    }
}

void Venda::adicionaPedido(Pedido* p) {
    m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */

    float total = 0;
    int numPedido = 0;
    for (auto const& atual : m_pedidos)
    {
      numPedido++;
      total += atual->calculaTotal();

      std::cout << "Pedido " << numPedido  << std::endl;
      std::cout << atual->resumo() << std::endl;

    } 

    std::cout << "Relatorio de Vendas" << std::endl;
    std::cout << "Total de vendas: R$" << total << std::endl;
    std::cout << "Total de pedidos: " << numPedido << std::endl;

  
}