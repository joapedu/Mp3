#include "listaencadeada.hpp"
#include "musica.hpp"
#include "no.hpp"
#include "playlist.hpp"
#include <iostream>
#include <string>

/**
 * Função para exibir o menu principal do programa.
 * @param musicas A lista encadeada de músicas disponíveis no sistema.
 * @param playlists A lista encadeada de playlists disponíveis no sistema.
 * @return O código da opção selecionada pelo usuário no menu principal.
 */
int menuPrincipal(ListaEncadeada<Musica> &musicas,
                  ListaEncadeada<Playlist> &playlists);

/**
 * Função para exibir o menu de gerenciamento de músicas.
 * @param musicas A lista encadeada de músicas disponíveis no sistema.
 * @param playlists A lista encadeada de playlists disponíveis no sistema.
 */
void menuMusica(ListaEncadeada<Musica> &musicas,
                ListaEncadeada<Playlist> &playlists);

/**
 * Função para exibir o menu de reprodução de músicas.
 * @param playlists A lista encadeada de playlists disponíveis no sistema.
 */
void tocarMusicas(ListaEncadeada<Playlist> &playlists);

/**
 * Função para exibir o menu de gerenciamento de playlists.
 * @param playlists A lista encadeada de playlists disponíveis no sistema.
 */
void menuPlaylist(ListaEncadeada<Playlist> &playlists);

/**
 * Função para exibir o menu de gerenciamento de músicas em playlists.
 * @param musicas A lista encadeada de músicas disponíveis no sistema.
 * @param playlists A lista encadeada de playlists disponíveis no sistema.
 */
void menuMusicaPlaylist(ListaEncadeada<Musica> &musicas,
                        ListaEncadeada<Playlist> &playlists);
