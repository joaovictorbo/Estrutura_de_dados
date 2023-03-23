#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H
struct noh {
int dado;
noh *prox;
};
class lista {
private:
noh *primeiro;
noh *ultimo;
int tamanho;
public:
lista();
~lista();
bool vazia();
int obter_tamanho();
void inserir_inicio(int valor);
void inserir_final(int valor);
void inserir_posicao(int valor, int posicao);
void retirar_inicio();
void retirar_final();
void retirar_posicao(int posicao);
void imprimir();
};
#endif