# Simulação de Propagação de Incêndios 🔥

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/otaviohiratsuka">
</a> 
</div>

</hr>

# OBJETIVOS
<div align="justify">
<p>Foi proposto pelo professor Michel Pires na disciplina de Algorítimo e Estrtura de Dados I, um trabalho no qual o objetivo era a implementação de um simulador de propagação de incêndio em um floresta, usando as linguagens C ou C++. Esse simulador deve modelar, em uma matriz bidimensional, o comportamento do fogo e a movimentação de um animal tentando escapar das chamas. </p>

<p>🎯 Esse projeto visa: </br>
<b>-Praticar programação com vetores/matrizes </br></b>
<b>-Refletir sobre desempenho e estratégias algorítmicas </br></b>
<b>-Discutir padrões de propagação e algoritmos emergentes </br></b>
<b>-Desenvolver pensamento crítico e habilidades na documentação </br></b>
</p>
<p>Após a apresentação do tema, bem como a demonstração dos objetivos, serão apresentados todos os resultados obtidos a partir dos testes feitos.</p>

# PROPOSTA

<p>O que o projeto propõe? A ideia central é simular, passo a passo, como o fogo se espalha entre as árvores e como um animal tenta escapar dessa situação, movimentando-se pela matriz em busca de segurança — especialmente tentando alcançar áreas com água. Para realizar o algoritmo foram necessarias algumas regras como:</p>

<h3>Regras de Propagação de Incêndio 🔥</h3>
A floresta é representada por uma matriz de dimensões N x M, onde cada célula pode conter:
<ul>
<li><code>0</code> -> Área Vazia (não queima) </li>
<li><code>1</code> -> Árvore Saudável </li>
<li><code>2</code> -> Árvore em Chamas </li>
<li><code>3</code> -> Árvore Queimada </li>
<li><code>4</code> -> Água</li>
</ul>

<p><b>1. Como o fogo se espalha?</b></br>
O fogo começa em um ponto específico do mapa (informado no arquivo <code>input.dat</code>). A cada rodada (ou iteração), ele se espelaha para os lados: </br>
Para cima <code>↑</code>, para baixo <code>↓</code>, para esquerda <code>←</code> e para a direta <code>→</code>. </br>
<b>📌Importante:</b> O fogo não se espalha na diagonal.
</p>

<p><b>2. Quem pode pegar fogo?</b></br>
Só as árvores saudáveis (<code>1</code>) podem pegar fogo. Se uma árvore está do lado de uma árvore em chamas(<code>2</code>), ela vai pegar na proxima iteração.
</p>

<p><b>3. O que acontece com uma árvore em chamas?</b></br>
Assim que uma árvore pega fogo, ela queima por uma rodada. Na rodada seguinte, ela vira uma árvore queimada(<code>3</code>) e não pega fogo novamente.
</p>

<p><b>4. Quando a simulação para? </b></br>
A propagação continua até que não exista mais árvores em chamas na matriz. Ou até alcançar o número maximo de rodadas definidas (variável <code>K</code>).
</p>

<h3>Regras de Movimentação do Animal 🦊</h3>
Um animal está presente na floresta e deve escapar do fogo se movimentando em busca de segurança. A cada rodada da simulação, ele age antes do fogo. Seu objetivo é sobreviver, de preferência alcançando a água.</br></br>

<p><b>1. Onde o animal pode estar?</b></br>
Ele começa em uma posição segura, ou seja, numa célula com área vazia <code>0</code> ou árvore saúdavel <code>1</code>. A posição inicial é escolhida automaticamente, não é informada pelo usuário.
</p>

<p><b>2. Como ele escolhe para onde ir?</b></br>
O animal olha para os quatro lados (cima, baixo, esquerda, direita) e escolhe o melhor caminho possível com base em uma hierarquia de prioridade:
<ul>
  <li><b>Melhor opção:</b> ir para a água <code>4</code>.</li>
  <li><b>Opção intermediarias:</b> ir para uma área vazia <code>0</code> ou uma árvore saudável <code>1</code>.</li>
  <li><b>Pior opção:</b> Só vá para árvore queimada <code>3</code> se não tiver outra saída.</li>
</ul>
Ele pode ficar parado por até 3 rodadas seguidas num local vazio <code>0</code>, já que o fogo não atinge essas áreas.
</p>

<p><b>3. O que acontece se ele achar água?</b></br>
Assim que o animal chegar em um posição com água, as células ao redor da água ficam mais "úmidas" e viram árvores saudáveis <code>1</code>.
</p>

<p><b>4. E se o fogo alcançar o animal?</b></br>
Se o animal estiver em uma posição e o fogo chegar lá na mesma rodada, ele tem uma última chance de escapar rapidamente,<b>mas</b> se todas as saídas estiverem bloqueadas por fogo recém-chegado, ele não consegue fugir.
</p>

<p>Durante a simulação, o sistema deve anotar quantos passos o animal deu, quantas vezes ele encontrou água, em qual rodada ele ficou preso ou morreu(se isso acontecer), se ele conseguiu sobreviver até o final.</p>

</hr>

# LÓGICA UTILIZADA

<h2>Estrutura do Projeto</h2>
<ul>
  <li><code>build</code>: onde está localizado os object (.o) e o executavel para a compilação app.exe</li>
  <li><code>src</code>: onde está localizado os arquivos do código-fonte</li>
    <ul><li><code>Animal.hpp</code> </li>
      <li><code>Animal.cpp</code></li>
      <li><code>Floresta.hpp</code></li>
      <li><code>Floresta.cpp</code></li>
      <li><code>config.hpp</code></li>
      <li><code>main.cpp</code></li>
      <li><code>input.dat</code></li>
      <li><code>output.dat</code></li>
    </ul>
      <li><code>Makefile</code>: Arquivo usado para compilar e executar o programa</li>   
      <li><code>README.MD</code>: Documentação do código</li>
</ul>

<h2>config.hpp</h2>
Essa classe serve para configurar todas as variáveis globais do sistema:

```
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
    INTERMEDIARIA = 1,
    PIOR = 2
};


#endif
```



<h2>Classes</h2>

<h3>Animal 🦊</h3>
</hr>
<b>Como ele se move?</b>
</br>
O principal método da classe é o:                  

