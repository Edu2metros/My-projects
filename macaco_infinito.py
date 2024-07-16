import random

alfabeto = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def macaco_infinito():
    palavra = ""
    while True:
        letra = random.choice(alfabeto)
        palavra += letra
        print(letra, end="")
        if palavra.endswith("macaco"):
            return

macaco_infinito()
