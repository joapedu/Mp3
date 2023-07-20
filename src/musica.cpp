#include "../include/musica.hpp"
#include <string>

/**
 * @brief Construtor padrão da classe Musica.
 *
 * Cria um objeto Musica com título e autor vazios.
 */
Musica::Musica() {
  setTitulo("");
  setAutor("");
}

/**
 * @brief Construtor da classe Musica que recebe título e autor.
 *
 * @param titulo Título da música.
 * @param autor Autor da música.
 */
Musica::Musica(std::string titulo, std::string autor) {
  setTitulo(titulo);
  setAutor(autor);
}

/**
 * @brief Obtém o título da música.
 *
 * @return O título da música como uma string.
 */
std::string Musica::getTitulo() { return titulo; }

/**
 * @brief Obtém o autor da música.
 *
 * @return O autor da música como uma string.
 */
std::string Musica::getAutor() { return autor; }

/**
 * @brief Define o título da música.
 *
 * @param titulo O título da música a ser definido.
 */
void Musica::setTitulo(std::string titulo) { this->titulo = titulo; }

/**
 * @brief Define o autor da música.
 *
 * @param autor O autor da música a ser definido.
 */
void Musica::setAutor(std::string autor) { this->autor = autor; }

/**
 * @brief Sobrecarga do operador de igualdade para a classe Musica.
 *
 * Verifica se duas músicas são iguais comparando seus títulos.
 *
 * @param outra A música a ser comparada.
 * @return true se as músicas têm o mesmo título, false caso contrário.
 */
bool Musica::operator==(Musica &outra) {
  return this->getTitulo() == outra.getTitulo();
}

/**
 * @brief Sobrecarga do operador de inserção para a classe Musica.
 *
 * @param os O stream de saída.
 * @param musica A música a ser exibida no stream.
 * @return O stream de saída com as informações da música formatadas.
 */
std::ostream &operator<<(std::ostream &os, const Musica &musica) {
  os << "Título: \"" << musica.titulo << "\" - Autor: \"" << musica.autor
     << "\"";
  return os;
}
