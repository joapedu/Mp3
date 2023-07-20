#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/listaencadeada.hpp"
#include "../include/menu.hpp"
#include "../include/musica.hpp"
#include "../include/no.hpp"
#include "../include/playlist.hpp"
#include "arquivo.cpp"

/**
 * @brief Função principal do programa.
 *
 * @param argc Número de argumentos passados na linha de comando.
 * @param argv Vetor de strings contendo os argumentos da linha de comando.
 * @return 0 se o programa foi executado com sucesso, 1 caso contrário.
 */
int main(int argc, char *argv[]) {
  ListaEncadeada<Playlist> playlists;
  ListaEncadeada<Musica> musicas;

  // Verifica o número de argumentos passados na linha de comando
  if (argc != 2) {
    std::cout << "Número de argumentos inválido! "
              << "Esperado 1 argumento (nome do arquivo).\n";
    return 1;
  }

  std::ifstream in_file;
  in_file.open(argv[1]);

  // Verifica se o arquivo de entrada pode ser aberto
  if (!in_file.is_open()) {
    std::cout << "Não foi possível abrir o arquivo \"" << argv[1] << "\"!\n";
    return 1;
  }

  // Analisa o conteúdo do arquivo e carrega as músicas e playlists nas listas
  // correspondentes
  parseFile(in_file, musicas, playlists);

  in_file.close();

  int exit{0};

  // Executa o loop do menu principal até que o usuário escolha sair do programa
  while (exit == 0) {
    exit = menuPrincipal(musicas, playlists);
  }

  std::ofstream out_file;
  out_file.open(argv[1]);

  // Escreve as músicas e playlists no arquivo de saída
  writeFile(out_file, musicas, playlists);

  out_file.close();

  // Limpa as listas de músicas e playlists antes de encerrar o programa
  playlists.limpar();
  musicas.limpar();

  return 0;
}
