#ifndef VACINAS_H
#define VACINAS_H
#include "constantes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// estrutura de dados das vacinas
typedef struct{
    char tipo[TAM_MAX_STR];
    int estoque;
} DadosVacina;

// estrutura de nó para lista encadeada de vacinas
typedef struct NoVacina{
    DadosVacina dados;
    struct NoVacina *pprox;
} ListaVacinas;

/**
 * Insere uma vacina na cabeca da lista
 * Entrada: lista e dados da vacina a ser inserida
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: a vacina é inserida na lista
 */
ListaVacinas* inserirVacina(ListaVacinas *l, DadosVacina dadosVac);

/**
 * Limpa a lista de vacinas uma a uma
 * Entrada: lista
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: os elementos da lista são todos removidos
 */
void limparListaVacinas(ListaVacinas *l);

/**
 * Consulta uma vacina da lista
 * Entrada: tipo da vacina a ser consultada e lista
 * Retorno: dados da vacina se ela for encontrada ou NULL caso contrário
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
DadosVacina* consultarVacina(ListaVacinas *l, char* tipoVacina);

/**
 * Altera os dados de uma vacina na lista
 * Entrada: tipo da vacina, lista e dados novos a serem inseridos na vacina
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: a vacina é alterada
 */
ListaVacinas* alterarVacina(ListaVacinas *l, DadosVacina *vac, char *tipoVac);

/**
 * Remove uma vacina da lista de vacinas
 * Entrada: tipo da vacina a ser removida e lista
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: elemento é removido da lista de vacinas
 */
ListaVacinas* removerVacina(char *tipoVac, ListaVacinas* l);

#endif