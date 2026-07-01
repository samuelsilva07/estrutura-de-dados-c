# MAIN

pilha = []
numeroPilha = 1
while True:
    print(f"\nPilha atual = {pilha}\n")
    print("I = Inserir (Pull)\nR = Remover (Pop)\nS = Sair\n")
    operacao = input("Escolha a operação a ser realizada: ").lower()
    if operacao == 'i':
        pilha.append(numeroPilha)
        numeroPilha += 1
    elif operacao == 'r':
        if len(pilha) == 0:
            print("A pilha está vazia.")
        else:
            del pilha[-1]
            numeroPilha -= 1
    elif operacao == 's':
        print("Fim do programa.\n")
        break
    else:
        print("Operação invalida!\n")

        