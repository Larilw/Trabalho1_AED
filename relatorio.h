#ifndef TRABALHO_1_RELATORIO_H
#define TRABALHO_1_RELATORIO_H

#include "habitantes.h"
#include "vacinas.h"

/**
 * Imprime relatorio com nome e estoque de vacinas
 * Entrada: struct da lista de vacinas
 * Retorno: nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void PrintRelatorioEstoque (ListaVacinas *listaVacina);

/**
 * Imprime relatorio com nome e cpf de habitantes vacinados com a primeira dose
 * Entrada: struct da lista de habitantes
 * Retorno: nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void PrintRelatorioPrimeiraDose (ListaHabitantes *listaHabitante);

/**
 * Imprime relatorio do numero de habitantes vacinados com a segunda dose
 * Entrada: struct da lista de habitantes e numero ultimo do grupo prioritario liberado
 * Retorno: nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void PrintRelatorioSegundaDose (ListaHabitantes *listaHabitante);

/**
 * Imprime relatorio de habitantes n�o vacinados por grupo prioritario
 * Entrada: struct da lista de habitantes
 * Retorno: nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void PrintRelatorioNaoVacinados (ListaHabitantes *listaHabitante, int *grupoPrioritario);

/**
 * Imprime relatorio de habitantes por grupo prioritario
 * Entrada: struct da lista de habitantes e numero ultimo do grupo prioritario liberado
 * Retorno: nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void PrintRelatorioPrioritario (ListaHabitantes *listaHabitante, int *grupoPrioritario);

/**
 * Imprime mensagem formatada
 * Entrada: string contendo o texto da mensagem e opcoes de formatacao
 * Retorno: nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void PrintMessage (char *str, char alinhamento, int barraTopo, int barraBase);

#endif //TRABALHO_1_RELATORIO_H
