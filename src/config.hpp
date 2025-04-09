#ifndef CONFIG_HPP
#define CONFIG_HPP

//Estado Floresta
const int VAZIO = 0;
const int ARVORE_SAUDAVEL = 1;
const int ARVORE_EM_CHAMAS = 2;
const int ARVORE_QUEIMADA = 3;
const int AGUA = 4;

//tamanho da floresta
const int TAMANHO_LINHAS = 100;
const int TAMANHO_COLUNAS = 100;

//simulacao
const int MAX_INTERACOES = 100;

//vento
const bool VENTO_ATIVADO = true;
const bool VENTO_ESQUERDA = true;
const bool VENTO_DIREITA = false;
const bool VENTO_CIMA = true;
const bool VENTO_BAIXO = false;

#endif
