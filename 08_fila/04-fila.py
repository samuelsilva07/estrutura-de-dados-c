fila = []
senha = 1
while True:
    print(f"\nFila atual = {fila}\n")
    print(" I = Inserir cliente\n A = Atender cliente\n S = Sair\n")
    operacao = input("Digite as operaçôes que serão realizadas: ").lower().strip()
    if operacao == 'i':
        fila.append(senha)
        senha += 1
    elif operacao == 'a':
        if len(fila) == 0:
            print("\nA fila está vazia.")
        else:
            atendido = fila.pop()
            print(f"\nCliente nº {atendido} atendido!")
    elif operacao == 's':
        print("Fim do programa.\n")
        break
    else:
        print("Operação invalida!\n")