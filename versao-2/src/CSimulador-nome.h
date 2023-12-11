// Este programa exemplifica a estrutura de um programa típico em C++.
// Note que no arquivo .h documentamos a interface; a forma de uso;
// No arquivo .cpp detalhes dos códigos; lógica numérica-computacional.
#include <string>
#include <vector>

/** Breve descrição da classe termina com ponto. 
 * ...descrição detalhada da classe...
 * ...pode ter várias linhas...
**/
class CAplicacao
{
public:    
    /// Descrição breve do construtor.
    /** Descrição detalhada do construtor. 
     *  ....blablabla....
     */
    CAplicacao()	{};
    
    /// Descrição breve do construtor.
    /** Descrição detalhada do construtor. 
     *  ....blablabla....
     */
   ~CAplicacao()	{};
   
   /// Apenas exibe mensagem na tela.
   void Run();
   
   /// Seta valor de x
   void X( int _x) 	{  x = _x; }
   
   /// Retorna valor de x 
   int X() 		{ return x; }
    
private:
    /// Descrição breve do método M1.
    /**
     * Descrição detalhada....
     * Posso incluir informações sobre parâmetros e retorno.
     * @param a um inteiro que representa ....
     * @param s uma string que representa ....
     * @return retorna ...
    */
    int M1(int a, std::string s);
       
    /// Descrição breve do atributo...
    /** Descrição detalhada do atributo... */
    std::vector<int> vy;

    /// Descrição breve do atributo...
    int x;
 
    int z; ///< Descrição breve (use apenas se for bem curta!).
    
    /// Enum representa (descrição breve).
    /** Descrição detalhada. */
    enum Enum { 
                 EVal1, ///< Breve descrição EVal1. 
                 EVal2, ///< Breve descrição EVal2. 
                 EVal3  ///< Breve descrição EVal3. 
               } ;
	       
    /// Descrição breve.
    /** Descrição detalhada. */
    Enum   variavelDoTipoEnumeracao;  
       
};
