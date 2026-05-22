def insertion(lista):
    i = 0
    for i in lista:
        j = i - 1
        while j > 0:
            if (lista[j - 1] > lista[j]):
                lista[j - 1], lista[j] = lista[j], lista[j - 1]
            j -= 1

# MAIN

lista = [2, 3, 1, 5, 4]
print(lista)
insertion(lista)
print(lista)
