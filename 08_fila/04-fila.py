import time
import os

def menu(fila):  
    print(f"\nFila atual = {fila}\n")
    print(" I = Inserir cliente\n A = Atender cliente\n S = Sair\n")

fila = []
senha = 1
OK = 1

while OK:
    os.system("cls")
    inseridos = 0 
    atendidos = 0
    menu(fila)
    operacao = input("Digite as operações que serão realizadas: ").lower().strip()

    for letra in operacao:
        if letra == 's':
            print("Fim do programa.\n")
            OK = 0
            break
        elif letra == 'i':
            fila.append(senha)
            senha += 1
            inseridos += 1
        elif letra == 'a':
            if len(fila) == 0:
                print("\nA fila está vazia.")
                time.sleep(2)
            else:
                atendido = fila.pop(0)
                print(f"\nCliente nº {atendido} atendido!")
                atendidos += 1
                time.sleep(2)
        else:
            print("Operação invalida, tente novamente.\n")

    if inseridos > 0: 
        print(f"Clientes inseridos = {inseridos}")
        time.sleep(2)
    if atendidos > 0:
        print(f"Clientes atendidos = {atendidos}")
        time.sleep(2)