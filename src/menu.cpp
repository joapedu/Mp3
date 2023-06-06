/**
 * @file menu.cpp
 * @brief Arquivo que implementa as funções relacionadas ao menu.
 */

#include <iostream>
#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"
#include "menu.hpp"

/**
 * @brief Menu de playlists, que permite adicionar, remover ou listar músicas no sistema.
 * 
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 */
void playlistMenu(LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "======================\n";
    std::cout << "Menu de playlists\n";
    std::cout << "1. Adicionar playlist\n";
    std::cout << "2. Remover playlist\n";
    std::cout << "3. Listar playlists\n";
    std::cout << "0. Voltar\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    std::string line;

    switch(choice){
        case 1: // Adicionar playlist
            std::cout << "Digite o nome da playlist para adicionar, ou deixe em branco para cancelar:\n";
            std::getline(std::cin, line);
            if(line != "") {
                if(playlists.searchValue(Playlist(line)) != nullptr){
                    std::cout << "Erro: A playlist \"" << line << "\" já existe.\n";
                }
                else{
                    playlists.add(Playlist(line));
                    std::cout << "Playlist \"" << line << "\" adicionada com sucesso.\n";
                }
            }
            else{
                std::cout << "Ação cancelada.\n";
            }
            break;
                
        case 2: // Remover playlist
            std::cout << "Digite o nome da playlist para remover, ou deixe em branco para cancelar:\n";
            std::getline(std::cin, line);
            if(line != ""){
                if(playlists.searchValue(Playlist(line)) == nullptr){
                    std::cout << "Erro: Playlist inválida.\n";
                }
                else{
                    playlists.removeValue(Playlist(line));
                    std::cout << "Playlist \"" << line << "\" removida com sucesso.\n";
                }
            }
            else{
                std::cout << "Ação cancelada.\n";
            }
            break;

        case 3: // Listar playlists
            if(playlists.getSize() == 0){
                std::cout << "Nenhuma playlist cadastrada.\n";
            }
            else{
                std::cout << "Playlists:\n";
                playlists.print();
            }
            break;

        case 0:
            return;

        default: // Escolha inválida
            std::cout << "Erro: Escolha inválida!\n";
            break;
    }
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
}

/**
 * @brief Menu de músicas, que permite adicionar, remover ou listar músicas no sistema.
 * 
 * @param songs Lista encadeada (LinkedList) de músicas (Song) do sistema.
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 */
void songMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "======================\n";
    std::cout << "Menu de músicas\n";
    std::cout << "1. Adicionar música\n";
    std::cout << "2. Remover música\n";
    std::cout << "3. Listar músicas\n";
    std::cout << "0. Voltar\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    std::string line;

    switch(choice){
        case 1: {// Adicionar música
            std::cout << "Digite o nome da música para adicionar, ou deixe em branco para cancelar:\n";
            std::getline(std::cin, line);
            if(line != "") {
                if(songs.searchValue(Song(line)) != nullptr){
                    std::cout << "Erro: A música \"" << line << "\" já existe.\n";
                }
                else{
                    std::string author;
                    std::cout << "Digite o nome do autor:\n";
                    std::getline(std::cin, author);

                    songs.add(Song(line, author));
                    std::cout << "Música \"" << line << "\" adicionada com sucesso.\n";
                }
            }
            else{
                std::cout << "Ação cancelada.\n";
            }
            break;
        }
                
        case 2: // Remover música
            std::cout << "Digite o nome da música para remover, ou deixe em branco para cancelar:\n";
            std::getline(std::cin, line);
            if(line != ""){
                if(songs.searchValue(Song(line)) == nullptr){
                    std::cout << "Erro: Música inválida.\n";
                }
                else{
                    songs.removeValue(Song(line));

                    Node<Playlist> *curr = playlists.getHead();

                    while(curr != nullptr){
                        curr->getValue().removeSong(Song(line));
                        curr = curr->getNext();
                    }

                    std::cout << "Música \"" << line << "\" removida com sucesso.\n";
                }
            }
            else{
                std::cout << "Ação cancelada.\n";
            }
            break;

        case 3: // Listar músicas
            if(songs.getSize() == 0){
                std::cout << "Nenhuma música cadastrada.\n";
            }
            else{
                std::cout << "Músicas:\n";
                songs.print();
            }
            break;

        case 0:
            return;

        default: // Escolha inválida
            std::cout << "Erro: Escolha inválida!\n";
            break;
    }
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
}

