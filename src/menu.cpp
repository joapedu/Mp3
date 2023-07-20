#include "../include/menu.hpp"
#include "../include/listaencadeada.hpp"
#include "../include/musica.hpp"
#include "../include/no.hpp"
#include "../include/playlist.hpp"
#include <iostream>
#include <string>

/**
 * @brief Função que apresenta o menu principal do programa.
 *
 * @param musicas Lista encadeada de músicas disponíveis.
 * @param playlists Lista encadeada de playlists disponíveis.
 * @return 1 se o programa deve ser encerrado, 0 caso contrário.
 */
int menuPrincipal(ListaEncadeada<Musica> &musicas,
                  ListaEncadeada<Playlist> &playlists) {
  int escolha;

  std::cout << "Menu MP3\n";
  std::cout << "1. Área das playlists\n";
  std::cout << "2. Área das músicas\n";
  std::cout << "3. Área das músicas dentro das playlists\n";
  std::cout << "4. Tocar playlist\n";
  std::cout << "0. Sair\n";
  std::cout << "Digite o comando: ";

  std::cin >> escolha;
  std::cin.ignore();

  switch (escolha) {
  case 1:
    menuPlaylist(playlists);
    break;

  case 2:
    menuMusica(musicas, playlists);
    break;

  case 3:
    menuMusicaPlaylist(musicas, playlists);
    break;

  case 4:
    tocarMusicas(playlists);
    break;

  case 0:
    std::cout << "Até Mais!.\n";
    return 1;

  default:
    std::cout << "Erro: Escolha inválida!\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
    break;
  }

  return 0;
}

/**
 * @brief Função que apresenta o menu para interação com músicas.
 *
 * @param musicas Lista encadeada de músicas disponíveis.
 * @param playlists Lista encadeada de playlists disponíveis.
 */
