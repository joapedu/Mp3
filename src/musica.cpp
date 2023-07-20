#include "../include/musica.hpp"
#include <string>

// construtor padrão
Musica::Musica() {
    setTitulo("");
    setAutor("");
}

// construtor da música que recebe título e autor.
Musica::Musica(std::string titulo, std::string autor) {
    setTitulo(titulo);
    setAutor(autor);
}

// título da música.
std::string Musica::getTitulo() {
    return titulo;
}

// autor da música. 
std::string Musica::getAutor() {
    return autor;
}

// título da música.
void Musica::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

// altera o autor
void Musica::setAutor(std::string autor) {
    this->autor = autor;
}

//sobrecarga operador igual
bool Musica::operator==(Musica &outra) {
    return this->getTitulo() == outra.getTitulo();
}

// sobrecarga do operador de inserção da música.
std::ostream& operator<<(std::ostream& os, const Musica &musica) {
    os << "Título: \"" << musica.titulo << "\" - Autor: \"" << musica.autor << "\"";
    return os;
}
