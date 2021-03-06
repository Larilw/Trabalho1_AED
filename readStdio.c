#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readStdio.h"
#include "constantes.h"
#include "habitantes.h"
#include "vacinas.h"
#include "Interface.h"

/**
 * Faz a leitura de um inteiro
 * retorno número inteiro
 *
 */
int LerInteiro ()
{
    char *final, buffer[TAM_MAX_STR];
    int inteiro;


    while (fgets(buffer, sizeof(buffer), stdin)) {
        inteiro = strtol(buffer, &final, 10);
        if (final == buffer || *final != '\n') {
            printf("----------------------------------------------------------------------\n");
            printf("Entre com um numero inteiro.\n");
            printf("----------------------------------------------------------------------\n");
        }
        else break;
    }
    return inteiro;
}

/**
 * Faz a leitura de de inteiros entre um intervalo
 * entrada dois extremos do intervalo
 * returno Retorna um inteiro caso esteja dentro do intervalo
 */

int LerIntervaloInteiro (int numA, int numB)
{
    int firstNum = (numA > numB)? numB: numA;
    int lastNum = (numA > numB)? numA: numB;
    int inteiro = LerInteiro ();

    while (inteiro < firstNum || inteiro > lastNum) {
        printf ("----------------------------------------------------------------------\n");
        printf ("Entre com um numero inteiro entre %d e %d\n", firstNum, lastNum);
        printf ("----------------------------------------------------------------------\n");
        inteiro = LerInteiro ();
    }
    return inteiro;
}

int LerString (char * str, int obrigatorio)
{
    int flag = 0;

    fgets (str, TAM_MAX_STR, stdin);
    if ((strlen(str)-1) == 0 && obrigatorio == 1) {
        while ((strlen(str)-1) == 0) {
            printf("----------------------------------------------------------------------\n");
            printf("Dado Invalido.\n");
            printf("----------------------------------------------------------------------\n");
            fgets (str, TAM_MAX_STR, stdin);
        }
    }
    str[strcspn(str, "\n")] = 0;

    return flag = 1;
}

char LerChar ()
{
    char final, buffer;
    char inteiro;

    scanf("%c", &buffer);
    return buffer;
}

DadosHabitante * LerHabitante (DadosHabitante *dados)
{
    char string[TAM_MAX_STR] = "";
    PrintMessage("Entre com o CPF.", 'd', 1, 1);
    LerString(string, 1);
    strcpy(dados->cpf, string);
    strcpy(dados->data_vacinacao, "");
    strcpy(dados->tipo_vacina, "");
    PrintMessage("Entre com o Telefone.", 'd', 1, 1);
    LerString(string, 0);
    strcpy(dados->telefone, string);
    PrintMessage("Entre com o endereco.", 'd', 1, 1);
    LerString(string, 0);
    strcpy(dados->endereco, string);
    PrintMessage("Entre com o RG.", 'd', 1, 1);
    LerString(string, 1);
    strcpy(dados->rg, string);
    PrintMessage("Entre com o nome.", 'd', 1, 1);
    LerString(string, 1);
    strcpy(dados->nome, string);
    PrintMessage("Entre com a profissao.", 'd', 1, 1);
    LerString(string, 0);
    strcpy(dados->profissao, string);
    PrintMessage("Entre com a genero.", 'd', 1, 1);
    dados->sexo = LerChar();
    PrintMessage("Entre com a idade.", 'd', 1, 1);
    dados->idade = LerInteiro();
    PrintMessage("Entre com a prioridade.", 'd', 1, 1);
    dados->prioridade = LerInteiro();
    dados->dose = 0;

    return dados;
}

DadosVacina * LerVacina (DadosVacina *dados)
{
    char string[TAM_MAX_STR] = "";

    PrintMessage("Entre com o nome da vacina.", 'd', 1, 1);
    LerString(string, 1);
    strcpy(dados->tipo, string);

    PrintMessage("Entre com a quantidade da vacina.", 'd', 1, 1);
    dados->estoque = LerInteiro();

    return dados;
}

DadosVacina * LerVacinaEstoque (DadosVacina *dados)
{
    PrintMessage("Entre com a quantidade da vacina que deseja inserir.", 'd', 1, 1);
    dados->estoque = LerInteiro();

    return dados;
}

