def selection(lista):
    for i in range(len(lista) - 1):
        menor = i
        for j in range(i + 1, len(lista)):
            if lista[j] < lista[menor]:
                menor = j
        if menor != i:
            lista[i], lista[menor] = lista[menor], lista[i]

lista = [2, 3, 1, 5, 4]
print(lista)
selection(lista)
print(lista)