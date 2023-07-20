#ifndef MUSICA_HPP
#define MUSICA_HPP

#include <string>
#include <iostream>

// classe de uma música
class Musica {

private:
    std::string titulo;
    std::string autor;

public:
    //construtor padrão.
    Musica();

    //construtor que recebe título e autor.
    Musica(std::string titulo, std::string autor = "");

    //título da música.
    std::string getTitulo();

    //autor da música.
    std::string getAutor();

    //altera o título da música.
    void setTitulo(std::string titulo);

    //altera o autor da música.
    void setAutor(std::string autor);

    //sobrecarga do operador de igualdade.
    bool operator==(Musica &outra);
    
    //sobrecarga do operador de inserção.
    friend std::ostream& operator<<(std::ostream& os, const Musica& musica);
};

#endif
