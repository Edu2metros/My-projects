#include <iostream>
#include <string>
#include <random>

std::string monkey_infinite(const std::string &word) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);
    int len = word.size();

    while (true) {
        std::string random_word(len, '\0');
        for (int i = 0; i < len; ++i) {
            random_word[i] = characters[dis(gen)];
        }
        
        std::cout << random_word << std::endl;

        if (random_word == word) {
            return random_word;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <word>" << std::endl;
        return 1;
    }
    
    std::string result = monkey_infinite(argv[1]);
    std::cout << "Word found: " << result << std::endl;
    
    return 0;
}
