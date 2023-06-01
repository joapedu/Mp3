/**
 * @file Playlist.cpp
 * @brief Arquivo que implementa os métodos da classe Playlist.
 */

#include <string>
#include <iostream>
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

/**
 * @brief Construtor padrão da playlist.
 */
Playlist::Playlist(){
    this->name = "";
}

/**
 * @brief Construtor da playlist que recebe seu nome.
 * 
 * @param name Nome da playlist.
 */
Playlist::Playlist(std::string name){
    this->name = name;
}

/**
 * @brief Destrutor da playlist, que remove todas as músicas.
 */
Playlist::~Playlist(){
    getSongs().clear();
}

/**
 * @brief Retorna o tamanho da playlist.
 * 
 * @return Número de músicas.
 */
size_t Playlist::getSize(){
    return getSongs().getSize();
}

/**
 * @brief Retorna o nome da playlist.
 * 
 * @return Nome da playlist.
 */
std::string Playlist::getName(){
    return name;
}

/**
 * @brief Retorna uma referência para a lista encadeada de músicas.
 * 
 * @return Referência para a lista de músicas.
 */
LinkedList<Song> &Playlist::getSongs(){
    return songs;
}

/**
 * @brief Adiciona uma música à playlist.
 * 
 * @param song Música a ser adicionada.
 */
void Playlist::addSong(Song song){
    getSongs().add(song);
}

/**
 * @brief Remove a música especificada da playlist.
 * 
 * @param title Título da música.
 */
void Playlist::removeSong(Song song){
    getSongs().removeValue(song);
}

/**
 * @brief Procura uma música na playlist.
 * 
 * @param song Música a ser buscada.
 * @return Retorna o ponteiro para a música, caso ela esteja na lista, ou nullptr
 * caso contrário.
 */
Song *Playlist::searchSong(Song song){
    return getSongs().searchValue(song);
}

/**
 * @brief Imprime as músicas da playlist.
 */
void Playlist::printSongs(){
    getSongs().print();
}

/**
 * @brief Sobrecarga de operador de igualdade.
 * 
 * @return Retorna true se o nome das playlists for igual.
 * @return Retorna false caso contrário.
 */
bool Playlist::operator==(Playlist &b){
    return this->getName() == b.getName();
}

/**
 * @brief Sobrecarga de operador de inserção da playlist.
 */
std::ostream& operator<<(std::ostream& os, const Playlist& playlist){
    os << "\"" << playlist.name << "\" - " << playlist.songs.getSize() << " música(s).";
    return os;
}