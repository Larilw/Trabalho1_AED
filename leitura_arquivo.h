#ifndef LEITURA_ARQUIVO_H
#define LEITURA_ARQUIVO_H
#include <stdio.h>
#include "habitantes.h"

/**
 * Remove um espaço vazio do início de uma string
 * Entrada: string com espaço e string sem espaco
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: o espaço no início da string é removido
 */
void removerEspacos(char stringComEspaco[TAM_MAX_STR+9], char stringSemEspaco[TAM_MAX_STR]);

/**
 * Insere um espaço no início de uma string e após cada ; presente na mesma
 * Entrada: duas strings, uma recebida com espaços e uma a ser preenchida com os espaços faltantes
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: são adicionados espaços na string recebida
 */
void inserirEspacos(char linhaLida[TAM_MAX_STR], char linhaNova[TAM_MAX_STR+9]);

/**
 * Separa uma string com os dados de um habitante e insere os mesmos nos campos de uma estrutura de habitante
 * Entrada: string com os dados do habitante
 * Retorno: dados do habitante
 * Pré-condição: nenhuma
 * Pós-condição: os dados são separados por tipo e inseridos na estrutura de habitante
 */
DadosHabitante separarDados(char *dados);

/**
 * Realiza a leitura de um arquivo texto linha por linha e insere na lista os habitantes presentes no arquivo 
 * Entrada: lista e caminho do arquivo
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: o arquivo é lido e os dados presentes nele são inseridos na lista  
 */
ListaHabitantes* lerArquivo(ListaHabitantes *l, char *caminhoArquivo);

#endif