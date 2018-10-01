#include "error.h"
#include <stdio.h>

// Exibe uma mensagem caso o arquivo a ser lido não exista
void nonExistentFileError() {
    printf("Erro ao tentar ler arquivo!\n\n"
        "Arquivo com o nome incorreto ou nao existente.\n");
}

// Exibe uma mensagem caso a entrada esteja errada
void invalidInputError() {
    printf("Entrada invalida!\n\n"
        "A entrada deve conter apenas o nome do arquivo a ser lido.\n"
        "Os arquivos a serem lidos se encontram na pasta /inputs\n");
}