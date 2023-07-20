#ifndef MUSICA_HPP
#define MUSICA_HPP

#include <iostream>
#include <string>

/**
 * @brief Classe que representa uma música.
 */
class Musica {

private:
  std::string titulo; ///< Título da música.
  std::string autor;  ///< Autor da música.

public:
  /**
   * @brief Construtor padrão da classe Musica.
   */
  Musica();

  /**
   * @brief Construtor da classe Musica que recebe título e autor.
   *
   * @param titulo O título da música.
   * @param autor O autor da música. (opcional, padrão = "")
   */
  Musica(std::string titulo, std::string autor = "");

  /**
   * @brief Obtém o título da música.
   *
   * @return O título da música como uma string.
   */
  std::string getTitulo();

  /**
   * @brief Obtém o autor da música.
   *
   * @return O autor da música como uma string.
   */
  std::string getAutor();

  /**
   * @brief Altera o título da música.
   *
   * @param titulo O novo título da música.
   */
  void setTitulo(std::string titulo);

  /**
   * @brief Altera o autor da música.
   *
   * @param autor O novo autor da música.
   */
  void setAutor(std::string autor);

  /**
   * @brief Sobrecarga do operador de igualdade.
   *
   * @param outra A outra música para comparar.
   * @return True se as músicas forem iguais, False caso contrário.
   */
  bool operator==(Musica &outra);

  /**
   * @brief Sobrecarga do operador de inserção para imprimir informações da
   * música.
   *
   * @param os O stream de saída onde a música será impressa.
   * @param musica A música a ser impressa.
   * @return O stream de saída após a impressão.
   */
  friend std::ostream &operator<<(std::ostream &os, const Musica &musica);
};

#endif
