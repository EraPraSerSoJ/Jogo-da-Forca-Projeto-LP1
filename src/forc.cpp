#include "/home/runner/Jogo-da-Forca/include/forc.hpp"



Forca::Forca(string arq_palavras, string arq_score) {
    arquivo_palavras = arq_palavras;
    arquivo_score = arq_score;
}

bool Forca::verifica_palavras() {
    ifstream file_palavras;
    file_palavras.open(arquivo_palavras);
    string linha;
    while (getline(file_palavras, linha)) { //verifica cada palavra do arquivo de palavrea
      
      for (int i = 0; i < linha.size(); i++) { //verifica cada letra da palavra sendo analisada
            int letra_int = (int)linha[i]; // transforma letra em int para comparar com valores da tabela ASCII
            bool valid; //criterio 1 de avaliação - se é letra ou hifen -
            if ((letra_int >= 65 && letra_int <= 90) || (letra_int >= 97 && letra_int <= 122) || (letra_int == 45)) {
                valid = true;
            }
            if (valid &&  (linha.size()>=4)) {}   //criterio 2 -se tem pelo menos 4 letras- 
            else {
                /*se existir uma palavra invalida no arquivo,mensagem de erro é exibida, 
                loop termina, fecha o arquivo e função retorna falso*/
                file_palavras.close();
                return false;
            }

        }

    }
    file_palavras.close();
    return true; //se nenhuma palavra for invalida, função retorna verdadeiro
}

//verifica validade de arquivo de scores
// falta verificar se espaços com nome, dificuldade ou pontuação estão vazios
bool Forca::verifica_score() {
    fstream file_scores;
    file_scores.open(arquivo_score);
    string linha;
    
    while(getline(file_scores, linha)) { // conta quantidade de ; por linha 
        scores.push_back(linha);
        int count = 0;
        for (int i = 0; i < linha.size(); i++) {
            int alvo = 59;
            int letra_int = (int)linha[i];
            if (letra_int == alvo && linha[i+1] == alvo) {
              file_scores.close();
              return false;
            }else if (letra_int == alvo && linha[i+1] == ' ' && linha[i+2] == alvo){
              file_scores.close();
              return false;
            }
            if (letra_int == alvo)
                count++;
        }
        if (count < 3 || count > 3){ //se a quantidade de ; for maior ou menor que 3 (por linha), função retorna falso 
            file_scores.close();
            return false;
        }
    }
    file_scores.close();
    return true;
}

//interface gráfica mostrando validação de arquivos de scores e palavras
void Forca::abertura(bool validade_score, bool validade_palavras) {
    cout<< ">  Lendo arquivos de palavras e scores, por favor aguarde..\n";
    cout<< "-----------------------------------------------------------------\n";
    if (validade_palavras && validade_score){
        cout<< ">  Arquivos OK!\n";
    }else if (!validade_palavras && !validade_score){
        cout<< ">  Arquivo de Palavras e Scores inválido!";
        exit(-1);
    }else if(!validade_palavras){
        cout<< ">  Arquivo de Palavras inválido!";
        exit(-1);
    }else{
        cout<< ">  Arquivo de Scores inválido!";
        exit(-1);
    }
    cout<< "-----------------------------------------------------------------\n";
    return;
}

void Forca::cabecalho () {
  cout << " $$$$$$$$\\  $$$$$$\\  $$$$$$$\\   $$$$$$\\   $$$$$$\\" << endl;   
  cout << "$$  _____|$$  __$$ \\$$  __$$ \\$$  __$$ \\$$  __$$ \\" << endl; 
  cout << "$$ |      $$ /  $$ |$$ |  $$ |$$ /  \\__|$$ /  $$ |" << endl;
  cout << "$$$$$\\    $$ |  $$ |$$$$$$$  |$$ |      $$$$$$$$ |" << endl;
  cout << "$$  __|   $$ |  $$ |$$  __$$< $$ |      $$  __$$ |" <<endl;
  cout << "$$ |      $$ |  $$ |$$ |  $$ |$$ |  $$\\ $$ |  $$ |" << endl;
  cout << "$$ |       $$$$$$  |$$ |  $$ |\\$$$$$$  |$$ |  $$ |" << endl;
  cout << "\\__|       \\______/ \\__|  \\__| \\______/ \\__|  \\__|" << endl;
  cout <<"\n\n\n";
                                                 
}

//interface gráfica do menu de escolhas do jogador
int Forca::menu () {
    int escolha;
    bool escolha_invalida = true;
    cout << "\n\n<><><><><><><><> - JOGO DA FORCA - <><><><><><><><>\n\n ";
    while(escolha_invalida) {
        cout << "Escolha a opção desejada:\n\n";
        cout << "1 - Inciar jogo \n2 - Ver scores anteriores\nSua escolha:  ";
        cin >> escolha;
        if (escolha == 1 || escolha == 2)
            escolha_invalida = false;
        else    
            cout << "\n\n\nXXXXXXX - Digite uma escolha válida! - XXXXXXX\n\n\n";
    }
    return escolha;
}

