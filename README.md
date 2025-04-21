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
<li>0️⃣ -> Área Vazia (não queima) </li>
<li>1️⃣ -> Árvore Saudável </li>
<li>2️⃣ -> Árvore em Chamas </li>
<li>3️⃣ -> Árvore Queimada </li>
<li>4️⃣ -> Água</li>
</ul>

<p><b>1. Como o fogo se espalha?</b></br>
O fogo começa em um ponto específico do mapa (informado no arquivo <code>input.dat</code>). A cada rodada (ou iteração), ele se espelaha para os lados: </br>
Para cima ⬆, para baixo ⬇, para esquerda ⬅ e para a direta ➡. </br>
<b>📌Importante:</b> O fogo não se espalha na diagonal.
</p>

<p><b>2. Quem pode pegar fogo?</b></br>
Só as árvores saudáveis (1️⃣) podem pegar fogo. Se uma árvore está do lado de uma árvore em chamas(2️⃣), ela vai pegar na proxima iteração.
</p>

<p><b>3. O que acontece com uma árvore em chamas?</b></br>
Assim que uma árvore pega fogo, ela queima por uma rodada. Na rodada seguinte, ela vira uma árvore queimada(3️⃣) e não pega fogo novamente.
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

# LÓGICA
</hr>

# COMPILAÇÃO E EXECUÇÃO
</hr>
A algorítmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make run`            | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build, além de em seguida executar o programa da pasta build após a realização da compilação | 
|  `make`                | 



# BIBLIOTECAS
</hr>
<h3>Bibliotecas utilizadas no projeto 📚</h3>
<ul>
  <li><code>#include 'iostream' </code></li>
  <li><code>#include 'algorithm' </code></li>
  <li><code>#include 'vector' </code></li>
  <li><code>#include 'utility' </code></li>
  <li><code>#include 'frstream' </code></li>
  <li><code>#include 'string' </code></li>
</ul>

# ESTRUTURA DO PROJETO
</hr>
<h3>Estrutura de Pastas 🗃️</h3>

```bash
📁 projeto/               
├── 📂 src/              
│   ├── Animal.hpp
│   ├── Animal.cpp
│   ├── config.hpp          # HEADERS
│   ├── Floresta.hpp
│   ├── Floresta.cpp
│   ├── main.cpp            # Codigo-Fonte
│   ├── input.dat           # Arquivo de entrada 
│   ├── output.dat          # Arquivo de saída 
│   └── simulador.exe       # Executável 
├── README.md             # Documentação
└── Makefile
```

# AUTOR
Criado por Otávio Hiratsuka Camilo;

Aluno do curso de Engenharia da Computação no [CEFET-MG](https://www.cefetmg.br)
