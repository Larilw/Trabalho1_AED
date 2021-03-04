#ifndef HABITANTES_H
#define HABITANTES_H
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[TAM_MAX_STR];
    int idade;
    char sexo;
    char rg[TAM_MAX_STR];
    char cpf[TAM_MAX_STR];
    char telefone[TAM_MAX_STR];
    char endereco[TAM_MAX_STR];
    char profissao[TAM_MAX_STR];
    int prioridade;
    char data_vacinacao[TAM_MAX_STR];
    char tipo_vacina[TAM_MAX_STR];
    int dose;
} DadosHabitante;

typedef struct NoHabitante{
    DadosHabitante habitante;
    struct NoHabitante *pprox;
} ListaHabitantes;

ListaHabitantes* inserirHabitante(ListaHabitantes* l, DadosHabitante dados);

ListaHabitantes* removerHabitante(char *cpf, ListaHabitantes* l);

DadosHabitante* consultarHabitante(char *cpf, ListaHabitantes *l);

ListaHabitantes* alterarHabitante(char *cpf, ListaHabitantes *l, DadosHabitante habitante);

#endif