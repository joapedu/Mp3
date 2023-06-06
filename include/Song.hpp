/**
 * @file Song.hpp
 * @brief Arquivo que contém a classe Song.
 */

#ifndef SONG_HPP
#define SONG_HPP

#include <string>
#include <iostream>

/**
 * @brief Classe que representa uma música, contendo título e autor.
 */
class Song{

private:
    std::string title; //!< Título da música.
    std::string author; //!< Autor da música.

public:
    //Construtor padrão.
    Song();
    //Construtor que recebe título e autor.
    Song(std::string title, std::string author = "");
    //Retorna o título da música.
    std::string getTitle();
    //Retorna o autor da música.
    std::string getAuthor();
    //Altera o título da música.
    void setTitle(std::string title);
    //Altera o autor da música.
    void setAuthor(std::string author);
    //Sobrecarga do operador de igualdade.
    bool operator==(Song &b);
    //Sobrecarga do operador de inserção.
    friend std::ostream& operator<<(std::ostream& os, const Song& song);
};

#endif