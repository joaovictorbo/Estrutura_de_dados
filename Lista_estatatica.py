import numpy as np

lista = np.array([0,0,0,0,0,0,0,0,0,0])

def lista_vazia():
    if lista[0] == 0:
        return True
    else:
        return False

def obtem_ultimo_elemento():
    for i in range(0,10):
        if lista[i] == 0:
            return i-1
    return "lista cheia"

def insere_elemento(posicao,elemento):
    if lista_vazia() == True:
        lista[0] = elemento
    elif obtem_ultimo_elemento() == "lista cheia":
        print("lista cheia")
    else:
        for i in range(obtem_ultimo_elemento(),posicao-1,-1):
            lista[i+1] = lista[i]
        lista[posicao] = elemento

def remove_elemento(posicao):
    if lista_vazia() == True:
        print("lista vazia")
    else:
        for i in range(posicao,obtem_ultimo_elemento()):
            lista[i] = lista[i+1]
        lista[obtem_ultimo_elemento()] = 0
