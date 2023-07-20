#include "../include/playlist.hpp"
#include "../include/listaencadeada.hpp"
#include "../include/musica.hpp"
#include <iostream>
#include <string>

/**
 * @brief Construtor padrão da classe Playlist.
 *
 * Cria uma playlist com nome vazio.
 */
Playlist::Playlist() { this->nome = ""; }

/**
 * @brief Construtor da classe Playlist que recebe seu nome.
 *
 * @param nome O nome da playlist a ser criada.
 */
Playlist::Playlist(std::string nome) { this->nome = nome; }

/**
 * @brief Construtor de cópia da classe Playlist.
 *
 * Cria uma nova playlist a partir de outra já existente, copiando seu nome e
 * músicas.
 *
 * @param outra A playlist a ser copiada.
 */
Playlist::Playlist(const Playlist &outra) {
  this->nome = outra.nome;

  this->adicionarMusica(outra);
}

/**
 * @brief Destrutor da classe Playlist.
 *
 * Libera a memória ocupada pelas músicas da playlist.
 */
Playlist::~Playlist() { getMusicas().limpar(); }

/**
 * @brief Obtém o tamanho da playlist.
 *
 * @return O número de músicas na playlist.
 */
size_t Playlist::getTamanho() { return getMusicas().getTamanho(); }

/**
 * @brief Obtém o nome da playlist.
 *
 * @return O nome da playlist como uma referência constante para uma string.
 */
const std::string &Playlist::getNome() const { return nome; }

/**
 * @brief Obtém a referência para a lista encadeada de músicas da playlist.
 *
 * @return A referência para a lista de músicas da playlist.
 */
ListaEncadeada<Musica> &Playlist::getMusicas() { return musicas; }

/**
 * @brief Adiciona uma música à playlist.
 *
 * @param musica A música a ser adicionada à playlist.
 */
void Playlist::adicionarMusica(Musica &musica) {
  getMusicas().adicionar(musica);
}

/**
 * @brief Adiciona todas as músicas de outra playlist à playlist atual.
 *
 * @param playlist A playlist da qual as músicas serão adicionadas.
 */
void Playlist::adicionarMusica(const Playlist &playlist) {
  getMusicas().adicionar(playlist.musicas);
}

/**
 * @brief Remove a música especificada da playlist.
 *
 * @param musica A música a ser removida da playlist.
 */
void Playlist::removerMusica(const Musica &musica) {
  getMusicas().removerValor(musica);
}

/**
 * @brief Remove da playlist todas as músicas presentes na outra playlist.
 *
 * @param playlist A playlist contendo as músicas a serem removidas.
 * @return O número de músicas removidas da playlist atual.
 */
int Playlist::removerMusica(const Playlist &playlist) {
  int removidas = 0;
  for (No<Musica> *musica = playlist.musicas.getCabeca(); musica != nullptr;
       musica = musica->getProximo()) {
    if (musicas.removerValor(musica->getValor())) {
      removidas++;
    }
  }
  return removidas;
}

/**
 * @brief Procura uma música na playlist.
 *
 * @param musica A música a ser procurada na playlist.
 * @return Um ponteiro para a música na playlist, ou nullptr se a música não
 * estiver na playlist.
 */
Musica *Playlist::buscarMusica(const Musica &musica) {
  return getMusicas().buscarValor(musica);
}

/**
 * @brief Imprime as músicas da playlist.
 *
 * Imprime os títulos e autores de todas as músicas presentes na playlist.
 */
void Playlist::imprimirMusicas() { getMusicas().imprimir(); }

/**
 * @brief Sobrecarga do operador de igualdade para a classe Playlist.
 *
 * Verifica se duas playlists são iguais comparando seus nomes.
 *
 * @param outra A playlist a ser comparada.
 * @return true se as playlists têm o mesmo nome, false caso contrário.
 */
bool Playlist::operator==(Playlist &outra) {
  return this->getNome() == outra.getNome();
}

/**
 * @brief Sobrecarga do operador de união de playlists.
 *
 * Cria uma nova playlist com o nome combinado das duas playlists de origem,
 * contendo todas as músicas das playlists originais sem duplicações.
 *
 * @param outra A playlist a ser unida com a playlist atual.
 * @return Uma nova playlist resultante da união das playlists originais.
 */
