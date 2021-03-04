#ifndef HABITANTES_H
#define HABITANTES_H
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura de dados dos habitantes
typedef struct{
    char nome[TAM_MAX_STR];
    int idade;
    char sexo;
    char rg[TAM_MAX_STR];
    char cpf[TAM_MAX_STR];
    char telefone[TAM_MAX_STR];
    char endereco[TAM_MAX_STR];
    char profissao[TAM_MAX_STR];
    int prioridade;
    char data_vacinacao[TAM_MAX_STR];
    char tipo_vacina[TAM_MAX_STR];
    int dose;
} DadosHabitante;

// estrutura de nó para lista encadeada de habitantes
typedef struct NoHabitante{
    DadosHabitante habitante;
    struct NoHabitante *pprox;
} ListaHabitantes;

/**
 * Insere um habitante na cabeca da lista de habitantes
 * Entrada: lista e dados do habitante a serem inseridos
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: elemento é inserido na lista de habitantes
 */
ListaHabitantes* inserirHabitante(ListaHabitantes* l, DadosHabitante dados);

/**
 * Remove um habitante da lista de habitantes
 * Entrada: cpf do habitante a ser removido e lista
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: elemento é removido da lista de habitantes
 */
ListaHabitantes* removerHabitante(char *cpf, ListaHabitantes* l);

/**
 * Consulta um habitante da lista
 * Entrada: cpf do habitante a ser consultado e lista
 * Retorno: dados do habitante se ele for encontrado ou NULL caso contrário
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
DadosHabitante* consultarHabitante(char *cpf, ListaHabitantes *l);

/**
 * Altera os dados de um habitante na lista
 * Entrada: cpf do habitante, lista e dados novos a serem inseridos no habitante
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: o habitante é alterado
 */
ListaHabitantes* alterarHabitante(char *cpf, ListaHabitantes *l, DadosHabitante habitante);

#endif