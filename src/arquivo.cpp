#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/listaencadeada.hpp"
#include "../include/menu.hpp"
#include "../include/musica.hpp"
#include "../include/no.hpp"
#include "../include/playlist.hpp"

/**
 * @brief Carrega o arquivo e adiciona as playlists e músicas ao sistema.
 *
 * @param in_file O arquivo de entrada contendo informações sobre as playlists e
 * músicas.
 * @param musicas A lista encadeada onde as músicas serão armazenadas.
 * @param playlists A lista encadeada onde as playlists serão armazenadas.
 */
void parseFile(std::ifstream &in_file, ListaEncadeada<Musica> &songs,
               ListaEncadeada<Playlist> &playlists) {
  std::string linha;
  while (std::getline(in_file, linha)) {
    std::istringstream iss{linha};
    std::string playlist_titulo;
    std::getline(iss, playlist_titulo, ';');

    Playlist playlist{playlist_titulo};
    playlists.adicionar(playlist);

    std::string song_string;
    while (std::getline(iss, song_string, ',')) {
      std::istringstream iss_song{song_string};
      std::string musica_titulo;
      std::string musica_autor;

      std::getline(iss_song, musica_titulo, ':');
      std::getline(iss_song, musica_autor);

      Musica Musica{musica_titulo, musica_autor};
      songs.adicionar(Musica);

      playlists.buscarValor(playlist)->adicionarMusica(Musica);
    }
  }
}

/**
 * @brief Salva playlists e músicas do sistema ao arquivo.
 *
 * @param out_file O arquivo de saída onde as informações serão salvas.
 * @param musicas A lista encadeada contendo as músicas a serem salvas.
 * @param playlists A lista encadeada contendo as playlists a serem salvas.
 */
void writeFile(std::ofstream &out_file, ListaEncadeada<Musica> &musicas,
               ListaEncadeada<Playlist> &playlists) {
  auto plRunner = playlists.getCabeca();

  while (plRunner != nullptr) {
    auto currPl = plRunner->getValor();

    out_file << currPl.getNome() << ';';

    auto songRunner = currPl.getMusicas().getCabeca();

    while (songRunner != nullptr) {
      auto currSong = songRunner->getValor();

      out_file << currSong.getTitulo() << ':';
      out_file << currSong.getAutor();

      if (songRunner->getProximo() != nullptr) {
        out_file << ',';
      }

      songRunner = songRunner->getProximo();
    }

    out_file << '\n';
    plRunner = plRunner->getProximo();
  }
}