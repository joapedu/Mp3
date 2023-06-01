/**
 * @file Playlist.hpp
 * @brief Arquivo que contém a classe Playlist.
 */

#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"

/**
 * @brief Classe que implementa uma playlist, contendo uma lista encadeada 
 * (LinkedList) de músicas (Song).
 */
class Playlist{

private:
    std::string name; //!< Nome da playlist.
    LinkedList<Song> songs; //!< Lista de músicas da playlist.

public:
    // Construtor padrão da playlist. 
    Playlist();
    // Construtor da playlist que recebe seu nome. 
    Playlist(std::string name);
    // Destrutor da playlist, que remove todas as músicas. 
    ~Playlist();
    // Retorna o tamanho da playlist.
    size_t getSize();
    // Retorna o nome da playlist. 
    std::string getName();
    // Retorna uma referência para a lista encadeada de músicas. 
    LinkedList<Song> &getSongs();
    // Adiciona uma música à playlist. 
    void addSong(Song song);
    // Remove a música especificada da playlist. 
    void removeSong(Song song);
    // Procura uma música na playlist. 
    Song *searchSong(Song song);
    // Imprime as músicas da playlist. 
    void printSongs();
    // Sobrecarga de operador de igualdade. 
    bool operator==(Playlist &b);
    // Sobrecarga de operador de inserção da playlist. 
    friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);
};

#endif