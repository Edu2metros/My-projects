#include <iostream>
#include <string>
#include <random>

std::string macaco_infinito(const std::string &palavra)
{
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    int len = palavra.size();
    
    while (true)
    {
        std::string random_word;
        for(int i = 0; i < len; i++)
        {
            char letra = alfabeto[gen() % alfabeto.size()];
            random_word.push_back(letra);
        }
        
        std::cout << random_word << std::endl; // Imprime a palavra gerada
        
        // Se a palavra gerada for igual à palavra desejada, retorna ela
        if(random_word == palavra)
            return random_word;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <palavra>" << std::endl;
        return 1;
    }
    
    std::string resultado = macaco_infinito(argv[1]);
    std::cout << "Palavra encontrada: " << resultado << std::endl;
    
    return 0;
}
