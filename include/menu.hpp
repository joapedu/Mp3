#include <iostream>
#include <string>
#include "no.hpp"
#include "listaencadeada.hpp"
#include "musica.hpp"
#include "playlist.hpp"

//menu principal.
int menuPrincipal(ListaEncadeada<Musica> &musicas, ListaEncadeada<Playlist> &playlists);

//menu de gerenciar músicas.
void menuMusica(ListaEncadeada<Musica> &musicas, ListaEncadeada<Playlist> &playlists);

//menu de tocar músicas.
void tocarMusicas(ListaEncadeada<Playlist> &playlists);

//menu de gerenciar playlists.
void menuPlaylist(ListaEncadeada<Playlist> &playlists);

//menu de gerenciar músicas em playlists.
void menuMusicaPlaylist(ListaEncadeada<Musica> &musicas, ListaEncadeada<Playlist> &playlists);