/**
 * @brief Menu de gerenciamento de músicas em playlists, que permite adicionar, remover ou listar
 * músicas nas playlists.
 * 
 * @param songs Lista encadeada (LinkedList) de músicas (Song) do sistema.
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 */
void songPlaylistMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "======================\n";
    std::cout << "Gerenciar músicas em playlists\n";
    std::cout << "1. Adicionar música em playlist\n";
    std::cout << "2. Remover música de playlist\n";
    std::cout << "3. Listar músicas de playlist\n";
    std::cout << "0. Voltar\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    if(choice == 0) return;

    std::string line;

    std::cout << "Digite o nome da playlist, ou deixe em branco para cancelar:\n";
    std::getline(std::cin, line);

    if(line == ""){
        std::cout << "Ação cancelada.\n";
        std::cout << "Pressione ENTER para continuar.";
        std::cin.get();
        return;
    }

    Playlist *pl = playlists.searchValue(Playlist(line));

    if(pl == nullptr){
        std::cout << "Erro: Playlist inválida.\n";
        std::cout << "Pressione ENTER para continuar.";
        std::cin.get();
        return;
    }

    switch(choice){
        case 1: { // Adicionar música em playlist
            std::cout << "Digite o nome da música para adicionar:\n";
            std::getline(std::cin, line);
            Song* musica = songs.searchValue(Song(line));

            //Caso música não exista no sistema
            if(musica == nullptr){ 
                std::cout << "Erro: Música inválida. Adicione a música ao sistema primeiro.\n";
            }
            //Caso música já esteja na playlist
            else if(pl->searchSong(*musica) != nullptr){
                std::cout << "Erro: Música já está na playlist.\n";
            }
            else{
                pl->addSong(*musica);
                std::cout << "Música adicionada com sucesso.\n";
            }
            break;
        }
        case 2: //Remover música de playlist
            std::cout << "Digite o nome da música para remover:\n";
            std::getline(std::cin, line);

            if(pl->searchSong(Song(line)) != nullptr){
                pl->removeSong(Song(line));
                std::cout << "Música removida com sucesso.\n";
            }
            else{
                std::cout << "Erro: Música não está na playlist.\n";
            }
            break;
        case 3: // Listar músicas de playlist
            if(pl->getSize() > 0){
                std::cout << "Músicas da playlist \"" << pl->getName() << "\":\n";
                pl->printSongs();
            }
            else{
                std::cout << "A playlist \"" << pl->getName() << "\" não possui músicas.\n";
            }
            break;
    }
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
}

/**
 * @brief Toca as músicas, em sequência, da playlist selecionada.
 * 
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 */
void playSongs(LinkedList<Playlist> &playlists){
    std::string line;
    std::cout << "Selecione a playlist para tocar, ou deixe em branco para cancelar:\n";
    std::getline(std::cin, line);

    if(line == ""){
        std::cout << "Ação cancelada.\n";
        std::cout << "Pressione ENTER para continuar.";
        std::cin.get();
        return;
    }

    Playlist *pl = playlists.searchValue(Playlist(line));

    if(pl == nullptr) {
        std::cout << "Erro: Playlist inválida.\n";
        std::cout << "Pressione ENTER para continuar.";
        std::cin.get();
        return;
    }

    if(pl->getSize() == 0){
        std::cout << "A playlist \"" << pl->getName() << "\" não tem nenhuma música.\n";
        std::cout << "Pressione ENTER para continuar.";
        std::cin.get();
        return;
    }

    int end = 0;
    int count = 1;
    Node<Song> *curr = pl->getSongs().getHead();

    while(end == 0){
        int choice;

        std::cout << "======================\n";
        std::cout << "Tocando playlist \"" << pl->getName() <<"\".\n";
        std::cout << "Música " << count << " de " << pl->getSize() << ":\n";
        std::cout << curr->getValue() << "\n";
        if(curr->getNext() == nullptr){
            std::cout << "Última música da playlist.\n";
        }
        else{
            std::cout << "Próxima música: " << curr->getNext()->getValue() << "\n";
        }
        std::cout << "1. Tocar próxima música\n";
        std::cout << "0. Parar de tocar\n";
        std::cout << "Digite sua escolha: ";

        std::cin >> choice;
        std::cin.ignore();

        if(choice == 1){
            curr = curr->getNext();
            count++;
        }
        else{
            end = 1;
        }

        if(curr == nullptr){
            std::cout << "A playlist acabou.\n";
            std::cout << "Pressione ENTER para continuar.";
            std::cin.get();
            end = 1;
        }
        
    }
    
}

/**
 * @brief Menu principal, que permite chamar os submenus relacionados a músicas e playlists.
 * 
 * @param songs Lista encadeada (LinkedList) de músicas (Song) do sistema.
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 * @return Retorna 1 caso o programa seja encerrado, ou 0 caso contrário.
 */
int mainMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "======================\n";
    std::cout << "Menu inicial\n";
    std::cout << "1. Gerenciar playlists\n";
    std::cout << "2. Gerenciar músicas\n";
    std::cout << "3. Gerenciar músicas em playlists\n";
    std::cout << "4. Tocar playlist\n";
    std::cout << "0. Sair\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    switch(choice){
        case 1: 
            playlistMenu(playlists); 
            break;

        case 2: 
            songMenu(songs, playlists); 
            break;

        case 3:
            songPlaylistMenu(songs, playlists);
            break;
        
        case 4:
            playSongs(playlists);
            break;

        case 0: 
            std::cout << "Programa encerrado.\n";
            return 1;

        default: 
            std::cout << "Erro: Escolha inválida!\n"; 
            std::cout << "Pressione ENTER para continuar.";
            std::cin.get();
            break;
    } 

    return 0;
}