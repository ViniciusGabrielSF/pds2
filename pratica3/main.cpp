#include <iostream>
#include <map>  // Isto é uma dica. 
#include <string>

using namespace std;

string obterMaisFrequente(map<string, int> contador){
    int frequencia = 0;
    string maisFrequente;  
    for (auto const& atual : contador)
    {
        if(atual.second > frequencia){
            maisFrequente = atual.first;
            frequencia = atual.second;
        }
    }

    return maisFrequente;
}

int main() {
    string palavra;
    map<string, int> contador;
    
    while (cin >> palavra){
        if(contador.find(palavra) != contador.end())
            contador[palavra]++;
        else 
            contador[palavra] = 1;
    };
    
    cout << obterMaisFrequente(contador) << endl;

    return 0;
}