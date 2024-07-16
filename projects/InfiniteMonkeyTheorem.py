import sys
import random
import string

def monkey_infinite(word):
    characters = string.ascii_letters
    len_word = len(word)

    while True:
        random_word = ''.join(random.choice(characters) for _ in range(len_word))
        print(random_word)

        if random_word == word:
            return random_word

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage:", sys.argv[0], "<word>")
        sys.exit(1)

    result = monkey_infinite(sys.argv[1])
    print("Word found:", result)
