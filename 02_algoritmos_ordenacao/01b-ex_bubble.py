def bubble(lista):
    fim = len(lista) - 1
    while(fim > 1):
        i = 0
        trocou = False
        while (i < fim):
            if lista[i] > lista[i+1]:
                trocou = True
                lista[i], lista[i + 1] = lista[i + 1], lista[i]
            i += 1
        if not trocou: 
            break
        fim -= 1

# MAIN

lista = [2, 3, 1, 5, 4]

print(f"Vetor não ordenado: {lista}")
bubble(lista)
print(f"Vetor ordenado: {lista}")
