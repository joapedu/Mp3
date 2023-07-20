#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/no.hpp"
#include "../include/listaencadeada.hpp"
#include "../include/musica.hpp"
#include "../include/playlist.hpp"
#include "../include/menu.hpp"

//carega o arquivo e adiciona as playlists e músicas ao sistema.
void parseFile(std::ifstream& in_file, ListaEncadeada<Musica>& songs, ListaEncadeada<Playlist> &playlists){
    std::string linha;
    while(std::getline(in_file, linha)){
        std::istringstream iss{linha};
        std::string playlist_titulo;
        std::getline(iss, playlist_titulo, ';');
        
        Playlist playlist{playlist_titulo};
        playlists.adicionar(playlist);

        std::string song_string;
        while(std::getline(iss, song_string, ',')){
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

//salva playlists e músicas do sistema ao arquivo.
void writeFile(std::ofstream& out_file, ListaEncadeada<Musica>& musicas, ListaEncadeada<Playlist>& playlists){
    auto plRunner = playlists.getCabeca();

    while(plRunner != nullptr){
        auto currPl = plRunner->getValor();

        out_file << currPl.getNome() << ';';

        auto songRunner = currPl.getMusicas().getCabeca();

        while(songRunner != nullptr){
            auto currSong = songRunner->getValor();

            out_file << currSong.getTitulo() << ':';
            out_file << currSong.getAutor();

            if(songRunner->getProximo() != nullptr){
                out_file << ',';
            }

            songRunner = songRunner->getProximo();
        }

        out_file << '\n';
        plRunner = plRunner->getProximo();
    }
}

//função principal
int main(int argc, char *argv[]){
    ListaEncadeada<Playlist> playlists;
    ListaEncadeada<Musica> musicas;

    if(argc != 2){
        std::cout << "Número de argumentos inválido! "
                  << "Esperado 1 argumento (nome do arquivo).\n";
        return 1;
    }
    
    std::ifstream in_file;
    in_file.open(argv[1]);

    if(!in_file.is_open()){
        std::cout << "Não foi possível abrir o arquivo \"" 
                  << argv[1] << "\"!\n";
        return 1;
    }
    
    parseFile(in_file, musicas, playlists);

    in_file.close();

    int exit{0};

    while(exit == 0){
        exit = menuPrincipal(musicas, playlists);
    }

    std::ofstream out_file;
    out_file.open(argv[1]);

    writeFile(out_file, musicas, playlists);

    out_file.close();

    playlists.limpar();
    musicas.limpar();

    return 0;
}
