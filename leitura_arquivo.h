#ifndef LEITURA_ARQUIVO_H
#define LEITURA_ARQUIVO_H
#include <stdio.h>

/**
 * Realiza a leitura de um arquivo texto linha por linha e insere na lista os habitantes presentes no arquivo 
 * Entrada: lista e caminho do arquivo
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: o arquivo é lido e os dados presentes nele são inseridos na lista  
 */
ListaHabitantes* lerArquivo(ListaHabitantes *l, char *caminhoArquivo);

#endif