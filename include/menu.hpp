/**
 * @file menu.hpp
 * @brief Arquivo cabeçalho das funções relacionadas ao menu
 * de gerenciamento de playlists.
 */

#include <iostream>
#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

// Menu de gerenciar playlists.
void playlistMenu(LinkedList<Playlist> &playlists);
// Menu de gerenciar músicas.
void songMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists);
// Menu de gerenciar músicas em playlists.
void songPlaylistMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists);
// Menu de tocar músicas.
void playSongs(LinkedList<Playlist> &playlists);
// Menu principal.
int mainMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists);