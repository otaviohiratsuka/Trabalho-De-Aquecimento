#ifndef CONFIG_HPP
#define CONFIG_HPP


//Estado da celula
const int VAZIO = 0;
const int ARVORE_SAUDAVEL = 1;
const int ARVORE_EM_CHAMAS = 2;
const int ARVORE_QUEIMADA = 3;
const int AGUA = 4;
const int ANIMAL = 5;
const int SEGURO = 6;

//tamanho da floresta
const int TAM_LINHAS = 10;
const int TAM_COLUNAS = 10;

//config de simulação
const int MAX_INTERACOES = 100;
const int MAX_REPOUSO = 3;
const int DURACAO_FOGO = 3;

enum PrioridadeMovimento{
    MELHOR = 0,
    INTERMEDIARIA,
    PIOR
};


#endif