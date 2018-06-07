# Corrida-de-Sapos
Trabalho de Linguagem de Programação (Corrida de Sapos)
# Autor
Felipe Augusto Oliveira Santos
# Compilação
$ g++ Corrida_Sapos.cpp -o ./bin/sapos
# Execução
$ ./bin/sapos
# Informações
Passos 1 e 2: No arquivo include/Funções.hpp as funções de leitura de arquivos são implementadas no inicio de cada função necessária para alguma tarefa

Passo 3:

a) A visualização de estatística dos sapos é feita através da função estatisticas_sapos(),  no arquivo include/Funções.hpp na linha 99, é chamada na linha 14 de src/Corrida_Sapos.cpp

b) A visualização de estatística das pistas é feita através da função estatisticas_pistas(),  no arquivo include/Funções.hpp na linha 117,
é chamada na linha 17 de src/Corrida_Sapos.cpp

c) A função para iniciar a corrida é implementada em include/Funções.hpp na linha 312 e é chamada em src/Corrida_Sapos.cpp na linha 57

d) A função para criar sapos implementada em include/Funções.hpp pela função criar_sapo() localizada na linha 209, é chamada na linha 28 de 
src/Corrida_Sapos.cpp 

e) A função para criar pistas implementada em include/Funções.hpp pela função criar_pista() localizada na linha 263, é chamada na linha 35 de 
src/Corrida_Sapos.cpp 

Passo 4:

a) A função para escolher pista é chamada na dentro da função iniciar_corrida() linha 277 do arquivo include/Funções.hpp

b) A função para mostrar Sapos é uma função para mostrar os sapos que irão correr e é chamada na linha 314 da função iniciar_corrida e encontra-se no arquivo include/Funções.hpp

c) O usuário da o start na corrida na linha 22 do arquivo scr/Corrida_Sapos.cpp chamando a função iniciar_corrida();

Passo 5:

a) Os sapos pulam individualmente na linha 341 da função iniciarCorrida(), no arquivo include/Funções.hpp 

b) Quando o sapo chega ao final da corrida os outros deixam de pular e o vencedor é anunciado

Doxygen: arquivo Doxyfile na pasta principal 
