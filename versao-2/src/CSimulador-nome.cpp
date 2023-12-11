//  Este programa exemplifica a estrutura de um programa típico em C++
#include <iostream>

// Inclui a declaração da classe
#include "CAplicacao.h" 

/** Note que no arquivo .cpp não é necessário colocar novamente a documentação
 * que foi colocada no arquivo .h. 
 * A documentação no arquivo .cpp costuma usar o padrão básico de C++ que é //
 * e costuma estar mais diretamente relacionada a implementação em sí,
 * ou seja, aos detalhes numéricos e computacionais; 
 * detalhes e explicação das contas e da lógica computacional.
 * */
void CAplicacao::Run()
{
  // std::cout escreve na tela  o texto "Bem-vindo ao C++!"
  std::cout << "Bem-vindo ao C++!" << std::endl;
}
