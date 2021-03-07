
#ifndef CONTROLEVACINAS_H
#define CONTROLEVACINAS_H
#include "constantes.h"
#include "habitantes.h"
#include "vacinas.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/**
 * Imprime os grupos prioritarios liberados para vacinacao
 * Entrada: nenhuma
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: imprime na tela os grupos prioritarios ja liberados para vacinacao
 */
void imprimeGruposPrioritarios();

/**
 * Valida os grupos prioritarios e adiciona um grupo
 * Entrada: um ponteiro de inteiro contendo um valor
 * Retorno: inteiro, 1 - grupo adicionado, 2 - ocorreu um erro de validacao, 0 - grupos completos
 * Pré-condição: variavel contendo um valor
 * Pós-condição: grupo validado adicionado ou mensagem com um erro
 */
int validaGrupoPrioritario(int *grupo);

/**
 * Libera grupos prioritarios
 * Entrada:nenhuma
 * Retorno: inteiro, 0 - para encerrar a liberacao dos grupos (quando todos os grupos foram adicionados), 1 - continuar liberando grupos
 * Pré-condição: nenhuma
 * Pós-condição: grupo liberado para vacinacao
 */
int liberaGrupoPrioritario();

/**
 * Verifica se o habitente existe no registro
 * Entrada: lista, dados do habitante e cpf do habitante
 * Retorno: inteiro, 0 - se o habitante nao existe no reistro, 1 - se o habitante existe no registro
 * Pré-condição: numero do cpf, lista e dados preenchidos
 * Pós-condição: se o habitante foi encontrado ou nao
 */
int verificaHabitanteRegistrado(ListaHabitantes *lista, DadosHabitante *dadosH, char *cpf);


/**
 * Verifica se o grupo prioritario do habitante
 * Entrada: dados do habitante
 * Retorno: inteiro, 0 - se o habitante nao esta no grupo prioritario, 1 - se o habitante esta no grupo prioritario
 * Pré-condição: dados do habitante preenchidos
 * Pós-condição: se o habitante esta no grupo prioritario para a vacinacao
 */
int verificaGrupoPrioritarioH(DadosHabitante *dadosH);

/**
 * Verifica se o habitante ja foi vacinado
 * Entrada: dados do habitante
 * Retorno: inteiro, 0 - se o habitante ja tomou as 2 doses, 1 - se o habitante pode tomar vacina
 * Pré-condição: dados do habitante preenchidos
 * Pós-condição: se o habitante pode ou nao tomar vacina
 */
int verificaVacinaConcluida(DadosHabitante *dados);

/**
 * Verifica se existe vacina disponivel no estoque
 * Entrada: lista de vacinas
 * Retorno: dados da vacina disponivel NULL se nao a vacina disponivel
 * Pré-condição: nenhuma
 * Pós-condição: vacina disponivel para ser aplicada
 */
DadosVacina* verificaEstoqueVacina(ListaVacinas *lista);

/**
 * Imprime estoque de vacinas
 * Entrada: lista de vacinas
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: imprime a lista de dados das vacinas presentes no estoque
 */
void imprimeVacinas(ListaVacinas *lista);

/**
 * Registra a vacinacao do habitante
 * Entrada: lista de vacinas, dados da vacina e habitante, e o cpf do habitante
 * Retorno: nenhum
 * Pré-condição: numero do cpf, listas preenchidas
 * Pós-condição: registra que o habitate foi vacinado
 */
void registrarVacinacao(char *cpf, ListaVacinas *listaV,DadosVacina *dadosVac, DadosHabitante *dadosH);


//void inicializaDadosStructH(DadosHabitante dados);


#endif // CONTROLEVACINAS_H
