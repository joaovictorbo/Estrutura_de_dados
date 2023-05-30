class lista_estatica {
private:
    int *lista;
    int tamanho;
    int tamanho_maximo;
public:
    lista_estatica(int tamanho_maximo);
    ~lista_estatica();
    void insere(int elemento);
    void remove(int elemento);
    void imprime();
    int busca(int elemento);
    int get_tamanho();
    int get_tamanho_maximo();
    int get_elemento(int posicao);
};

