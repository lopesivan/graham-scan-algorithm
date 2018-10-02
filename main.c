#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "error.h"
#include "graham_scan.h"

/*  
 * file : main.c 
 * 
 * 
 * Entradaa: arquivos na formatação definida no arquivo 'Imagens.h'
 * Saída: matriz com os dados equalizados da imagem de entrada e os histogramas
 * de intensidades,função de densidade,acumulado e equalizado para a referida 
 * imagem.
 *  
 * Plataforma Alvo : PIC18F4550 (Microchip)
 * Compilador : XC8 (Microchip)
 * IDE :  MPLABX (Microchip)
 * OBS:Taxa de Transmissão padrão :  9600 (podendo ser alterado na função MAIN).
 * 
 * O presente algoritmo foi implementado com referencia ao procedimento de 
 * equalização de histogramas e imagens apresentado no livro Processamento DigitAL
 * de Imagens dos Autores Gonzales e Woods como trabalho na cadeira de Sistemas 
 * embarcados do CURSO DE ENGENHARIA DE COMPUTAÇÃO DO IFCE CAMPUS FORTALEZA 
 * sob a orientação do PROFESSOR ELIAS TEODORO.   * 
 * 
 *  Authors : Andre Vieira e Luan Barroso
 * 
 *  Copyright (C) 2018 Andre Vieira <sgavsnake@gmail.com>
 *  Copyright (C) 2018 Luan Pontes  <pontesluanlx@gmail.com> * 
 *  Data de Atualização : 30 de maio de 2018
 *   * 
 *  Modo de uso:  os valores dos vetores existentes neste arquivo são
 *              utilizados para calcular os histogramas nos algoritmos da aplicação
 *              os valores definidos fazem referencia aos dados de uma imagem em formato .pgm
 *              doo tipo P2;
 *              O numero maximo de pixels de cada imagem testado para o armazenamento em 
 *              constantes para o presente trabalho foram de 4070 pixels,com dimensões de 
 *              55 por 74 pixels. 
 *              Este trabalho possui duas imagens locaizadas na pasta Imagens.h formatadas
 *              com formato definido no cabeçalho de cada imagem para inserir outras imagens
 *              basta seguir o padrão já definido.
 *              Para uso do algoritmo altere o valor do parametro da função 
 *              "selectEqualizeImagem(parametro)" para 1 ou 2 conforme imagem que deseja que sejam realizado
 *              os procedimentos do algoritmo ou valor que desejar caso tenha inserido alguma imagem.              
 *              Em um programa de terminal com interface serial os resultados serão impressos bastando
 *              transferi-los para um arquivo .txt e alterar o formato do arquivo para '.pgm'
 * 
 *              
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