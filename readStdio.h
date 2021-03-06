#ifndef TRABALHO_1_READSTDIO_H
#define TRABALHO_1_READSTDIO_H

#include "readStdio.h"
#include "constantes.h"
#include "habitantes.h"
#include "vacinas.h"

int LerInteiro ();

int LerIntervaloInteiro (int numA, int numB);

int LerString (char * str, int obrigatorio);

char LerChar ();

DadosHabitante * LerHabitante (DadosHabitante *dados);

DadosVacina * LerVacina (DadosVacina *dados);

DadosVacina * LerVacinaEstoque (DadosVacina *dados);

#endif //TRABALHO_1_READSTDIO_H
