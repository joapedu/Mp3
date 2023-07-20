#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include <iostream>
#include "musica.hpp"
#include "no.hpp"

// classe que implementa a lista encadeada

template <typename T>
class ListaEncadeada {

private:
    No<T> *cabeca;
    No<T> *cauda;

public:
    //construtor da lista encadeada. 
    ListaEncadeada();
    
    //construtor cópia da lista encadeada.
    ListaEncadeada(const ListaEncadeada<T> &outra);
    
    //destrutor da lista encadeada, que remove todos os elementos.
    ~ListaEncadeada();
    
    //remove todos os elementos da lista. 
    void limpar();
    
    //retorna o tamanho da lista encadeada. 
    size_t getTamanho() const;
    
    //retorna o início da lista. 
    No<T> *getCabeca() const;
    
    //retorna o final da lista. 
    No<T> *getCauda() const;
    
    //altera o ponteiro cabeça da lista. 
    void setCabeca(No<T> *cabeca);
    
    //altera o ponteiro cauda da lista. 
    void setCauda(No<T> *cauda);
    
    //adiciona um novo elemento com valor especificado ao final da lista. 
    void adicionar(T valor);
    
    //adiciona todos os elementos de uma lista ao final da lista.
    void adicionar(const ListaEncadeada<T> &outra);
    
    //procura um elemento específico na lista. 
    T *buscarValor(T valor);
    
    //remove o elemento no índice especificado da lista.
    void removerFinal();
    
    //remove o elemento especificado da lista. 
    int removerValor(T valor);
    
    //remove todos os elementos de uma lista da lista.
    void removerValor(ListaEncadeada<T> &outra);
    
    //imprime todos os elementos da lista recursivamente. 
    void imprimir();
    
    //sobrecarga de operador de soma, que concatena duas listas.
    ListaEncadeada<T> operator+(ListaEncadeada<T> &outra);
    
    //sobrecarga de operador de extração, que remove um elemento da lista.
    const ListaEncadeada<T> &operator>>(No<T> &no);
    
    //sobrecarga de operador de inserção, que adiciona um elemento à lista.
    const ListaEncadeada<T> operator<<(const No<T> &no);
};

//construtor
template <typename T>
ListaEncadeada<T>::ListaEncadeada() {
    cabeca = nullptr;
    cauda = nullptr;
}

template <typename T>
ListaEncadeada<T>::ListaEncadeada(const ListaEncadeada<T> &outra) {
    cabeca = nullptr;
    cauda = nullptr;

    adicionar(outra);
}

//destrutor da lista encadeada, que remove todos os elementos.
template <typename T>
ListaEncadeada<T>::~ListaEncadeada() {
    limpar();
}

//remove todos os elementos da lista
template <typename T>
void ListaEncadeada<T>::limpar() {
    No<T> *anterior = nullptr;
    No<T> *atual = cabeca;

    while (atual != nullptr) {
        anterior = atual;
        atual = atual->getProximo();
        delete anterior;
    }
    cabeca = nullptr;
    cauda = nullptr;
}

//traz o tamanho da lista
template <typename T>
size_t ListaEncadeada<T>::getTamanho() const {
    size_t tamanho = 0;
    No<T> *atual = cabeca;

    while (atual != nullptr) {
        atual = atual->getProximo();
        tamanho++;
    }
    return tamanho;
}

//retorna a cabeça da lista
template <typename T>
No<T> *ListaEncadeada<T>::getCabeca() const {
    return cabeca;
}

//retorna o final da lista  
template <typename T>
No<T> *ListaEncadeada<T>::getCauda() const {
    return cauda;
}

//altera o ponteiro incial da lista
template <typename T>
void ListaEncadeada<T>::setCabeca(No<T> *cabeca) {
    this->cabeca = cabeca;
}

//altera o ponteiro final
template <typename T>
void ListaEncadeada<T>::setCauda(No<T> *cauda) {
    this->cauda = cauda;
}

//coloca um elemento especifico ao final da lista
template <typename T>
void ListaEncadeada<T>::adicionar(T valor) {
    No<T> *novoNo = new No<T>(valor);

    // Verifica se a lista é vazia
    if (cabeca == nullptr) {
        cabeca = novoNo;
        cauda = novoNo;
    } else {
        cauda->setProximo(novoNo);
        cauda = novoNo;
    }
}

//adiciona uma lista ao final da outra lista.
template <typename T>
void ListaEncadeada<T>::adicionar(const ListaEncadeada<T> &outra) {
    No<T> *noAtual = outra.getCabeca();
    
    while (noAtual != nullptr) {
        this->adicionar(noAtual->getValor());
        noAtual = noAtual->getProximo();
    }
}

//procura um elementom da lista
template <typename T>
T *ListaEncadeada<T>::buscarValor(T valor) {
    No<T> *atual = cabeca;

    while (atual != nullptr) {
        if (atual->getValor() == valor) {
            return &(atual->getValor());
        }
        atual = atual->getProximo();
    }
    return nullptr;
}

//remove o elemento de um indíce
template <typename T>
void ListaEncadeada<T>::removerFinal() {
    No<T> *atual = cabeca;
    No<T> *anterior = nullptr;

    while (atual->getProximo() != nullptr) {
        anterior = atual;
        atual = atual->getProximo();
    }

    if (anterior != nullptr) {
        anterior->setProximo(nullptr);
        cauda = anterior;
    } else {
        cabeca = nullptr;
        cauda = nullptr;
    }

    delete atual;
}

//remove o elemento especifico da lista.
template <typename T>
int ListaEncadeada<T>::removerValor(T valor) {
    No<T> *atual = cabeca;
    No<T> *anterior = nullptr;

    while (atual != nullptr) {
        if (atual->getValor() == valor) {
            if (anterior != nullptr) {
                anterior->setProximo(atual->getProximo());
                if (atual == cauda) {
                    cauda = anterior;
                }
            } else {
                cabeca = atual->getProximo();
                if (cabeca == nullptr) {
                    cauda = nullptr;
                }
            }
            delete atual;
            return 1;
        }
        anterior = atual;
        atual = atual->getProximo();
    }
    return 0;
}

//remove o elementos de uma lista da lista.
template <typename T>
void ListaEncadeada<T>::removerValor(ListaEncadeada<T> &outra) {
    No<T> *noAtual = outra.getCabeca();

    while (noAtual != nullptr) {
        removerValor(noAtual->getValor());
        noAtual = noAtual->getProximo();
    }
}

//imprime os elementos da lista utilizando recursão
template <typename T>
void ListaEncadeada<T>::imprimir() {
    imprimirAux(cabeca);
}

//auxiliar para a função imprimir
template <typename T>
void imprimirAux(No<T> *atual) {
    if (atual != nullptr) {
        std::cout << atual->getValor() << std::endl;
        imprimirAux(atual->getProximo());
    }
}

//sobrecarga de soma
template <typename T>
ListaEncadeada<T> ListaEncadeada<T>::operator+(ListaEncadeada<T> &outra) {
    ListaEncadeada<T> novaLista;
    novaLista.adicionar(*this);
    novaLista.adicionar(outra);

    return novaLista;
}

//sobrecarga de operador de extração
template <typename T>
const ListaEncadeada<T> &ListaEncadeada<T>::operator>>(No<T> &no) {
    if (cabeca != nullptr) {
        no = *cauda;
        removerFinal();
    }

    return *this;
}

//sobrecarga de operador de inserção
template <typename T>
const ListaEncadeada<T> ListaEncadeada<T>::operator<<(const No<T> &no) {
    adicionar(no.getValor());
    return *this;
}

#endif
