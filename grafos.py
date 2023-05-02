# Classe Grafo

import numpy as np
import pandas as pd
class Grafo:
    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = np.zeros((vertices, vertices))
        
    def reset(self):
        self.visitados = [False] * self.vertices
        self.pilha = []
        self.caminho = []

    # Adiciona arestas
    def add_aresta(self, u, v, peso=1):
        self.grafo[u-1][v-1] = peso
        self.grafo[v-1][u-1] = peso

    # Mostra o grafo
    def show(self):
        for i in self.grafo:
            for j in i:
                print(j, end=' ')
            print()

    # Busca em largura
    def bfs(self, inicio, fim):
        self.reset()
        self.caminho.append(inicio)
        self.visitados[inicio-1] = True
        self.pilha.append(inicio-1)
        while len(self.pilha) > 0:
            for i in range(self.vertices):
                if self.grafo[self.pilha[0]][i] > 0 and not self.visitados[i]:
                    self.caminho.append(i+1)
                    self.visitados[i] = True
                    self.pilha.append(i)
            self.pilha.pop(0)
        if not self.visitados[fim-1]:
            print('Não há caminho entre os vértices')
        else:
            print(self.caminho)

    # Busca em profundidade
    def dfs(self, inicio, fim):
        self.reset()
        self.caminho.append(inicio)
        self.visitados[inicio-1] = True
        self.pilha.append(inicio-1)
        while len(self.pilha) > 0:
            for i in range(self.vertices):
                if self.grafo[self.pilha[-1]][i] > 0 and not self.visitados[i]:
                    self.caminho.append(i+1)
                    self.visitados[i] = True
                    self.pilha.append(i)
                    break
                elif i == self.vertices-1:
                    self.pilha.pop()
            if self.pilha[-1] == fim-1:
                break
        if not self.visitados[fim-1]:
            print('Não há caminho entre os vértices')
        else:
            print(self.caminho)

g = Grafo(8)
g.add_aresta(1, 2)
g.add_aresta(1, 3)
g.add_aresta(2, 4)
g.add_aresta(2, 5)
g.add_aresta(3, 6)
g.add_aresta(5, 8)
g.add_aresta(6, 8)
g.add_aresta(7, 8)
g.show()
g.bfs(1, 8)
g.dfs(1, 8)