[`bool Animal :: mover(vector<vector<int>>& matriz)`](https://github.com/otaviohiratsuka/Trabalho-De-Aquecimento/blob/main/src/Animal.cpp#L51-L123)


Antes de começar a mover, o animal avalia as células ao redor usando a função
[`PrioridadeMovimento Animal :: avaliarPrioridade(int tipoCelula) const;`](https://github.com/otaviohiratsuka/Trabalho-De-Aquecimento/blob/main/src/Animal.cpp#L8-L25)
ela define a ordem de preferência:
<ul>
  <li><b>Melhor opção(0): <code>AGUA</code> (valor 4)</b></li>
  <li><b>Opções Intermediarias(1): <code>VAZIO</code> (valor 1) e <code>ARVORE_SAUDAVEL</code> (valor 1)</b></li>
  <li><b>Pior opção(2):</b> <code>ARVORE_QUEIMADA</code> (valor 3)</li>
  <li> <code>ARVORE_EM_CHAMAS</code> sempre deve ser evitado -  se o animal estiver em uma celula em chamas, morre instantaneamente.</li>
</ul>

Agora, com as prioridades configuradas o animal precisa fazer algumas verificações antes de começar a se mover. A primeira verificação é do seu estado, se está vivo ou morto: <code>if (!estaVivo()) return false;</code> Se o animal já morreu, não se move mais. Após isso, o animal verifica células adjacentes(cima, baixo, esquerda, direta) para o fogo, usando uma variavel [<code>fogoAdjacente</code>](https://github.com/otaviohiratsuka/Trabalho-De-Aquecimento/blob/main/src/Animal.cpp#L64-L76) .Se houver fogo próximo, o animal interrompe o repouso com o <code>break;</code>

Assim que o animal chega em um celula segura (<code>VAZIO</code> ou <code>AGUA</code>) ele pode repousar. O animal só sai do repouso se houver fogo por perto e tiver execedido o tempo máximo de repouso(<code>MAX_REPOUSO</code>).

A [lógica do movimento](https://github.com/otaviohiratsuka/Trabalho-De-Aquecimento/blob/main/src/Animal.cpp#L93-L110) funciona da seguinte forma. Se o animal não estiver em repouso, é gerado uma lista de células adjacentes válidas(excluindo fogo). Ordena as opções por prioridade, usando <code>avaliarPrioridade()</code>. Depois de ordenadar as opções (<code>sort(opcoes.begin(), opcoes.end());</code>), o animal escolhe a melhor célula disponível (<code>posicao = opcoes[0].second;</code>). E no final contabiliza a quantidade de passos.

Como dito anteriormente, a melhor opção sempre vai ser a <code>AGUA</code>, e isso não é por acaso. Assim que o animal alcança n valor 4 a função <code>encontrarAgua()</code> é ativada. E a primera ação da função é transformar a celula atual (4) em uma celula vazia (0): <code>matriz[posicao.first][posicao.second] = VAZIO;</code>. Logo após, inicia-se o efeito principal: a regeneração das células ao redor.
Primeiro, um loop percorre as quatro direções (cima, baixo, esquerda e direita), aplicando as transformações necessárias.
[Loop](https://github.com/otaviohiratsuka/Trabalho-De-Aquecimento/blob/main/src/Animal.cpp#L137) | [Transformações](https://github.com/otaviohiratsuka/Trabalho-De-Aquecimento/blob/main/src/Animal.cpp#L141-L146) .

<h3>Floresta 🌳</h3>
A classe Floresta é o núcleo da simulação, responsável por gerenciar o ambiente, a propagação do fogo e a interação com o animal. A floresta tem como resposabilidade iniciar a matriz e posicionar o animal nas coordenadas (x,y) <code>Floresta(int x, int y)</code> . Outro método chave é <code>carregaArquivo(string arquivo)</code>, onde lê o <code>input.dat</code> para carregar o mapa incial da floresta.



<br><b>Como acontece a propagação do fogo?</b><br>



A função <code>propagaFogo()</code> é responsável por simular a propagação do incêndio na floresta. Essa função permite o controle de pausa, criação de matriz temporária (evita que as alterações afetem o cálculo das células vizinhas durante a iteração.).

No funcionamento das chamas, há um looping que percorre todas as células a matriz para verificar se está em chamas. Depois incrementa <code>tempoFogo</code> para células em chamas. Se antingir <code>DURACAO_FOGO</code>, a celula vira <code>ARVORE_QUEIMADA</code>. [Células em Chamas](https://github.com/otaviohiratsuka/Trabalho-De-Aquecimento/blob/main/src/Floresta.cpp#L95-L98). 
A propagação só acontece em <code>ARVORE_SAUDAVEL</code> e <code>VAZIO</code>.
```cpp
// Define direções de propagação
vector<pair<int, int>> direcoes;
if (ventoAtivado) {
    direcoes = {{-1,0}, {0,-1}, {1,0}, {0,1}};  // Ordem específica com vento
} else {
    direcoes = {{-1,0}, {1,0}, {0,-1}, {0,1}};  // Ordem padrão
}

// Propaga para células vizinhas
for (const auto& dir : direcoes) {
    int ni = i + dir.first;
    int nj = j + dir.second;
    
    // Verifica limites da matriz
    if (ni >= 0 && ni < TAM_LINHAS && nj >= 0 && nj < TAM_COLUNAS) {
        // Pega fogo se for árvore saudável ou vazio
        if (matriz[ni][nj] == ARVORE_SAUDAVEL || matriz[ni][nj] == VAZIO) {
            novaMatriz[ni][nj] = ARVORE_EM_CHAMAS;
            tempoFogo[ni][nj] = 1;  // Inicia contador
        }
    }
}
```
*Código decrito em: [linha 100 a 114](https://github.com/otaviohiratsuka/Trabalho-De-Aquecimento/blob/main/src/Floresta.cpp#L100)*
Obs.: O vento alerata a ordem de propagação para simular a direção do vento.

Ápos isso, as mudanças são aplicadas atualizando a matriz principal <code>matriz = novaMatriz;</code> 

[Exemplo Prático]
```
[1, 0, 1]  
[1, 2, 1]  // 2 = ARVORE_EM_CHAMAS
[1, 1, 4]

[2, 2, 2]  
[2, 3, 2]  // 3 = ARVORE_QUEIMADA
[2, 2, 4]

[3, 3, 3]  
[3, 3, 3]  // 4 = AGUA
[3, 3, 4]
```

<br><b>Interação com o Animal</b><br>

O método <code>simular(int maxIterações)</code> é resposavel por mostrar a iterações. Mostrando se o animal morreu preso no fogo(<code>verificarMortePorFogo()</code>) ou se o fogo foi extinto(se não há mais células <code>ARVORE_EM_CHAMAS</code>) (<code>temFogo()</code>).

Também é apresentado um função chamada <code>darSegundaChance()</code>, que permite que o animal consiga fugir do fogo quando ele está adjacente, pausando o fogo(<code>fogoPausado=true</code>) e força um movimento de emergencia.

Para complementar a função existem alguns outros métodos auxiliares como: <code>temFogo()</code>, <code>salvaArquivo(string arquivo, int iteracao)</code> e <code>mostrarEstadoTerminal()</code>.

<h3>main.cpp</h3>
A main.cpp tem a simples função de puxar todos os métodos, carregar o arquivo <code>input.dat</code>, limpar o arquivo <code>output.dat</code> e posicional o animal inicialmente <code>Floresta floresta(x,y).</code>

<h2>Resultados</h2>
Para um breve exemplo, foi usado uma matriz 10x10 para mostrar os métodos funções do código.

A função <code>encontrarAgua()</code> em ação:



<img src="https://cdn.discordapp.com/attachments/426138366703173643/1365868472189583465/image.png?ex=680edfa4&is=680d8e24&hm=5afc8b01b08efeb46a176f133783db709f5a14bc64ffe442cf4499bf05f24d11&" alt=transform_agua width="500px">


A celula 5 transforma as suas celulas adjacentes em <code>ARVORE_SAUDAVEL</code>.


A função <code>verificaMortePorFogo()</code>:



<img src="https://cdn.discordapp.com/attachments/426138366703173643/1365869802530275471/image.png?ex=680ee0e1&is=680d8f61&hm=a95776a9bf3d160b4848514754a0a55fa97381e66b8100119b90531074b5760a&" alt=transform_agua width="500px">


A fogo "engole" a celula(5) e atualiza o estado do animal de vivo para morto


</hr>

#CONCLUSÃO
</hr>
Este projeto teve como objetivo desenvolver uma simulação de incêndio florestal utilizando a linguagem C++, modelando uma situação dinâmica onde um animal tenta sobreviver a uma floresta em chamas.A estrutura do projeto foi fundamentada em Programação Orientada a Objetos (POO), com a definição clara de duas principais entidades: <code>Animal</code> e <code>Floresta</code>. Cada uma delas foi responsável por gerenciar partes específicas da simulação — o animal focando em movimentação e sobrevivência, enquanto a floresta controla o ambiente e a propagação do fogo.
A simulação implementou diversos comportamentos realistas:
<ul>
  <li>Propagação dinâmica de fogo para células adjacentes.</li>
  <li>Mecanismo de "segunda chance" para o animal em situações de perigo iminente, pausando o fogo temporariamente para permitir fuga.</li>
  <li>Espalhamento de água ao encontrar fontes (4), curando árvores ao redor.</li>
  <li>Contador de iterações para medir o progresso da simulação.</li>
  <li>Gravação automática do estado da floresta a cada passo, garantindo análise posterior através de arquivos.</li>
</ul>
Além disso, melhorias importantes foram implementadas, como a organização dos arquivos de saída dentro do diretório correto e o tratamento de casos críticos de forma robusta.

Em resumo, o projeto alcançou uma simulação funcional, estratégica e realista de incêndio florestal com sobrevivência de um agente inteligente. Sua arquitetura modular permite futuras extensões, como inteligência artificial mais avançada para o animal, novas condições climáticas e variações no terreno.

Este trabalho demonstra não apenas conhecimento técnico em C++, mas também pensamento lógico, organização de software e antecipação de cenários críticos no desenvolvimento de simulações dinâmicas

<h2>Diagrama UML</h2>
<img src="https://cdn.discordapp.com/attachments/426138366703173643/1365874543037648997/Trabalho_1-_AEDS_1.png?ex=680ee54b&is=680d93cb&hm=aaad0b32bc256cd0e4b6a37e074057c13585a82aadcb1f86ff8a6440022c4f08&" alt="diagram_uml" width = "500px">


# COMPILAÇÃO E EXECUÇÃO
</hr>
A algorítmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`              	 | Compila o código-fonte conforme as regras definidas no Makefile | 
|  `make run`            | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build, além de em seguida executar o programa da pasta build após a realização da compilação |

# AUTOR
Criado por Otávio Hiratsuka Camilo;

Aluno do curso de Engenharia da Computação no [CEFET-MG](https://www.cefetmg.br)
<div> 
  <a href = "mailto:otaviohiratsukac@gmail.com"><img src="https://img.shields.io/badge/-Gmail-%23333?style=for-the-badge&logo=gmail&logoColor=white" target="_blank"></a>
  <a href="https://www.linkedin.com/in/ot%C3%A1vio-hiratsuka-camilo-045563287/" target="_blank"><img src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>  
</div>

