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