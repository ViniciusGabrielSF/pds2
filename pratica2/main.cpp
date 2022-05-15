#include <iostream>
#include <string>

using namespace std;


void imprimeQuantidadeCaracteresIguais(string palavra, char caractere){
    int quantidade = 0;

    for(char atual : palavra){
        if(atual == caractere)
            quantidade++;
    }
    
    quantidade > 0 && cout << caractere << " " << quantidade << endl;
}

int main() {
    string palavra;

    cin >> palavra;

    imprimeQuantidadeCaracteresIguais(palavra, 'a');
    imprimeQuantidadeCaracteresIguais(palavra, 'e');
    imprimeQuantidadeCaracteresIguais(palavra, 'i');
    imprimeQuantidadeCaracteresIguais(palavra, 'o');
    imprimeQuantidadeCaracteresIguais(palavra, 'u');
    
    return 0;
}