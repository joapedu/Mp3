#ifndef NO_HPP
#define NO_HPP

/**
 * Classe do nó da lista encadeada.
 * @tparam T O tipo de dado que o nó irá armazenar.
 */
template <typename T> class No {

  T valor;        ///< O valor armazenado no nó.
  No<T> *proximo; ///< Ponteiro para o próximo nó na lista.

public:
  /**
   * Construtor padrão do nó.
   */
  No() = default;

  /**
   * Construtor que recebe o valor a ser colocado no nó.
   * @param valor O valor a ser armazenado no nó.
   */
  No(const T &valor);

  /**
   * Obtém o valor do nó atual.
   * @return Uma referência ao valor armazenado no nó.
   */
  T &getValor();

  /**
   * Obtém o ponteiro para o próximo nó.
   * @return O ponteiro para o próximo nó na lista.
   */
  No *getProximo();

  /**
   * Altera o valor do nó atual.
   * @param valor O novo valor a ser armazenado no nó.
   */
  void setValor(T valor);

  /**
   * Altera o ponteiro para o próximo nó.
   * @param proximo O novo ponteiro para o próximo nó na lista.
   */
  void setProximo(No<T> *proximo);
};

/**
 * Construtor que recebe o valor a ser colocado no nó.
 * @tparam T O tipo de dado que o nó irá armazenar.
 * @param valor O valor a ser armazenado no nó.
 */
template <typename T> No<T>::No(const T &valor) {
  setValor(valor);
  setProximo(nullptr);
}

/**
 * Obtém o valor do nó atual.
 * @tparam T O tipo de dado que o nó armazena.
 * @return Uma referência ao valor armazenado no nó.
 */
template <typename T> T &No<T>::getValor() { return valor; }

/**
 * Obtém o ponteiro para o próximo nó.
 * @tparam T O tipo de dado que o nó armazena.
 * @return O ponteiro para o próximo nó na lista.
 */
template <typename T> No<T> *No<T>::getProximo() { return proximo; }

/**
 * Altera o valor do nó atual.
 * @tparam T O tipo de dado que o nó armazena.
 * @param valor O novo valor a ser armazenado no nó.
 */
template <typename T> void No<T>::setValor(T valor) { this->valor = valor; }

/**
 * Altera o ponteiro para o próximo nó.
 * @tparam T O tipo de dado que o nó armazena.
 * @param proximo O novo ponteiro para o próximo nó na lista.
 */
template <typename T> void No<T>::setProximo(No<T> *proximo) {
  this->proximo = proximo;
}

#endif
