#ifndef INTERFACE_H
#define INTERFACE_H

#include "habitantes.h"

void MenuHabitantes (ListaHabitantes *l);

void MenuInserirHabitanteManual (ListaHabitantes *l);

void MenuConsultarHabitante (ListaHabitantes *l);

void MenuInserirHabitanteArquivo (ListaHabitantes *l);

void MenuRemoverHabitante (ListaHabitantes *l);

void MenuVacina ();

void MenuVacinacao ();

void MenuRelatorio ();

void MenuPrincipal (ListaHabitantes *l);

void PrintMessage (char* str);

#endif //INTERFACE_H
