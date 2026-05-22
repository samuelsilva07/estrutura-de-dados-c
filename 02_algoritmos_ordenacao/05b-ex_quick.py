def quick(vet, inicio=0, fim=None):
    if fim == None: fim = len(vet) - 1
    if fim > inicio:
        pivo = vet[inicio]
        a = inicio + 1
        b = fim 
        while True:
            while (a < fim) and (vet[a] <= pivo): a += 1
            while vet[b] > pivo: b -= 1
            if a < b:
                vet[b], vet[a] = vet[a], vet[b]
                a += 1
                b -= 1
            if (a >= b): 
                break
        vet[inicio] = vet[b]
        vet[b] = pivo
        quick(vet, 0, b - 1)
        quick(vet, a, fim)

# main

lista = [2, 3, 1, 5, 4]
print(lista)
quick(lista)
print(lista)
