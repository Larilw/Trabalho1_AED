#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readStdio.h"
#include "constantes.h"
#include "habitantes.h"
#include "vacinas.h"
#include "Interface.h"
#include "controleVacinas.h"

/**
 * Faz a leitura de um inteiro
 * Entrada: nenhuma
 * Retorno: número inteiro
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
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
 * Faz a leitura de inteiros entre um intervalo
 * entrada dois extremos do intervalo
 * returno Retorna um inteiro caso esteja dentro do intervalo
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
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

/**
 * Faz a leitura de uma string
 * entrada string de destino e inteiro para demarcar obrigatoriedade de preenchimento
 * returno Retorna flag 1 caso string esteja vazia
 * Pré-condição: nenhuma
 * Pós-condição: str preenchida com entrada do teclado
 */
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
    if ((strlen(str)-1) == 0 && obrigatorio == 0) flag = 1;
    str[strcspn(str, "\n")] = 0;

    return flag;
}

void LimpaBuffer ()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Faz a leitura de um char
 * entrada nenhuma
 * returno caractere
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
char LerChar ()
{
    char buffer;

    scanf("%c", &buffer);
    LimpaBuffer();

    return buffer;
}

/**
 * Faz a leitura de dados do habitante
 * Entrada: struct de dados do habitante e lista de habitantes
 * returno struct de dados do habitante preenchida
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
DadosHabitante *LerHabitante(DadosHabitante *dados, ListaHabitantes *listaHabitante)
{
    char string[TAM_MAX_STR] = "";
    PrintMessage("Entre com o CPF.", 'e', 1, 1);
    LerString(string, 1);
    strcpy(dados->cpf, string);
    if (verificaHabitanteRegistrado(listaHabitante, dados, dados->cpf)) {
        return NULL;
    }

    strcpy(dados->data_vacinacao, "");
    strcpy(dados->tipo_vacina, "");
    PrintMessage("Entre com o Telefone.", 'e', 1, 1);
    LerString(string, 0);
    strcpy(dados->telefone, string);
    PrintMessage("Entre com o endereco.", 'e', 1, 1);
    LerString(string, 0);
    strcpy(dados->endereco, string);
    PrintMessage("Entre com o RG.", 'e', 1, 1);
    LerString(string, 1);
    strcpy(dados->rg, string);
    PrintMessage("Entre com o nome.", 'e', 1, 1);
    LerString(string, 1);
    strcpy(dados->nome, string);
    PrintMessage("Entre com a profissao.", 'e', 1, 1);
    LerString(string, 0);
    strcpy(dados->profissao, string);
    PrintMessage("Entre com a genero.", 'e', 1, 1);
    dados->sexo = LerChar();
    PrintMessage("Entre com a idade.", 'e', 1, 1);
    dados->idade = LerInteiro();
    PrintMessage("Entre com a prioridade.", 'e', 1, 1);
    dados->prioridade = LerIntervaloInteiro(1, 5);
    dados->dose = 0;

    return dados;
}

/**
 * Faz a leitura de dados de uma vacina
 * Entrada: struct de dados da vacinas
 * returno struct de dados da vacina preenchida
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
DadosVacina * LerVacina (DadosVacina *dados)
{
    char string[TAM_MAX_STR] = "";

    PrintMessage("Entre com o nome da vacina.", 'e', 1, 1);
    LerString(string, 1);
    strcpy(dados->tipo, string);

    PrintMessage("Entre com a quantidade da vacina.", 'e', 1, 1);
    dados->estoque = LerInteiro();

    return dados;
}

/**
 * Faz a leitura de estoque de uma vacina
 * Entrada: struct de dados da vacinas
 * returno: struct de dados da vacina com novo estoque
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
DadosVacina * LerVacinaEstoque (DadosVacina *dados)
{
    PrintMessage("Entre com a quantidade da vacina que deseja inserir.", 'e', 1, 1);
    dados->estoque = LerInteiro();

    return dados;
}

