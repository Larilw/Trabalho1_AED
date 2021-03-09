#ifndef INTERFACE_H
#define INTERFACE_H

#include "habitantes.h"
#include "vacinas.h"

/**
 * Menu de cadastro de habitantes
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuHabitantes(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de inser��o manual de habitantes a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: insere elemento na lista de habitantes
 */
void MenuInserirHabitanteManual(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de inser��o por arquivo de habitantes a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: elementos de arquivo s�o inseridos � lista de habitantes
 */
void MenuInserirHabitanteArquivo(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de consulta por cpf na lista de habitantes
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuConsultarHabitante(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);


/**
 * Menu de remo��o de habitantes da lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: elemento removido da lista de habitantes
 */
void MenuRemoverHabitante(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de chamada das fun��es de gerenciamento do cadastro de vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuVacina(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de insercao de vacina a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: elemento inserido a lista de vacinas
 */
void MenuCadastrarVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de altera�ao de estoque da vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: estoque de elemento da lista de vacinas � alterado
 */
void MenuInserirEstoque(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de remo��o de vacina da lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: elemento da lista de vacinas � removido
 */
void MenuRemoverVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de chamada das fun��es de gerenciamento da vacina��o
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuVacinacao(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de libera��o de grupo priorit�rio
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: grupo priorit�rio � liberado
 */
void MenuLiberarPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de registro de vacina��o
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: grupo prioritario do elemento liberado
 * Pos-Condi��o: vacinina��o do elemento � registrada
 */
void MenuRegistrarVacinacao (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de relatorios
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuRelatorio (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama fun��o de impress�o do relatorio de estoque da vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuRelatorioEstoque (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama fun��o de impress�o do relatorio de vacinados com a primeira dose
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuRelatorioPrimeiraDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama fun��o de impress�o do relatorio de vacinados com a segunda dose
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuRelatorioSegundaDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama fun��o de impress�o do relatorio de n�o vacinados
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuRelatorioNaoVacinados (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu que chama fun��o de impress�o do relatorio de habitantes por grupo prioritario
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuRelatorioPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

/**
 * Menu de principal que faz a chamada dos submenus
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pr�-condi��o: nenhuma
 * Pos-Condi��o: nenhuma
 */
void MenuPrincipal(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);


#endif //INTERFACE_H
