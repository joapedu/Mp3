#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "listaencadeada.hpp"
#include "musica.hpp"
#include "no.hpp"
#include <string>

/**
 * @brief Classe que implementa uma playlist.
 */
class Playlist {

private:
  std::string nome;               //!< Nome da playlist.
  ListaEncadeada<Musica> musicas; //!< Lista de músicas da playlist.

public:
  /**
   * @brief Construtor padrão da classe Playlist.
   */
  Playlist();

  /**
   * @brief Construtor da playlist que recebe seu nome.
   *
   * @param nome O nome da playlist.
   */
  Playlist(std::string nome);

  /**
   * @brief Construtor cópia da playlist.
   *
   * @param outra A outra playlist a ser copiada.
   */
  Playlist(const Playlist &outra);

  /**
   * @brief Destrutor da playlist, que remove todas as músicas.
   */
  ~Playlist();

  /**
   * @brief Obtém o tamanho da playlist (quantidade de músicas).
   *
   * @return O tamanho da playlist.
   */
  size_t getTamanho();

  /**
   * @brief Obtém o nome da playlist.
   *
   * @return O nome da playlist.
   */
  const std::string &getNome() const;

  /**
   * @brief Obtém a referência para a lista encadeada de músicas da playlist.
   *
   * @return A lista encadeada de músicas.
   */
  ListaEncadeada<Musica> &getMusicas();

  /**
   * @brief Adiciona uma música à playlist.
   *
   * @param musica A música a ser adicionada.
   */
  void adicionarMusica(Musica &musica);

  /**
   * @brief Adiciona todas as músicas de outra playlist à playlist atual.
   *
   * @param playlist A playlist de onde as músicas serão adicionadas.
   */
  void adicionarMusica(const Playlist &playlist);

  /**
   * @brief Remove a música especificada da playlist.
   *
   * @param musica A música a ser removida.
   */
  void removerMusica(const Musica &musica);

  /**
   * @brief Remove todas as músicas de outra playlist da playlist atual.
   *
   * @param playlist A playlist de onde as músicas serão removidas.
   * @return O número de músicas removidas.
   */
  int removerMusica(const Playlist &playlist);

  /**
   * @brief Procura uma música na playlist.
   *
   * @param musica A música a ser procurada.
   * @return Um ponteiro para a música encontrada, ou nullptr se não encontrada.
   */
  Musica *buscarMusica(const Musica &musica);

  /**
   * @brief Imprime as músicas da playlist.
   */
  void imprimirMusicas();

  /**
   * @brief Sobrecarga do operador de igualdade.
   *
   * @param outra A outra playlist a ser comparada.
   * @return true se as playlists forem iguais, false caso contrário.
   */
  bool operator==(Playlist &outra);

  /**
   * @brief Sobrecarga do operador de união de playlists.
   *
   * @param outra A outra playlist a ser unida à playlist atual.
   * @return Uma nova playlist contendo as músicas de ambas as playlists.
   */
  Playlist operator+(const Playlist &outra);

  /**
   * @brief Sobrecarga do operador de união de playlist com música.
   *
   * @param musica A música a ser adicionada à playlist atual.
   * @return Uma nova playlist contendo as músicas da playlist atual mais a
   * música adicionada.
   */
  Playlist operator+(Musica &musica);

  /**
   * @brief Sobrecarga do operador de diferença de playlists.
   *
   * @param outra A outra playlist a ser subtraída da playlist atual.
   * @return Uma nova playlist contendo as músicas que estão na playlist atual e
   * não na outra.
   */
  Playlist operator-(const Playlist &outra);

  /**
   * @brief Sobrecarga do operador de diferença de playlist com música.
   *
   * @param musica A música a ser removida da playlist atual.
   * @return Uma nova playlist contendo as músicas da playlist atual sem a
   * música removida.
   */
  Playlist operator-(Musica &musica);

  /**
   * @brief Sobrecarga do operador de atribuição de playlist.
   *
   * @param outra A outra playlist a ser copiada para a playlist atual.
   * @return A playlist atual após a cópia.
   */
  Playlist &operator=(const Playlist &outra);

  /**
   * @brief Sobrecarga do operador de extração de música de uma playlist.
   *
   * @param musica O objeto que receberá a música extraída da playlist atual.
   * @return A playlist atual após a extração da música.
   */
  Playlist &operator>>(Musica &musica);

  /**
   * @brief Sobrecarga do operador de inserção de música em playlist.
   *
   * @param musica A música a ser adicionada à playlist atual.
   * @return A playlist atual após a adição da música.
   */
  Playlist &operator<<(Musica &musica);

  /**
   * @brief Sobrecarga do operador de inserção de playlist.
   *
   * @param os O stream de saída.
   * @param playlist A playlist a ser impressa no stream de saída.
   * @return O stream de saída após a impressão da playlist.
   */
  friend std::ostream &operator<<(std::ostream &os, const Playlist &playlist);
};

#endif
