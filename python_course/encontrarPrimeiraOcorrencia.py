def checkDuplicado(numbers):
    array = [-1, -1]
    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            if numbers[i] == numbers[j]:
                if array[0] == -1 or array[1] > j:
                    array[0] = numbers[i]
                    array[1] = j
    return array[0]

numeros = [1, 2, 3, 4, 4, 2]
result = checkDuplicado(numeros)

if(result != -1):
    print("Primeira ocorrência duplicada: ", result)
else:
    print("Não há ocorrência duplicada")
