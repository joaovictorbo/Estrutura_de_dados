#ifndef PILHA_H
#define PILHA_H
struct noh {
int dado;
noh *prox;
};
class pilha {
private:
noh *ultimo;
noh *primeiro;
int tamanho;
public:
pilha();
~pilha();
bool vazia();
int obter_tamanho();
void inserir_final(int valor);
void retirar_final();
void imprimir();
};
#endif