def bubble(tam, lista):
    fim = tam - 1
    i = 0
    trocou = False
    while (i < fim):
        if lista[i] > lista[i+1]:
            trocou = True
            lista[i], lista[i + 1] = lista[i + 1], lista[i]
        i += 1
    if trocou: 
        bubble(fim - 1, lista)
        

# MAIN

lista = [2, 3, 1, 5, 4]
print(f"Vetor não ordenado: {lista}")
bubble(len(lista), lista)
print(f"Vetor ordenado: {lista}")
