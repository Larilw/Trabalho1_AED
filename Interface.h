#ifndef INTERFACE_H
#define INTERFACE_H

#include "habitantes.h"
#include "vacinas.h"

void MenuHabitantes (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina);

void MenuInserirHabitanteManual (ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina);

void MenuConsultarHabitante (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina);

void MenuInserirHabitanteArquivo (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina);

void MenuRemoverHabitante (ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina);

void MenuVacina (ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina);

void MenuCadastrarVacina (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina);

void MenuInserirEstoque (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina);

void MenuRemoverVacina (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina);

void MenuVacinacao (ListaVacinas *listaVacina);

void MenuRelatorio ();

void MenuPrincipal (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina);

void PrintMessage (char* str);

#endif //INTERFACE_H
