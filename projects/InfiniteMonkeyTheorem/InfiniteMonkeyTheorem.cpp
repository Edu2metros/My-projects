#include <iostream>
#include <string>
#include <random>
#include <gmp.h>

std::string monkey_infinite(const std::string &word, mpz_t &attempts) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);
    int len = word.size();

    mpz_set_ui(attempts, 0);

    while (true) {
        std::string random_word(len, '\0');
        for (int i = 0; i < len; ++i) {
            random_word[i] = characters[dis(gen)];
        }

        mpz_add_ui(attempts, attempts, 1);
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
    
    mpz_t attempts;
    mpz_init(attempts);

    std::string result = monkey_infinite(argv[1], attempts);
    std::cout << "Word found: " << result << std::endl;
    std::cout << "Attempts: ";
    mpz_out_str(stdout, 10, attempts);
    std::cout << std::endl;
    
    mpz_clear(attempts);

    return 0;
}
