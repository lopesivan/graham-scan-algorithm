/*  
 * file : main.c 
 * 
 * 
 * Entrada: arquivo de texto (.txt) contendo os pontos do plano 2D a serem analizados
 * Saída: conjunto de pontos que formam um fecho convexo
 *  
 * Plataforma Alvo : Raspberry PI 3
 * Compilador : GCC
 * Editor de texto :  VSCode
 * 
 * O presente algoritmo foi implementado para solucionar o problema do fecho convexo
 * como trabalho na cadeira de Sistemas embarcados do CURSO DE ENGENHARIA DE COMPUTAÇÃO 
 * DO IFCE CAMPUS FORTALEZA sob a orientação do PROFESSOR ELIAS TEODORO.  * 
 * 
 * Authors : Jessica Lewinter e Thalys Viana
 * 
 * Copyright (C) 2018 Jessica Lewinter <jessicalewinter@gmail.com>
 * Copyright (C) 2018 Thalys Viana  <thalysvianaguiar@gmail.com> * 
 * Data de Atualização : 01 de outubro de 2018
 *  * 
 * Modo de uso:  
 * 
 * O programa recebe como entrada na linha de comando o caminho de um arquivo de
 * texto do tipo .txt contendo as entradas a serem analizadas. As entradas devem
 * ser pares de números inteiros representando as cordenadas x e y de um ponto no plano 2D.
 * 
 * o arquivo .txt deve seguir o seguinte formato:
 * <total-pontos-a-serem-lidos> <ponto x1> <ponto y1> ... <ponto xn> <pontoyn>
 * 
 * Os valores lidos do arquivo (pontos) serão utilizados para calcular, se possível, o menor polígono
 * convexo que abranja todos esses pontos. Junto aos arquivos que formam o programa há também uma pasta
 * chamada /inputs com alguns arquivos de texto com entradas já testadas
 * 
 * Um exemplo de execução do programa seria:
 * <executável> <caminho-do-arquivo-com-entradas>               
 * 
 * This file or program is a free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public
 * License version 3 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License version 3 for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License version 3 along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "error.h"
#include "graham_scan.h"

/* Função: Mostra o ouput das entradas pre-definidas
 * 
 * Entrada : argc -> numero de argumentos apontados por argv 
 *           argv -> vetor de argumentos
 * Retorno : 0
 * Saída   : Exibe os pontos que formam o fecho convexo. Caso não existam, exibe uma mensagem
 *           informando que não é possível formar um fecho com os pontos passados
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

int main(int argc, char *argv[])
{   
    if (argc != 2) {
        invalidInputError();
    } else {
        startGrahamScan(argv[1]);
    }
    return 0;
}