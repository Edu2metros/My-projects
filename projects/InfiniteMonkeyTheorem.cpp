#include <iostream>
#include <string>
#include <random>

std::string macaco_infinito(const std::string &palavra) {
    const std::string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, caracteres.size() - 1);
    int len = palavra.size();

    while (true) {
        std::string random_word(len, '\0');
        for (int i = 0; i < len; ++i) {
            random_word[i] = caracteres[dis(gen)];
        }
        
        std::cout << random_word << std::endl;

        if (random_word == palavra) {
            return random_word;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <palavra>" << std::endl;
        return 1;
    }
    
    std::string resultado = macaco_infinito(argv[1]);
    std::cout << "Palavra encontrada: " << resultado << std::endl;
    
    return 0;
}
