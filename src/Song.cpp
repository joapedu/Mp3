/**
 * @file Song.cpp
 * @brief Arquivo que implementa os métodos da classe Song
 */

#include "Song.hpp"
#include <string>

/**
 * @brief Construtor padrão da música.
 * 
 */
Song::Song(){
    setTitle("");
    setAuthor("");
}

/**
 * @brief Construtor da música que recebe título e autor.
 * 
 * @param title Título da música.
 * @param author (Opcional) Autor da música.
 */
Song::Song(std::string title, std::string author){
    setTitle(title);
    setAuthor(author);
}

/**
 * @brief Retorna o título da música.
 * 
 * @return Título da música.
 */
std::string Song::getTitle(){
    return title;
}

/**
 * @brief Retorna o autor da música.
 * 
 * @return Autor da música.
 */
std::string Song::getAuthor(){
    return author;
}

/**
 * @brief Altera o título da música.
 * 
 * @param title Novo título.
 */
void Song::setTitle(std::string title){
    this->title = title;
}

/**
 * @brief Altera o autor da música.
 * 
 * @param author Novo autor.
 */
void Song::setAuthor(std::string author){
    this->author = author;
}

/**
 * @brief Sobrecarga do operador de igualdade, que compara o título de duas músicas.
 * @note Duas músicas com títulos iguais e autores diferentes serão consideradas iguais.
 * 
 * @return Retorna true caso o título das músicas seja igual, e false caso contrário.
 */
bool Song::operator==(Song &b){
    return this->getTitle() == b.getTitle();
}

/**
 * @brief Sobrecarga do operador de inserção da música.
 */
std::ostream& operator<<(std::ostream& os, const Song &song){
    os << "Título: \"" << song.title << "\" - Autor: \"" << song.author << "\"";
    return os;
}