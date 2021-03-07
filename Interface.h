#ifndef INTERFACE_H
#define INTERFACE_H

#include "habitantes.h"
#include "vacinas.h"

void MenuHabitantes(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuInserirHabitanteManual(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuConsultarHabitante(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuInserirHabitanteArquivo(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRemoverHabitante(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuVacina(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuCadastrarVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuInserirEstoque(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRemoverVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuVacinacao(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuLiberarPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRegistrarVacinacao (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRelatorio (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRelatorioEstoque (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRelatorioPrimeiraDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRelatorioSegundaDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRelatorioNaoVacinados (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuRelatorioPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void MenuPrincipal(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario);

void PrintMessage(char *str, char alinhamento, int barraTopo, int barraBase);

#endif //INTERFACE_H
