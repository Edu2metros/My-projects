#duplique, triplique e quaduplique o numero passado.

def multiplicar(numero):
    for i in range(2, 5):
        tmp = numero * i
        print("Numero: ", tmp)

multiplicar(20)