void Forca::imprime_score() {
    fstream file_scores;
    file_scores.open(arquivo_score);
    string linha;
    cout << "\n\n<><><><><><><><> - SCORES ANTERIORES - <><><><><><><><>\n\n";
    
    while(getline(file_scores, linha)) { // imprime o conteudo de cada linha
        cout << linha << endl;
    }

}

void Forca::escolhe_dificuldade() {
    int escolha = 0;
    
    cout << "\n\n<><><><><><><><> - VAMOS INICIAR - <><><><><><><><>\n\n ";

    while (escolha != 1 && escolha != 2 && escolha != 3) {
        cout << "Escolha o nível de dificuldade\n";
        cout << "1 - Fácil\n2 - Médio\n3 - Dificil\n";
        cout << "\nSua esolha: ";
        cin >> escolha;    
        if (escolha != 1 && escolha != 2 && escolha != 3){
            cout << "\n\n\nXXXXXXX - Digite uma escolha válida! - XXXXXXX\n\n\n";
        }else{
            break;
        }
    }
    if (escolha == 1){
        dificuldade = "Facil";
    }else if (escolha == 2){
        dificuldade = "Medio";
    }else{
        dificuldade = "Dificil";
    }
}
 


void Forca::carrega_palavras() {
    ifstream file_palavras;
    file_palavras.open(arquivo_palavras);
    string linha;
    while (getline(file_palavras, linha)) {
      for (int i = 0; i < linha.size(); i++) { //deixa todas as palavras com letras maiúsculas, para padronização
          linha[i] = toupper(linha[i]);
      }
      
      
        palavras.push_back(linha);
  }
}

void Forca::sorteia_palavra(){

    unsigned seed = time(0);
    srand(seed);

    int pos = rand() % palavras.size();
    palavra_secreta = palavras.at(pos);
    palavras_jogadas.push_back(palavra_secreta);
}

// setters e getters
    string Forca::get_dificuldade() {
        return dificuldade;
    }



bool Forca::verifica_letra(char letra_palavra){
  bool acerto = false;
		if(chute == letra_palavra) {
			acerto = true;
      contador_acertos++;//corrigir erros de multiplas letras por chute
		}

  return acerto;
}


void Forca::imprime_secreta(){
  for(int i = 0; i < palavra_secreta.size() ;i++){
    if(verifica_letra(palavra_secreta[i])){
      chutes_certos[i] = chute;
      guarda_chutes[i] = chute;
    }
    if(i == palavra_secreta.size()-1){
      contador_acertos = 0;
      contador_turnos++;
    }
    if(chutes_certos[i] == '$'){
      cout << "_";
    }else{
      cout << chutes_certos[i];
    }
  }
  cout << endl;
}

void Forca::le_chute() {

    cout << "Digite seu chute: ";
    cin >> chute;
    chute = toupper(chute);//transforma chute em maiusculo para evitar erros
    aux_chute = chute;
    for(int i = 0; i < palavra_secreta.size();i++){
        if(verifica_letra(palavra_secreta[i])){
          pontos++;
        }else if(contador_acertos == 0 && i == palavra_secreta.size()-1){
          cout << "Poxa, essa letra não está na palavra! Tente novamente.";
          pontos--;
          erros++;
        }
    }
}



void Forca::imprime_boneco(){
  cout << endl;
  cout << "<><><><><><><><> - TURNO " << contador_turnos<< " - <><><><><><><><>" << endl;
  cout << endl;
  if(erros == 0){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 1){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 2){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /       "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 3){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /|      "<< endl;
  	cout << " |              "<< endl;
    cout << " |              "<< endl;
  	cout << "_|___           ";
  	cout << endl << endl;
  }else  if(erros == 4){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /|\\    "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 5){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /|\\    "<< endl;
  	cout << " |      /       "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 6){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /|\\    "<< endl;
  	cout << " |      / \\    "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }
}


int Forca::get_erros(){
  
  return erros;
}

int Forca::get_pontos(){
  return pontos;  
                  
}  
string Forca::get_secreta(){
    return palavra_secreta;
}

bool Forca::condicao_vitoria(){
  int BO = 0;
  BO = 0;
  for(int i = 0; i < palavra_secreta.size();i++){
    if(chutes_certos[i] == '$'){
      BO++;
    }
  }
  if(pontos == palavra_secreta.size()){
    pontos = pontos+2;
    if (erros == 0) {
      pontos++;
    }
    return true;
  }else if(BO == 0){
    pontos = pontos+2;
    if (erros == 0) {
      pontos++;
    }
    return true;
  }else{
    return false;
  }
  
}

