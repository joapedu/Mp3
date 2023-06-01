/**
 * @file main.cpp
 * @brief Arquivo principal do programa.
 */

#include <iostream>
#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"
#include "menu.hpp"

/**
 * @brief Setup inicial do programa, que adiciona exemplos de
 * músicas e playlists para demonstrar as funcionalidades do
 * programa.
 * 
 * @param songs Lista encadeada (LinkedList) de músicas (Song) do sistema.
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 */
void setup(LinkedList<Song> &songs, LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "Deseja executar o setup inicial? Isso irá adicionar\n" <<
                 "alguns exemplos de músicas e playlists\n";
    std::cout << "1. Sim\n";
    std::cout << "0. Não\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    if(choice == 0) return;

    Song mus1("Música 1", "Autor 1");
    Song mus2("Música 2", "Autor 2");
    Song mus3("Música 3", "Autor 3");
    Song mus4("Música 4", "Autor 4");

    Playlist pl1("Playlist 1");
    Playlist pl2("Playlist 2");
    Playlist pl3("Playlist 3");

    songs.add(mus1);
    songs.add(mus2);
    songs.add(mus3);
    songs.add(mus4);

    playlists.add(pl1);
    playlists.add(pl2);
    playlists.add(pl3);

    auto pl1ptr = playlists.searchValue(pl1);
    auto pl2ptr = playlists.searchValue(pl2);
    auto pl3ptr = playlists.searchValue(pl3);

    pl1ptr->addSong(mus1);
    pl1ptr->addSong(mus2);
    pl1ptr->addSong(mus3);

    pl2ptr->addSong(mus1);
    pl2ptr->addSong(mus4);

    std::cout << "Setup completo\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
}

int main(){
    LinkedList<Playlist> playlists;
    LinkedList<Song> songs;

    setup(songs, playlists);

    int exit{0};

    while(exit == 0){
        exit = mainMenu(songs, playlists);
    }

    playlists.clear();
    songs.clear();

    return 0;
}