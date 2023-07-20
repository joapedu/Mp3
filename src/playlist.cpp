#include <string>
#include <iostream>
#include "../include/listaencadeada.hpp"
#include "../include/musica.hpp"
#include "../include/playlist.hpp"

//construtor padrão
Playlist::Playlist(){
    this->nome = "";
}

//construtor da playlist que recebe seu nome.
Playlist::Playlist(std::string nome){
    this->nome = nome;
}

Playlist::Playlist(const Playlist &outra){
    this->nome = outra.nome;

    this->adicionarMusica(outra);
}

//destrutor da playlist
Playlist::~Playlist(){
    getMusicas().limpar();
}

//tamanho da playlist
size_t Playlist::getTamanho(){
    return getMusicas().getTamanho();
}

//retorna o nome da playlist
const std::string& Playlist::getNome() const{
    return nome;
}

//referência para a lista encadeada de músicas
ListaEncadeada<Musica> &Playlist::getMusicas() {
    return musicas;
}

//adiciona uma música à playlist
void Playlist::adicionarMusica(Musica &musica){
    getMusicas().adicionar(musica);
}

//adiciona todas as músicas de uma outra playlist à playlist.
void Playlist::adicionarMusica(const Playlist &playlist){
    getMusicas().adicionar(playlist.musicas);
}

//remove a música especificada da playlist
void Playlist::removerMusica(const Musica &musica){
    getMusicas().removerValor(musica);
}

//remove da playlist todas as músicas na playlist recebida
int Playlist::removerMusica(const Playlist &playlist){
    int removidas = 0;
    for (No<Musica> *musica = playlist.musicas.getCabeca(); musica != nullptr; musica = musica->getProximo()){
        if (musicas.removerValor(musica->getValor())){
            removidas++;
        }
    }
    return removidas;
}

//procura uma música na playlist
Musica *Playlist::buscarMusica(const Musica &musica){
    return getMusicas().buscarValor(musica);
}

//imprime as músicas da playlist
void Playlist::imprimirMusicas(){
    getMusicas().imprimir();
}

//sobrecarga de operador de igualdade
bool Playlist::operator==(Playlist &outra){
    return this->getNome() == outra.getNome();
}

//sobrecarga de operador de união de playlists
Playlist Playlist::operator+(const Playlist &outra){
    Playlist novaLista(nome + " + " + outra.nome);
    novaLista.adicionarMusica(*this);

    No<Musica> *noAtual = outra.musicas.getCabeca();

    while(noAtual != nullptr){
        Musica musicaAtual = noAtual->getValor();
        if(novaLista.buscarMusica(musicaAtual) == nullptr){
            novaLista.adicionarMusica(musicaAtual);
        }

        noAtual = noAtual->getProximo();
    }

    return novaLista;
}

//sobrecarga de operador de união de playlist com música
Playlist Playlist::operator+(Musica &musica){
    Playlist novaLista(*this);
    if(novaLista.buscarMusica(musica) == nullptr){
        novaLista.adicionarMusica(musica);
    }

    return novaLista;
}

//sobrecarga de operador de diferença de playlists
Playlist Playlist::operator-(const Playlist &outra){
    Playlist novaLista(nome + " - " + outra.nome);
    novaLista.adicionarMusica(*this);
    novaLista.removerMusica(outra);

    return novaLista;
}

//sobrecarga de operador de diferença de playlist com música
Playlist Playlist::operator-(Musica &musica){
    Playlist novaLista(*this);
    novaLista.removerMusica(musica);

    return novaLista;
}

//sobrecarga de operador de atribuição de playlist
Playlist& Playlist::operator=(const Playlist &outra){
    if(this != &outra){
        musicas.limpar();

        adicionarMusica(outra);
        nome = outra.nome;
    }
    return *this;
}

//sobrecarga de operador de extração de música de uma playlist
Playlist& Playlist::operator>>(Musica &musica){
    if(musicas.getCabeca() != nullptr){
        musica = musicas.getCauda()->getValor();
        this->musicas.removerFinal();
    }

    return *this;
}

//sobrecarga de operador de inserção de música em playlist
Playlist& Playlist::operator<<(Musica &musica){
    if(buscarMusica(musica)==nullptr){
        this->adicionarMusica(musica);
    }

    return *this;
}

//sobrecarga de operador de inserção da playlist
std::ostream& operator<<(std::ostream& os, const Playlist& playlist){
    os << "\"" << playlist.nome << "\" - " << playlist.musicas.getTamanho() << " música(s).";
    return os;
}
