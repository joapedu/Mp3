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
const std::string& Playlist::getName() const{
    return name;
}

/**
 * @brief Retorna uma referência para a lista encadeada de músicas.
 * 
 * @return Referência para a lista de músicas.
 */
LinkedList<Song> &Playlist::getSongs() {
    return songs;
}

/**
 * @brief Adiciona uma música à playlist.
 * 
 * @param song Música a ser adicionada.
 */
void Playlist::addSong(Song &song){
    getSongs().add(song);
}

Playlist::Playlist(const Playlist &other){
    this->name = other.name;

    this->addSong(other);
}


//leva musicas de uma playlist à outra
void Playlist::addSong(const Playlist &playlist){
    getSongs().add(playlist.songs);
}
Playlist::Playlist(const Playlist &other){
    this->name = other.name;

    this->addSong(other);
}

// remove todas musicas da playlis
int Playlist::removeSong(const Playlist &playlist){
    int removed = 0;
    for (Node<Song> *song = playlist.songs.getHead(); song != nullptr; song = song->getNext()){
        if (songs.removeValue(song->getValue())){
            removed++;
        }
    }
    return removed;
}

// sobrecarga união de playlist.
Playlist Playlist::operator+(const Playlist &other){
    Playlist newPl(name + " + " + other.name);
    newPl.addSong(*this);

    Node<Song> *currNode = other.songs.getHead();

    while(currNode != nullptr){
        Song currSong = currNode->getValue();
        if(newPl.searchSong(currSong) == nullptr){
            newPl.addSong(currSong);
        }

        currNode = currNode->getNext();
    }

    return newPl;
}

// sobrecarga união de playlist 
Playlist Playlist::operator+(Song &song){
    Playlist newPl(*this);
    if(newPl.searchSong(song) == nullptr){
        newPl.addSong(song);
    }

    return newPl;
}

// sobrecarga diferença de playlist
Playlist Playlist::operator-(const Playlist &other){
    Playlist newPl(name + " - " + other.name);
    newPl.addSong(*this);
    newPl.removeSong(other);

    return newPl;
}

// sobrecarga diferença de playlist com música
Playlist Playlist::operator-(Song &song){
    Playlist newPl(*this);
    newPl.removeSong(song);

    return newPl;
}

// sobrecarga atribuição de playlist.
Playlist& Playlist::operator=(const Playlist &other){
    if(this != &other){
        songs.clear();

        addSong(other);
        name = other.name;
    }
    return *this;
}

// sobrecarga extração música de uma playlist.
Playlist& Playlist::operator>>(Song &song){
    if(songs.getHead() != nullptr){
        song = songs.getTail()->getValue();
        this->songs.popBack();
    }

    return *this;
}

// sobrecarga de operador de inserção de música em playlist, 
Playlist& Playlist::operator<<(Song &song){
    if(searchSong(song)==nullptr){
        this->addSong(song);
    }

    return *this;
}

// sobrecarga inserção da playlist.
std::ostream& operator<<(std::ostream& os, const Playlist& playlist){
    os << "\"" << playlist.name << "\" - " << playlist.songs.getSize() << " música(s).";
    return os;
}

/**
 * @brief Remove a música especificada da playlist.
 * 
 * @param title Título da música.
 */
void Playlist::removeSong(const Song &song){
    getSongs().removeValue(song);
}

/**
 * @brief Procura uma música na playlist.
 * 
 * @param song Música a ser buscada.
 * @return Retorna o ponteiro para a música, caso ela esteja na lista, ou nullptr
 * caso contrário.
 */
Song *Playlist::searchSong(const Song &song){
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

