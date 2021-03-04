#ifndef VACINAS_H
#define VACINAS_H
#include "constantes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    char tipo[TAM_MAX_STR];
    int estoque;
} DadosVacina;

typedef struct NoVacina{
    DadosVacina dados;
    struct NoVacina *pprox;
} ListaVacinas;

ListaVacinas* inserirVacina(ListaVacinas *l, DadosVacina dadosVac);

void limparListaVacinas(ListaVacinas *l);

DadosVacina* consultarVacina(ListaVacinas *l, char* tipoVacina);

ListaVacinas* alterarVacina(ListaVacinas *l, DadosVacina *vac, char *tipoVac);

#endif