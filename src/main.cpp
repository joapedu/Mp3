/**
 * @file main.cpp
 * @brief Arquivo principal do programa.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"
#include "menu.hpp"

// processo de ler o arquivo e adicionar ao programa
void vistaFile(std::ifstream& in_file, LinkedList<Song>& songs, LinkedList<Playlist> &playlists){
    std::string line;
    while(std::getline(in_file, line)){
        std::istringstream iss{line};
        std::string pl_title;
        std::getline(iss, pl_title, ';');
        
        Playlist playlist{pl_title};
        playlists.add(playlist);

        std::string song_string;
        while(std::getline(iss, song_string, ',')){
            std::istringstream iss_song{song_string};
            std::string song_title;
            std::string song_author;

            std::getline(iss_song, song_title, ':');
            std::getline(iss_song, song_author);

            Song song{song_title, song_author};
            songs.add(song);

            playlists.searchValue(playlist)->addSong(song);
        }
    }
}

/**
 * @brief escrita do documento ao projeto
 * 
 * @param songs Lista encadeada de músicas.
 * @param playlists Lista encadeada de playlists.
 */
void anotFile(std::ofstream& out_file, LinkedList<Song>& songs, LinkedList<Playlist> &playlists){
    auto plRunner = playlists.getHead();

    while(plRunner != nullptr){
        auto currPl = plRunner->getValue();

        out_file << currPl.getName() << ';';

        auto songRunner = currPl.getSongs().getHead();

        while(songRunner != nullptr){
            auto currSong = songRunner->getValue();

            out_file << currSong.getTitle() << ':';
            out_file << currSong.getAuthor();

            if(songRunner->getNext() != nullptr){
                out_file << ',';
            }

            songRunner = songRunner->getNext();
        }

        out_file << '\n';
        plRunner = plRunner->getNext();
    }
}

int main(int argc, char *argv[]){
    LinkedList<Playlist> playlists;
    LinkedList<Song> songs;

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
    
    vistaFile(in_file, songs, playlists);

    in_file.close();

    int exit{0};

    while(exit == 0){
        exit = mainMenu(songs, playlists);
    }

    std::ofstream out_file;
    out_file.open(argv[1]);

    anotFile(out_file, songs, playlists);

    out_file.close();

    playlists.clear();
    songs.clear();

    return 0;
}
