#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include "musica.hpp"
#include "no.hpp"
#include <iostream>

/**
 * Classe que implementa uma lista encadeada genérica.
 * @tparam T O tipo de dado que a lista irá conter.
 */
template <typename T> class ListaEncadeada {

private:
  No<T> *cabeca; ///< Ponteiro para o primeiro elemento da lista.
  No<T> *cauda;  ///< Ponteiro para o último elemento da lista.

public:
  /**
   * Construtor da lista encadeada.
   */
  ListaEncadeada();

  /**
   * Construtor cópia da lista encadeada.
   * @param outra A lista encadeada a ser copiada.
   */
  ListaEncadeada(const ListaEncadeada<T> &outra);

  /**
   * Destrutor da lista encadeada, que remove todos os elementos.
   */
  ~ListaEncadeada();

  /**
   * Remove todos os elementos da lista.
   */
  void limpar();

  /**
   * Retorna o tamanho da lista encadeada.
   * @return O tamanho da lista.
   */
  size_t getTamanho() const;

  /**
   * Retorna o início da lista.
   * @return O primeiro elemento da lista.
   */
  No<T> *getCabeca() const;

  /**
   * Retorna o final da lista.
   * @return O último elemento da lista.
   */
  No<T> *getCauda() const;

  /**
   * Altera o ponteiro cabeça da lista.
   * @param cabeca O novo valor para o ponteiro cabeça.
   */
  void setCabeca(No<T> *cabeca);

  /**
   * Altera o ponteiro cauda da lista.
   * @param cauda O novo valor para o ponteiro cauda.
   */
  void setCauda(No<T> *cauda);

  /**
   * Adiciona um novo elemento com valor especificado ao final da lista.
   * @param valor O valor a ser adicionado à lista.
   */
  void adicionar(T valor);

  /**
   * Adiciona todos os elementos de uma lista ao final da lista.
   * @param outra A lista contendo os elementos a serem adicionados.
   */
  void adicionar(const ListaEncadeada<T> &outra);

  /**
   * Procura um elemento específico na lista.
   * @param valor O valor do elemento a ser procurado.
   * @return Um ponteiro para o valor encontrado ou nullptr se não encontrado.
   */
  T *buscarValor(T valor);

  /**
   * Remove o elemento no final da lista.
   */
  void removerFinal();

  /**
   * Remove o elemento especificado da lista.
   * @param valor O valor do elemento a ser removido.
   * @return 1 se o elemento foi removido com sucesso, 0 se não encontrado.
   */
  int removerValor(T valor);

  /**
   * Remove todos os elementos de uma lista da lista.
   * @param outra A lista contendo os elementos a serem removidos.
   */
  void removerValor(ListaEncadeada<T> &outra);

  /**
   * Imprime todos os elementos da lista recursivamente.
   */
  void imprimir();

  /**
   * Sobrecarga do operador de soma, que concatena duas listas.
   * @param outra A lista a ser concatenada com esta.
   * @return Uma nova lista contendo os elementos das duas listas concatenados.
   */
  ListaEncadeada<T> operator+(ListaEncadeada<T> &outra);

  /**
   * Sobrecarga do operador de extração, que remove um elemento da lista.
   * @param no Referência ao nó onde o valor removido será armazenado.
   * @return A lista após a extração.
   */
  const ListaEncadeada<T> &operator>>(No<T> &no);

  /**
   * Sobrecarga do operador de inserção, que adiciona um elemento à lista.
   * @param no O nó contendo o valor a ser adicionado à lista.
   * @return A lista após a inserção.
   */
  const ListaEncadeada<T> operator<<(const No<T> &no);
};

// construtor
template <typename T> ListaEncadeada<T>::ListaEncadeada() {
  cabeca = nullptr;
  cauda = nullptr;
}

template <typename T>
ListaEncadeada<T>::ListaEncadeada(const ListaEncadeada<T> &outra) {
  cabeca = nullptr;
  cauda = nullptr;

  adicionar(outra);
}

// destrutor da lista encadeada, que remove todos os elementos.
template <typename T> ListaEncadeada<T>::~ListaEncadeada() { limpar(); }

// remove todos os elementos da lista
template <typename T> void ListaEncadeada<T>::limpar() {
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

// traz o tamanho da lista
template <typename T> size_t ListaEncadeada<T>::getTamanho() const {
  size_t tamanho = 0;
  No<T> *atual = cabeca;

  while (atual != nullptr) {
    atual = atual->getProximo();
    tamanho++;
  }
  return tamanho;
}

// retorna a cabeça da lista
template <typename T> No<T> *ListaEncadeada<T>::getCabeca() const {
  return cabeca;
}

// retorna o final da lista
template <typename T> No<T> *ListaEncadeada<T>::getCauda() const {
  return cauda;
}

// altera o ponteiro incial da lista
template <typename T> void ListaEncadeada<T>::setCabeca(No<T> *cabeca) {
  this->cabeca = cabeca;
}

// altera o ponteiro final
template <typename T> void ListaEncadeada<T>::setCauda(No<T> *cauda) {
  this->cauda = cauda;
}

// coloca um elemento especifico ao final da lista
template <typename T> void ListaEncadeada<T>::adicionar(T valor) {
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

// adiciona uma lista ao final da outra lista.
template <typename T>
void ListaEncadeada<T>::adicionar(const ListaEncadeada<T> &outra) {
  No<T> *noAtual = outra.getCabeca();

  while (noAtual != nullptr) {
    this->adicionar(noAtual->getValor());
    noAtual = noAtual->getProximo();
  }
}

// procura um elemento da lista
template <typename T> T *ListaEncadeada<T>::buscarValor(T valor) {
  No<T> *atual = cabeca;

  while (atual != nullptr) {
    if (atual->getValor() == valor) {
      return &(atual->getValor());
    }
    atual = atual->getProximo();
  }
  return nullptr;
}

// remove o elemento de um índice
template <typename T> void ListaEncadeada<T>::removerFinal() {
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

// remove o elemento especifico da lista.
template <typename T> int ListaEncadeada<T>::removerValor(T valor) {
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

// remove o elementos de uma lista da lista.
template <typename T>
void ListaEncadeada<T>::removerValor(ListaEncadeada<T> &outra) {
  No<T> *noAtual = outra.getCabeca();

  while (noAtual != nullptr) {
    removerValor(noAtual->getValor());
    noAtual = noAtual->getProximo();
  }
}

// imprime os elementos da lista utilizando recursão
template <typename T> void ListaEncadeada<T>::imprimir() {
  imprimirAux(cabeca);
}

// auxiliar para a função imprimir
template <typename T> void imprimirAux(No<T> *atual) {
  if (atual != nullptr) {
    std::cout << atual->getValor() << std::endl;
    imprimirAux(atual->getProximo());
  }
}

// sobrecarga de soma
template <typename T>
ListaEncadeada<T> ListaEncadeada<T>::operator+(ListaEncadeada<T> &outra) {
  ListaEncadeada<T> novaLista;
  novaLista.adicionar(*this);
  novaLista.adicionar(outra);

  return novaLista;
}

// sobrecarga de operador de extração
template <typename T>
const ListaEncadeada<T> &ListaEncadeada<T>::operator>>(No<T> &no) {
  if (cabeca != nullptr) {
    no = *cauda;
    removerFinal();
  }

  return *this;
}

// sobrecarga de operador de inserção
template <typename T>
const ListaEncadeada<T> ListaEncadeada<T>::operator<<(const No<T> &no) {
  adicionar(no.getValor());
  return *this;
}

#endif
