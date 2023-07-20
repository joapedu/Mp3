#ifndef NO_HPP
#define NO_HPP

// classe do nó da lista encadeada
template <typename T>
class No {

    T valor;
    No<T> *proximo;

public:
    // construtor padrão
    No() = default;
    
    // construtor que recebe o valor a ser colocado no nó
    No(const T &valor);
    
    // valor do nó atual
    T &getValor();
    
    // ponteiro para o próximo nó
    No *getProximo();
    
    // altera o valor do nó atual
    void setValor(T valor);
    
    // altera o ponteiro para o próximo nó
    void setProximo(No<T> *proximo);
};

// construtor do valor a ser colocado no nó
template <typename T>
No<T>::No(const T &valor){
    setValor(valor);
    setProximo(nullptr);
}

// valor do nó
template <typename T>
T &No<T>::getValor(){
    return valor;
}

// ponteiro para o próximo nó
template <typename T>
No<T> *No<T>::getProximo(){
    return proximo;
}

// altera o valor do nó
template <typename T>
void No<T>::setValor(T valor){
    this->valor = valor;
}

// ponteiro para o próximo elemento
template <typename T>
void No<T>::setProximo(No<T> *proximo){
    this->proximo = proximo;
}

#endif
