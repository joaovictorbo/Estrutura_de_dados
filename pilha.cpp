#include <iostream>
#include <cstdlib>
#include "pilha.h"
using namespace std;

pilha::pilha() {
primeiro = NULL;
ultimo = NULL;
tamanho = 0;
}

pilha::~pilha() {
noh *atual = primeiro;
while (atual != NULL) {
noh *temp = atual;
atual = atual->prox;
delete temp;
}
}

bool pilha::vazia() {
return (primeiro == NULL);
}

int pilha::obter_tamanho() {
return tamanho;
}

void pilha::inserir_final(int valor) {
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


void pilha::retirar_final() {
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


void pilha::imprimir() {
noh *atual = primeiro;
while (atual != NULL) {
cout << atual->dado << " ";
atual = atual->prox;
}
cout << endl;
}

int main() {
pilha l;
l.inserir_final(40);
l.inserir_final(50);
l.inserir_final(60);
l.imprimir();
l.retirar_final();
l.imprimir();
return 0;
}