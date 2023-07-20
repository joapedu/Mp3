#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include "no.hpp"
#include "listaencadeada.hpp"
#include "musica.hpp"

//classe que implementa uma playlist
class Playlist {

private:
    std::string nome; //!< Nome da playlist.
    ListaEncadeada<Musica> musicas; //!< Lista de músicas da playlist.

public:
    //construtor padrão 
    Playlist();
    
    //construtor da playlist que recebe seu nome 
    Playlist(std::string nome);

    //construtor cópia da playlist
    Playlist(const Playlist &outra);

    //destrutor da playlist, que remove todas as músicas 
    ~Playlist();

    //tamanho da playlist
    size_t getTamanho();

    //nome da playlist 
    const std::string &getNome() const;

    //referência para a lista encadeada de músicas 
    ListaEncadeada<Musica> &getMusicas();

    //adiciona uma música à playlist 
    void adicionarMusica(Musica &musica);

    //adiciona todas as músicas de uma outra playlist à playlist
    void adicionarMusica(const Playlist &playlist);

    //remove a música especificada da playlist 
    void removerMusica(const Musica &musica);

    //remove todas as músicas de uma outra playlist da playlist
    int removerMusica(const Playlist &playlist);

    //procura uma música na playlist 
    Musica *buscarMusica(const Musica &musica);

    //imprime as músicas da playlist 
    void imprimirMusicas();

    //sobrecarga de operador de igualdade 
    bool operator==(Playlist &outra);

    //sobrecarga de operador de união de playlists
    Playlist operator+(const Playlist &outra);

    //sobrecarga de operador de união de playlist com música
    Playlist operator+(Musica &musica);

    //sobrecarga de operador de diferença de playlists
    Playlist operator-(const Playlist &outra);

    //sobrecarga de operador de diferença de playlist com música
    Playlist operator-(Musica &musica);

    //sobrecarga de operador de atribuição de playlist
    Playlist& operator=(const Playlist &outra);

    //sobrecarga de operador de extração de música de uma playlist
    Playlist& operator>>(Musica &musica);

    //sobrecarga de operador de inserção de música em playlist
    Playlist& operator<<(Musica &musica);

    //sobrecarga de operador de inserção de playlist 
    friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);
};

#endif
