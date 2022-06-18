#include "/home/runner/Jogo-da-Forca/include/forc.hpp"
#include <fstream>
#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Portuguese");

  string palavras = "/home/runner/Jogo-da-Forca/data/pal.txt"; // argv[1] caso usado em cmd
  string scores = "/home/runner/Jogo-da-Forca/data/score.txt"; // argv[2] 

  Forca *jogo = new Forca(palavras, scores);
  
  jogo->abertura(jogo->verifica_score(), jogo->verifica_palavras());

  int escolha = 2;
  while (escolha ==
         2) { // ***modularizar isso em uma função fora da classe Forca
    escolha = jogo->menu();
    system("clear");
    if (escolha == 1) {
      system("clear");
      break;
    }
    jogo->imprime_score();
  }
  jogo->carrega_palavras();
  bool novo_jogo = true;
  jogo->cabecalho();

  while (novo_jogo) {
    jogo->escolhe_dificuldade();
    jogo->sorteia_palavra();
    jogo->reseta_partida();
    jogo->gera_dica();
    int erros = 0;
    int pontos = 0;

    system("clear");

    while (erros < 6) {
    returnHere:

      erros = jogo->get_erros();
      jogo->imprime_boneco();
      cout << endl;
      jogo->imprime_secreta();
      pontos = jogo->get_pontos();
      cout << "Pontos: " << pontos << endl;
      if (erros > 5) {
        cout << "\n\nO jogo acabou, a palavra era ";
        string a = jogo->get_secreta();
        cout << a;
        break;
      }
      if (jogo->condicao_vitoria()) {
        cout << "Voce venceu! A palavra era " << jogo->get_secreta() << endl;
        cout << "Pontuação final: " << jogo->get_pontos() << endl;
        break;
      }
      jogo->le_chute();
      if (jogo->verifica_chute_repetido()) {
        char chute;
        chute = jogo->get_chute();
        system("clear");
        cout << "Voce já chutou " << chute << "! Tente outro chute." << endl;
        goto returnHere;
      }
      system("clear");
    }
    // system("pause") no windows
    if (jogo->condicao_vitoria()) {
      novo_jogo = jogo->menu_jogar_novamente();
    }else {
      
      break;
    }

    system("clear");
  }
  jogo->recebe_nome_jogador();
  jogo->atualiza_score();
}
