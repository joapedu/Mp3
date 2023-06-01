/**
 * @file Node.hpp
 * @brief Arquivo que contém a classe Node.
 */

#ifndef NODE_HPP
#define NODE_HPP

/**
 * @brief Classe que implementa um nó de uma lista encadeada (LinkedList) template.
 * 
 * @tparam T Tipo do valor armazenado no nó.
 */
template <typename T>
class Node{

    T value; //!< Valor do nó atual da lista encadeada.
    Node<T> *next; //!<Ponteiro para o próximo nó da lista encadeada.

public:
    //Construtor que recebe o valor a ser colocado no nó.
    Node(T &value);
    //Retorna o valor do nó atual.
    T &getValue();
    //Retorna o ponteiro para o próximo nó.
    Node *getNext();
    //Altera o valor do nó atual.
    void setValue(T value);
    //Altera o ponteiro para o próximo nó.
    void setNext(Node<T> *next);
};

/**
 * @brief Construtor que recebe o valor a ser colocado no nó.
 * 
 * @param value Valor do nó.
 */
template <typename T>
Node<T>::Node(T &value){
    setValue(value);
    setNext(nullptr);
}

/**
 * @brief Retorna o valor do nó.
 * 
 * @return Valor do nó.
 */
template <typename T>
T &Node<T>::getValue(){
    return value;
}

/**
 * @brief Retorna o ponteiro para o próximo nó na lista.
 * 
 * @return Ponteiro para o próximo nó.
 */
template <typename T>
Node<T> *Node<T>::getNext(){
    return next;
}

/**
 * @brief Altera o valor do nó.
 * 
 * @param value Novo valor.
 */
template <typename T>
void Node<T>::setValue(T value){
    this->value = value;
}

/**
 * @brief Altera o ponteiro para o próximo elemento.
 * 
 * @param next Novo ponteiro.
 */
template <typename T>
void Node<T>::setNext(Node<T> *next){
    this->next = next;
}

#endif