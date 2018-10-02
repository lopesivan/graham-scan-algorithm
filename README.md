# Graham Scan Algorithm
------------------------------

Autores: Jessica Lewinter e Thalys Viana

### Descrição do algoritmo
O algoritmo de Graham Scan é um algortimo de geometria computacional utilizado para computar um fecho convexo. Tal algoritmo recebe como entrada um conjunto de pontos em um plano 2D e computa o menor polígono convexo que contenha todos esses pontos.

Plataforma Alvo: Raspberry Pi 3

O presente algoritmo foi implementado para solucionar o problema do fecho convexo como trabalho na cadeira de Sistemas embarcados do curso de Engenharia de Computação do IFCE Campus Fortaleza

As seguintes fontes foram usadas como referência:

Convex Hull
<https://brilliant.org/wiki/convex-hull/>
Convex Hull Algorithms
<https://en.wikipedia.org/wiki/Convex_hull_algorithms>
Convex Hull | Set 2 (Graham Scan)
<https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/>

### Exemplo de funcionamento do algoritmo
![Alt Text](https://ds055uzetaobb.cloudfront.net/image_optimizer/ea21a7ce6180f91fa4724e4c8fc7ae1a3949e671.gif)

### Modo de uso
 O programa recebe como entrada na linha de comando o caminho de um arquivo de
 texto do tipo .txt contendo as entradas a serem analizadas. As entradas devem
 ser pares de números inteiros representando as cordenadas x e y de um ponto no plano 2D.
  
 o arquivo .txt deve seguir o seguinte formato:
 `<total-pontos-a-serem-lidos> <ponto x1> <ponto y1> ... <ponto nx> <ponto ny>`
 Os valores lidos do arquivo (pontos) serão utilizados para calcular, se possível, o menor polígono convexo que abranja todos esses pontos. Junto aos arquivos que formam o programa há também uma pastachamada `/inputs` com alguns arquivos de texto com entradas já testadas. 
 
 Um exemplo de execução do programa seria:
 `<executável> <caminho-do-arquivo-com-entradas>`

##### Obs:
O arquivo com as entradas deve conter n pares de pontos representando as coordenadas x e y no plano. Tais entradas devem estar separadas por espaços. E o primeiro parâmetro de entrada deve informa a quantidade de pontos a serem lidos.

##### Exemplo de entrada:
`4 1 1 2 2 3 3 1 3`

##### Saída:

`Output:
(1.00, 3.00)
(3.00, 3.00)
(1.00, 1.00)`

### Preparação para executar o programa
##### Passo 1:  Compilar os arquivos 
`gcc *.c -o <nome-do-executável>` 
##### Passo 2: Executar 
`<nome-do-executável> <caminho-com-arquivo-de-texto>`
##### Exemplo de como executar o programa:
`./main.out inputs/cg01.txt`