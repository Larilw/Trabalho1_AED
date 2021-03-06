#ifndef TRABALHO_1_READSTDIO_H
#define TRABALHO_1_READSTDIO_H

#include "readStdio.h"
#include "constantes.h"
#include "habitantes.h"

int LerInteiro ();

int LerIntervaloInteiro (int numA, int numB);

int LerString (char * str, int obrigatorio);

char LerChar ();

DadosHabitante * LerHabitante (DadosHabitante *dados);

#endif //TRABALHO_1_READSTDIO_H