Playlist Playlist::operator+(const Playlist &outra) {
  Playlist novaLista(nome + " + " + outra.nome);
  novaLista.adicionarMusica(*this);

  No<Musica> *noAtual = outra.musicas.getCabeca();

  while (noAtual != nullptr) {
    Musica musicaAtual = noAtual->getValor();
    if (novaLista.buscarMusica(musicaAtual) == nullptr) {
      novaLista.adicionarMusica(musicaAtual);
    }

    noAtual = noAtual->getProximo();
  }

  return novaLista;
}

/**
 * @brief Sobrecarga do operador de união de playlist com música.
 *
 * Cria uma nova playlist a partir da playlist atual, adicionando uma música,
 * desde que a música não esteja presente na playlist original.
 *
 * @param musica A música a ser adicionada na nova playlist.
 * @return Uma nova playlist resultante da adição da música à playlist original.
 */
Playlist Playlist::operator+(Musica &musica) {
  Playlist novaLista(*this);
  if (novaLista.buscarMusica(musica) == nullptr) {
    novaLista.adicionarMusica(musica);
  }

  return novaLista;
}

/**
 * @brief Sobrecarga do operador de diferença de playlists.
 *
 * Cria uma nova playlist com o nome combinado das duas playlists de origem,
 * contendo todas as músicas da playlist atual que não estão presentes na outra
 * playlist.
 *
 * @param outra A playlist a ser subtraída da playlist atual.
 * @return Uma nova playlist resultante da diferença entre as playlists
 * originais.
 */
Playlist Playlist::operator-(const Playlist &outra) {
  Playlist novaLista(nome + " - " + outra.nome);
  novaLista.adicionarMusica(*this);
  novaLista.removerMusica(outra);

  return novaLista;
}

/**
 * @brief Sobrecarga do operador de diferença de playlist com música.
 *
 * Cria uma nova playlist a partir da playlist atual, removendo a música
 * especificada.
 *
 * @param musica A música a ser removida da nova playlist.
 * @return Uma nova playlist resultante da remoção da música da playlist
 * original.
 */
Playlist Playlist::operator-(Musica &musica) {
  Playlist novaLista(*this);
  novaLista.removerMusica(musica);

  return novaLista;
}

/**
 * @brief Sobrecarga do operador de atribuição para a classe Playlist.
 *
 * Substitui o conteúdo da playlist atual pelo conteúdo da outra playlist
 * fornecida.
 *
 * @param outra A playlist a ser copiada.
 * @return Uma referência para a playlist atual após a atribuição.
 */
Playlist &Playlist::operator=(const Playlist &outra) {
  if (this != &outra) {
    musicas.limpar();

    adicionarMusica(outra);
    nome = outra.nome;
  }
  return *this;
}

/**
 * @brief Sobrecarga do operador de extração de música de uma playlist.
 *
 * Remove a última música da playlist atual e a armazena na variável 'musica'.
 *
 * @param musica A música a ser extraída da playlist.
 * @return Uma referência para a playlist atual após a extração.
 */
Playlist &Playlist::operator>>(Musica &musica) {
  if (musicas.getCabeca() != nullptr) {
    musica = musicas.getCauda()->getValor();
    this->musicas.removerFinal();
  }

  return *this;
}

/**
 * @brief Sobrecarga do operador de inserção de música em playlist.
 *
 * Adiciona a música especificada à playlist atual, caso ela ainda não esteja
 * presente.
 *
 * @param musica A música a ser adicionada na playlist.
 * @return Uma referência para a playlist atual após a adição da música.
 */
Playlist &Playlist::operator<<(Musica &musica) {
  if (buscarMusica(musica) == nullptr) {
    this->adicionarMusica(musica);
  }

  return *this;
}

/**
 * @brief Sobrecarga do operador de inserção para a classe Playlist.
 *
 * Imprime as informações da playlist no stream de saída no formato "Nome - N
 * músicas.".
 *
 * @param os O stream de saída.
 * @param playlist A playlist a ser exibida no stream.
 * @return O stream de saída com as informações da playlist formatadas.
 */
std::ostream &operator<<(std::ostream &os, const Playlist &playlist) {
  os << "\"" << playlist.nome << "\" - " << playlist.musicas.getTamanho()
     << " música(s).";
  return os;
}