void menuMusica(ListaEncadeada<Musica> &musicas,
                ListaEncadeada<Playlist> &playlists) {
  int escolha;

  std::cout << "Área das músicas\n";
  std::cout << "1. Adicionar Título\n";
  std::cout << "2. Remover Título\n";
  std::cout << "3. Listar Músicas\n";
  std::cout << "0. Voltar\n";
  std::cout << "Digite o comando: ";

  std::cin >> escolha;
  std::cin.ignore();

  std::string line;

  switch (escolha) {
  case 1: { // Adicionar música
    std::cout << "Digite o nome da música para adicionar, ou deixe em branco "
                 "para cancelar:\n";
    std::getline(std::cin, line);
    if (line != "") {
      if (musicas.buscarValor(Musica(line)) != nullptr) {
        std::cout << "Erro: A música \"" << line << "\" já existe.\n";
      } else {
        std::string author;
        std::cout << "Digite o nome do autor:\n";
        std::getline(std::cin, author);

        musicas.adicionar(Musica(line, author));
        std::cout << "Música \"" << line << "\" adicionada com sucesso.\n";
      }
    } else {
      std::cout << "Ação cancelada.\n";
    }
    break;
  }

  case 2: // Remover música
    std::cout << "Digite o nome da música para remover, ou deixe em branco "
                 "para cancelar:\n";
    std::getline(std::cin, line);
    if (line != "") {
      if (musicas.buscarValor(Musica(line)) == nullptr) {
        std::cout << "Erro: Música inválida.\n";
      } else {
        musicas.removerValor(Musica(line));

        No<Playlist> *curr = playlists.getCabeca();

        while (curr != nullptr) {
          curr->getValor().removerMusica(Musica(line));
          curr = curr->getProximo();
        }

        std::cout << "Música \"" << line << "\" removida com sucesso.\n";
      }
    } else {
      std::cout << "Ação cancelada.\n";
    }
    break;

  case 3: // Listar músicas
    if (musicas.getTamanho() == 0) {
      std::cout << "Nenhuma música cadastrada.\n";
    } else {
      std::cout << "Músicas:\n";
      musicas.imprimir();
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
 * @brief Função para tocar as músicas de uma playlist.
 *
 * @param playlists Lista encadeada de playlists disponíveis.
 */
void tocarMusicas(ListaEncadeada<Playlist> &playlists) {
  std::string line;
  std::cout
      << "Selecione a playlist para tocar, ou deixe em branco para cancelar:\n";
  std::getline(std::cin, line);

  if (line == "") {
    std::cout << "Ação cancelada.\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
    return;
  }

  Playlist *pl = playlists.buscarValor(Playlist(line));

  if (pl == nullptr) {
    std::cout << "Erro: Playlist inválida.\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
    return;
  }

  if (pl->getTamanho() == 0) {
    std::cout << "A playlist \"" << pl->getNome()
              << "\" não tem nenhuma música.\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
    return;
  }

  int end = 0;
  int count = 1;
  No<Musica> *curr = pl->getMusicas().getCabeca();

  while (end == 0) {
    int escolha;

    std::cout << "Tocando playlist \"" << pl->getNome() << "\".\n";
    std::cout << "Música " << count << " de " << pl->getTamanho() << ":\n";
    std::cout << curr->getValor() << "\n";
    if (curr->getProximo() == nullptr) {
      std::cout << "Última música da playlist.\n";
    } else {
      std::cout << "Próxima música: " << curr->getProximo()->getValor() << "\n";
    }
    std::cout << "1. Tocar Título seguinte\n";
    std::cout << "0. Parar de tocar\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> escolha;
    std::cin.ignore();

    if (escolha == 1) {
      curr = curr->getProximo();
      count++;
    } else {
      end = 1;
    }

    if (curr == nullptr) {
      std::cout << "A playlist acabou.\n";
      std::cout << "Pressione ENTER para continuar.";
      std::cin.get();
      end = 1;
    }
  }
}

/**
 * @brief Função que apresenta o menu para interação com playlists.
 *
 * @param playlists Lista encadeada de playlists disponíveis.
 */
void menuPlaylist(ListaEncadeada<Playlist> &playlists) {
  int escolha;

  std::cout << "Menu de Playlists\n";
  std::cout << "1. Adicionar Playlist\n";
  std::cout << "2. Remover Playlist\n";
  std::cout << "3. Listar Playlists\n";
  std::cout << "0. Voltar\n";
  std::cout << "Digite sua escolha: ";

  std::cin >> escolha;
  std::cin.ignore();

  std::string line;

  switch (escolha) {
  case 1: // Adicionar playlist
    std::cout << "Digite o nome da playlist para adicionar, ou deixe em branco "
                 "para cancelar:\n";
    std::getline(std::cin, line);
    if (line != "") {
      if (playlists.buscarValor(Playlist(line)) != nullptr) {
        std::cout << "Erro: A playlist \"" << line << "\" já existe.\n";
      } else {
        playlists.adicionar(Playlist(line));
        std::cout << "Playlist \"" << line << "\" adicionada com sucesso.\n";
      }
    } else {
      std::cout << "Ação cancelada.\n";
    }
    break;

  case 2: // Remover playlist
    std::cout << "Digite o nome da playlist para remover, ou deixe em branco "
                 "para cancelar:\n";
    std::getline(std::cin, line);
    if (line != "") {
      if (playlists.buscarValor(Playlist(line)) == nullptr) {
        std::cout << "Erro: Playlist inválida.\n";
      } else {
        playlists.removerValor(Playlist(line));
        std::cout << "Playlist \"" << line << "\" removida com sucesso.\n";
      }
    } else {
      std::cout << "Ação cancelada.\n";
    }
    break;

  case 3: // Listar playlists
    if (playlists.getTamanho() == 0) {
      std::cout << "Nenhuma playlist cadastrada.\n";
    } else {
      std::cout << "Playlists:\n";
      playlists.imprimir();
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
 * @brief Função que apresenta o menu para interação com músicas dentro de
 * playlists.
 *
 * @param musicas Lista encadeada de músicas disponíveis.
 * @param playlists Lista encadeada de playlists disponíveis.
 */
void menuMusicaPlaylist(ListaEncadeada<Musica> &musicas,
                        ListaEncadeada<Playlist> &playlists) {
  int escolha;

  std::cout << "Alterar Músicas nas Playlists\n";
  std::cout << "1. Adicionar Música em Playlist\n";
  std::cout << "2. Remover Música de Playlist\n";
  std::cout << "3. Listar Músicas de Playlist\n";
  std::cout << "0. Voltar\n";
  std::cout << "Digite sua escolha: ";

  std::cin >> escolha;
  std::cin.ignore();

  if (escolha == 0)
    return;

  std::string line;

  std::cout << "Digite o nome da playlist, ou deixe em branco para cancelar:\n";
  std::getline(std::cin, line);

  if (line == "") {
    std::cout << "Ação cancelada.\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
    return;
  }

  Playlist *pl = playlists.buscarValor(Playlist(line));

  if (pl == nullptr) {
    std::cout << "Erro: Playlist inválida.\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
    return;
  }

  switch (escolha) {
  case 1: { // Adicionar música em playlist
    std::cout << "Digite o nome da música para adicionar:\n";
    std::getline(std::cin, line);
    Musica *musica = musicas.buscarValor(Musica(line));

    // Caso música não exista no sistema
    if (musica == nullptr) {
      std::cout
          << "Erro: Música inválida. Adicione a música ao sistema primeiro.\n";
    }
    // Caso música já esteja na playlist
    else if (pl->buscarMusica(*musica) != nullptr) {
      std::cout << "Erro: Música já está na playlist.\n";
    } else {
      pl->adicionarMusica(*musica);
      std::cout << "Música adicionada com sucesso.\n";
    }
    break;
  }
  case 2: // Remover música de playlist
    std::cout << "Digite o nome da música para remover:\n";
    std::getline(std::cin, line);

    if (pl->buscarMusica(Musica(line)) != nullptr) {
      pl->removerMusica(Musica(line));
      std::cout << "Música removida com sucesso.\n";
    } else {
      std::cout << "Erro: Música não está na playlist.\n";
    }
    break;
  case 3: // Listar músicas de playlist
    if (pl->getTamanho() > 0) {
      std::cout << "Músicas da playlist \"" << pl->getNome() << "\":\n";
      pl->imprimirMusicas();
    } else {
      std::cout << "A playlist \"" << pl->getNome()
                << "\" não possui músicas.\n";
    }
    break;
  }
  std::cout << "Pressione ENTER para continuar.";
  std::cin.get();
}