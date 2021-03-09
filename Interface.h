#ifndef INTERFACE_H
#define INTERFACE_H

#include "habitantes.h"
#include "vacinas.h"

/**
 * Menu de cadastro de habitantes
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuHabitantes(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de inserção manual de habitantes a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: insere elemento na lista de habitantes
 */
void MenuInserirHabitanteManual(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de inserção por arquivo de habitantes a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elementos de arquivo são inseridos à lista de habitantes
 */
void MenuInserirHabitanteArquivo(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de consulta por cpf na lista de habitantes
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuConsultarHabitante(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);


/**
 * Menu de remoção de habitantes da lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento removido da lista de habitantes
 */
void MenuRemoverHabitante(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de chamada das funções de gerenciamento do cadastro de vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuVacina(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de insercao de vacina a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento inserido a lista de vacinas
 */
void MenuCadastrarVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de alteraçao de estoque da vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: estoque de elemento da lista de vacinas é alterado
 */
void MenuInserirEstoque(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de remoção de vacina da lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento da lista de vacinas é removido
 */
void MenuRemoverVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de chamada das funções de gerenciamento da vacinação
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuVacinacao(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de liberação de grupo prioritário
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: grupo prioritário é liberado
 */
void MenuLiberarPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de registro de vacinação
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: grupo prioritario do elemento liberado
 * Pos-Condição: vacininação do elemento é registrada
 */
void MenuRegistrarVacinacao (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de relatorios
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorio (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama função de impressão do relatorio de estoque da vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioEstoque (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama função de impressão do relatorio de vacinados com a primeira dose
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioPrimeiraDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama função de impressão do relatorio de vacinados com a segunda dose
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioSegundaDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama função de impressão do relatorio de não vacinados
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioNaoVacinados (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama função de impressão do relatorio de habitantes por grupo prioritario
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de principal que faz a chamada dos submenus
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuPrincipal(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);


#endif //INTERFACE_H
