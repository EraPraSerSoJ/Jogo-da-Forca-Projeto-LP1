+                 ---------------------------***JOGO DA FORCA***----------------------------
+
+ #AUTORES: Ana Catarina Gonçalves Fuentes, João Carlos Alves Júnior.
+ 1.0 ORGANIZAÇÃO
+-----------------	
+ O Projeto contém 3 pastas: src, include e data. Em src temos os arquivos .cpp  e
+ os executáveis (que devem apenas ser executados pela linha de comando).
+ Na pasta include está o arquivo .hpp, sendo ele o arquivo de cabeçalho da classe Forca.
+ Em data estão os arquivos utilizados pelo programa, o arquivo de palavras e de score.
+ 
+ 2.0 REQUISITOS
+----------------
+ Para executar o jogo é necessário possuir o g++, para compilar os arquivos.
+ É preferível que seja executado no SO Windows, para que todas as features funcionem de maneira
+ apropriada.
+
+ 3.0 COMPILAÇÃO
+-----------------
+ Para compilar basta digitar o comando abaixo na linha de comando:
+ g++ -o prog main.cpp forc.cpp
+ NOTA: Não é necessário realizar a compilação caso não queira, já existe um arquivo
+ executável dentro da pasta src.
+
+ 4.0 EXECUÇÃO
+----------------
+ Após o processo de compilação, e com o executável pronto, basta digitar o comando abaixo:
+ prog ../data/palavras.txt ../data/scores.txt
+ OBSERVAÇÃO: O caminho para o arquivo de palavras deve SEMPRE vir antes do caminho para o arquivo
+ de scores.
+
+ 5.0 FEATURES IMPLEMENTADAS
+------------------------------
+ #1 - Verificação de validade de arquivo de Palavras
+ #2 - Verificação de validade de arquivo de Scores
+ #3 - Criação de interface gráfica interativa
+ #4 - Criação e implementação da classe Forca
+ #5 - Menu de escolhas interativo
+ #6 - Verificação de chutes repetidos (impossibilidade de perder chutando a mesma letra ou de burlar o jogo ganhando vários pontos com a mesma letra)
+ #7 - Presença de dicas a partir da dificuldade escolhida 
+ #8 - Representação visual da forca e do "jogador" a cada erro
+ #9 - Possibilidade de jogar nova partida em caso de vitória (sem possibilidade de repetir palavras já jogadas)
+ #10 - Atualização de arquivo de scores após partida jogada.
+
+ 6.0 INTERATIVIDADE
+ -------------------------
+ Repassamos nosso trabalho para o repl.it para que possa ser jogado por outras pessoas
+ e assim criar um histórico de scores de maneira orgânica, ao mesmo tempo que serve de entretenimento.
+ Segue abaixo link do projeto pelo repl.it:
+ https://replit.com/@KhanForTheWin/Jogo-da-Forca?v=1
+
+

