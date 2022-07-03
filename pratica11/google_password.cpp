#include "google_password.hpp"
#include "usuario.hpp"
#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  // TODO: Implemente este metodo
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */

  if(!checkPassword(password))
    return;

  Usuario usuario(login, password);

  m_passwords.insert(make_pair(url,usuario) );
 
}

void GooglePassword::remove(const std::string& url) {
  m_passwords.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */

  auto par = m_passwords.find(url);

  if(par == m_passwords.end())
    return;

  if(par->second.getPassword() != old_password)
    return;

  if(!checkPassword(new_password))
    return;

  par->second.setLogin(login);
  par->second.setPassword(new_password);

}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */

  
    std::cout << m_passwords.size() << std::endl;
    for (auto const& atual : m_passwords)
    {
      std::cout << atual.first << ": " << atual.second.getLogin() << " and " << atual.second.getPassword() << std::endl;
    }
}

bool GooglePassword::checkPassword(const std::string& password) const {
  if(password.find("123456") != std::string::npos)
    return false;

  if(password.size() > 50 || password.size() < 6)
        return false;

  if(password.find(" ") != std::string::npos)
    return false;

    return true;
}