bool Forca::verifica_chute_repetido(){
 if (chutes_certos.find(aux_chute) != string::npos){
    pontos = pontos - contador_acertos;//correçao de multiplos erros por chute
    return true;
  }else{
    return false;
  }
}
void Forca::gera_dica () {
    unsigned seed = time(0);
    srand(seed);
    int qtd_dica, max_dica = (palavra_secreta.size()/5);

    if (max_dica == 1 || max_dica == 0) {
      qtd_dica = 1;

    }else if (max_dica > 1) {
        qtd_dica = (rand() % max_dica)+1;
        
    }

    cout << "qtd de dica: " << qtd_dica << endl;
    if (dificuldade == "Facil") {
        int cont = 0;
        if (qtd_dica > 0) { // gerando as dicas!!
            for (int i = 0; i < palavra_secreta.size(); i++) {
                int int_letra = (int)palavra_secreta[i];
                if (int_letra != 65 && int_letra != 69 && int_letra != 73 && int_letra != 79 && int_letra != 85) {
                    char dica = (char)int_letra;
                    adiciona_dica(dica);
                    cont++;
                }

                if (cont == qtd_dica){
                    break;
                }
            }
        }
    }else if (dificuldade == "Medio"){
      int cont = 0;
        if (qtd_dica > 0) { // gerando as dicas!!
            for (int i = 0; i < palavra_secreta.size(); i++) {
                int int_letra = (int)palavra_secreta[i];
                if (int_letra == 65 || int_letra == 69 || int_letra == 73 || int_letra == 79 || int_letra == 85) {
                    char dica = (char)int_letra;
                    adiciona_dica(dica);
                    cont++;
                }

                if (cont == qtd_dica){
                    break;
                }
            }
        }

    }

}

void Forca::adiciona_dica(char dica) {
  for (int i=0; i < palavra_secreta.size(); i++) {
    if (dica == palavra_secreta[i]) {
      chutes_certos[i] = dica;
    }
  }
}

char Forca::get_chute(){
  return chute;
}

void Forca::remove_palavra_jogada() {
  for (auto it = palavras.begin(); it != palavras.end(); ++it) {
    auto i = distance(palavras.begin(), it);
    if (palavras.at(i) == palavra_secreta) {
        palavras.erase(it);
    }
  }
}

void Forca::adiciona_palavra_jogada(){ //adiciona palavra jogada
                                       //no vector de palavras jogadas
  palavras_jogadas.push_back(palavra_secreta);
}

bool Forca::menu_jogar_novamente() {
  int escolha = 0;
  while (escolha != 1 && escolha !=2) {
    cout << "\n\n<><><><><><><><> - MENU - <><><><><><><><>\n\n ";
    cout << "Deseja jogar outra partida?" << endl;
    cout << "1 - Sim\n2 - Não\nSua escolha: ";
    cin >> escolha;
    if (escolha == 1 || escolha == 2) {
      break;
    }
    system("clear");
    cout << "\n\t !! Digite uma escolha válida !!\n" << endl;
    
  }
  if (escolha == 1) {
    cout << "\n>Okay, se prepare para um novo desafio!" << endl;
    jogar_novamente = true;
    return true;
  }else{
    jogar_novamente = false;
    cout << "\n>Certo! Vamos atualizar o arquivo de score com sua pontuação."<< endl;
    return false;
  }
}


void Forca::reseta_partida() {
  chutes_certos = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
  guarda_chutes = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
  erros = 0;
  chute = '%';
  contador_turnos = 1;
  total_pontos = total_pontos+pontos;
  pontos = 0;
}

void Forca::finaliza_jogo() {
  cout << "\n\n<><><><><> - FIM DE JOGO - <><><><><>\n\n ";
  cout << "Digte seu nome para que seu score seja adicionado no arquivo de scores." << endl;
  cout << "\nSeu nome: ";
  cin >> nome_jogador;
}

void Forca::atualiza_score() {
  ofstream arq_scores;
  arq_scores.open("score.txt");
  
  //escrevendo no arquivo 
  for (int i=0; i < scores.size(); i++) {
    arq_scores << scores.at(i);
    arq_scores << "\n";
  }

  arq_scores << dificuldade << ";" << " ";
  arq_scores << nome_jogador << "; ";
  for (int i = 0; i < palavras_jogadas.size(); i++) {
    if (i == palavras_jogadas.size()-1) {
      arq_scores << palavras_jogadas.at(i) << "; ";
      
    }else{
      arq_scores << palavras_jogadas.at(i) << ", ";
    }
  }

  arq_scores << total_pontos;
  arq_scores.close();
}

void Forca::recebe_nome_jogador() {
  cout << "\n\nDigite seu nome por favor: ";
  cin >> nome_jogador;
}