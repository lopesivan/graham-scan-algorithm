#include "error.h"
#include <stdio.h>

/* Função: Exibe uma mensagem caso o arquivo a ser lido não exista
 * Entrada : Nenhuma 
 * Retorno : Nada
 * Saída   : "Erro ao tentar ler arquivo!

              Arquivo com o nome incorreto ou nao existente.
              
            "
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

void nonExistentFileError() {
    printf("Erro ao tentar ler arquivo!\n\n"
        "Arquivo com o nome incorreto ou nao existente.\n");
}

/* Função: Exibe uma mensagem caso a entrada esteja errada
 * Entrada : Nenhuma 
 * Retorno : Nada
 * Saída   : "Entrada invalida!"
 
              A entrada deve conter apenas o nome do arquivo a ser lido.
              Os arquivos a serem lidos se encontram na pasta /inputs
              
            "
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

void invalidInputError() {
    printf("Entrada invalida!\n\n"
        "A entrada deve conter apenas o nome do arquivo a ser lido.\n"
        "Os arquivos a serem lidos se encontram na pasta /inputs\n");
}