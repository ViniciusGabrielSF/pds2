#include "jogo_da_vida.h"
#include <cassert>

// Inicializa vivas_ como um vetor com l elementos.
// Cada elemento, por sua vez, é um vetor com c elementos iguais a false.
JogoDaVida::JogoDaVida(int l, int c) 
    : vivas_(l, std::vector<bool>(c, false)) {
}

void validarCoordenadas(int i, int linhas, int j, int colunas){
    assert(i >= 0 && i < linhas);
    assert(j >= 0 && j < colunas);
}

bool JogoDaVida::viva(int i, int j) {
    validarCoordenadas(i, this->linhas(),j , this->colunas() );
    
  return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j) {
    validarCoordenadas(i, this->linhas(),j , this->colunas() );
    assert(vivas_[i][j] == true);
    
  vivas_[i][j] = false;
}
void JogoDaVida::Reviver(int i, int j) {
    validarCoordenadas(i, this->linhas(),j , this->colunas() );
    assert(vivas_[i][j] == false);
    
  vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
    validarCoordenadas(x, this->linhas(),y , this->colunas() );
    
  int vizinhas_vivas = 0;
  for (int i : {x - 1, x, x + 1}) {
    for (int j : {y - 1, y, y + 1}) {
      if (i != x || j != y) {  // Não conta a própria célula [x, y].
        int i_circular = (i + linhas()) % linhas();   
        int j_circular = (j + colunas()) % colunas();
        if (viva(i_circular, j_circular)) {
          vizinhas_vivas++;
        }
      }
    }
  }
  return vizinhas_vivas;
}

void JogoDaVida::ExecutarProximaIteracao() {
  JogoDaVida novo(linhas(), colunas());  // Cria um novo objeto, com todas as 
                                         // células mortas.
  for (int i = 0; i < linhas(); i++) {
    for (int j = 0; j < colunas(); j++) {
      int n = NumeroDeVizinhasVivas(i, j);
       if(n == 3 || (n == 2 && viva(i, j))) {
         novo.Reviver(i, j);
       } 
    }
  } 
  *this = novo;
}

void JogoDaVida::Executar(int n) {
    assert(n >= 1);
    
  for (int i = 0; i < n; i++) {
    ExecutarProximaIteracao();
  }
}
