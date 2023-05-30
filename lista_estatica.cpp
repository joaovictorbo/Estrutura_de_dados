#include "lista_estatica.h"
#include <iostream>

using namespace std;

lista_estatica::lista_estatica(int tamanho_maximo) {
    lista = new int[tamanho_maximo];
    tamanho = 0;
    this->tamanho_maximo = tamanho_maximo;
}

lista_estatica::~lista_estatica() {
    delete[] lista;
}

void lista_estatica::insere(int elemento) {
    if (tamanho < tamanho_maximo) {
        lista[tamanho] = elemento;
        tamanho++;
    } else {
        cout << "Lista cheia!" << endl;
    }
}

void lista_estatica::remove(int elemento) {
    int posicao = busca(elemento);
    if (posicao != -1) {
        for (int i = posicao; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    } else {
        cout << "Elemento nao encontrado!" << endl;
    }
}

void lista_estatica::imprime() {
    for (int i = 0; i < tamanho; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

int lista_estatica::busca(int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            return i;
        }
    }
    return -1;
}

int lista_estatica::get_tamanho() {
    return tamanho;
}

int lista_estatica::get_tamanho_maximo() {
    return tamanho_maximo;
}

int lista_estatica::get_elemento(int posicao) {
    if (posicao >= 0 && posicao < tamanho) {
        return lista[posicao];
    } else {
        cout << "Posicao invalida!" << endl;
        return -1;
    }
}

int main() {
    lista_estatica lista(10);
    lista.insere(10);
    lista.insere(20);
    lista.insere(30);
    lista.insere(40);
    lista.insere(50);
    lista.imprime();
    lista.remove(30);
    lista.imprime();
    cout << lista.get_elemento(2) << endl;
    cout << lista.get_elemento(10) << endl;
    return 0;
}