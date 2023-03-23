/*1. Criação da lista vazia;
2. Verificar se a lista está vazia;
3. Obter o tamanho da lista;
4. Obter/modificar o valor do elemento de uma determinada
posição na lista;
5. Inserir um elemento em uma determinada posição;
6. Retirar um elemento de uma determinada posição.
7. Imprimir os elementos de toda a lista. */

#include <iostream>
#include <cstdlib>
#include "lista_dinamica.h"
using namespace std;

lista::lista() {
primeiro = NULL;
ultimo = NULL;
tamanho = 0;
}

lista::~lista() {
noh *atual = primeiro;
while (atual != NULL) {
noh *temp = atual;
atual = atual->prox;
delete temp;
}
}

bool lista::vazia() {
return (primeiro == NULL);
}

int lista::obter_tamanho() {
return tamanho;
}

void lista::inserir_inicio(int valor) {
noh *novo = new noh;
novo->dado = valor;
novo->prox = primeiro;
primeiro = novo;
if (ultimo == NULL)
ultimo = novo;
tamanho++;
}

void lista::inserir_final(int valor) {
noh *novo = new noh;
novo->dado = valor;
novo->prox = NULL;
if (ultimo != NULL)
ultimo->prox = novo;
ultimo = novo;
if (primeiro == NULL)
primeiro = novo;
tamanho++;
}

void lista::inserir_posicao(int valor, int posicao) {
if (posicao == 0)
inserir_inicio(valor);
else if (posicao == tamanho)
inserir_final(valor);
else if (posicao > 0 && posicao < tamanho) {
noh *novo = new noh;
novo->dado = valor;
noh *anterior = primeiro;
for (int i = 0; i < posicao - 1; i++)
anterior = anterior->prox;
novo->prox = anterior->prox;
anterior->prox = novo;
tamanho++;
}
}

void lista::retirar_inicio() {
if (primeiro != NULL) {
noh *temp = primeiro;
primeiro = primeiro->prox;
delete temp;

if (primeiro == NULL)
ultimo = NULL;
tamanho--;
}
}

void lista::retirar_final() {
if (ultimo != NULL) {
noh *anterior = primeiro;
while (anterior->prox != ultimo)
anterior = anterior->prox;
delete ultimo;
ultimo = anterior;
if (ultimo == NULL)
primeiro = NULL;
else
ultimo->prox = NULL;
tamanho--;
}
}

void lista::retirar_posicao(int posicao) {
if (posicao == 0)
retirar_inicio();
else if (posicao == tamanho - 1)
retirar_final();
else if (posicao > 0 && posicao < tamanho - 1) {
noh *anterior = primeiro;
for (int i = 0; i < posicao - 1; i++)
anterior = anterior->prox;
noh *temp = anterior->prox;
anterior->prox = temp->prox;
delete temp;
tamanho--;
}
}

void lista::imprimir() {
noh *atual = primeiro;
while (atual != NULL) {
cout << atual->dado << " ";
atual = atual->prox;
}
cout << endl;
}

int main() {
lista l;
l.inserir_inicio(10);
l.inserir_inicio(20);
l.inserir_inicio(30);
l.inserir_final(40);
l.inserir_final(50);
l.inserir_final(60);
l.inserir_posicao(70, 3);
l.inserir_posicao(80, 6);
l.inserir_posicao(90, 0);
l.inserir_posicao(100, 9);
l.imprimir();
l.retirar_inicio();
l.retirar_final();
l.retirar_posicao(3);
l.imprimir();
return 0;
}


