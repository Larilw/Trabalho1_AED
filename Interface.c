#include <stdio.h>
#include "Interface.h"
#include "habitantes.h"
#include "readStdio.h"
#include "leitura_arquivo.h"

/*
 * Variaveis de controle do menu
 */
#define CANCELAR 0
#define CONFIMAR 1

// Menu Principal
#define MMENU_HABITANTE 1
#define MMENU_VACINA    2
#define MMENU_VACINACAO 3
#define MMENU_RELATORIO 4

// Menu de cadastro do habitante
#define MHABITANTE_INSERIRMANUAL    1
#define MHABITANTE_INSERIRARQUIVO   2
#define MHABITANTE_CONSULTAR        3
#define MHABITANTE_REMOVER          4

// Menu de cadastro de vacina
#define MVACINA_CADASTRARVACINA 1
#define MVACINA_INSERIRESTOQUE  2
#define MVACINA_REMOVER         3

// Menu de vacinação
#define MVACINACAO_LIBERARGRUPO 1
#define MVACINACAO_REGISTRO     2

// Menu de relatorios
#define MRELATORIO_ESTOQUE      1
#define MRELATORIO_PRIMEIRADOSE 2
#define MRELATORIO_SEGUNDADOSE  3
#define MRELATORIO_NAOVACINADOS 4
#define MRELATORIO_PRIORITARIO  5


/**
 * Menu principal do programa
 * Entrada: lista de habitantes e vacinas
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuPrincipal(ListaHabitantes *l) {
    int seletor;

    /*
    printf("--------------------------------------------------------------------------------\n");
    printf("                              Menu Principal\n");
    printf("--------------------------------------------------------------------------------\n\n");
    */
    PrintMessage("                              Menu Principal");
    printf("Entre com o numero da operacao desejada\n\n");
    printf("%d - Cadastro de habitantes\n", MMENU_HABITANTE);
    printf("%d - Cadastro de Vacinas\n", MMENU_VACINA);
    printf("%d - Registro de vacinacao\n", MMENU_VACINACAO);
    printf("%d - Relatorios\n", MMENU_RELATORIO);
    printf("%d - Encerrar programa\n", CANCELAR);

    seletor = LerInteiro();

    switch (seletor) {
        case MMENU_HABITANTE:
            MenuHabitantes(l);
        case MMENU_VACINA:
            MenuVacina(l);
        case MMENU_VACINACAO:
            MenuVacinacao(l);
        case MMENU_RELATORIO:
            MenuRelatorio(l);
        case CANCELAR:
            MenuPrincipal(l);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuPrincipal(l);
    }
}

/**
 * Menu de cadastro de habitantes
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuHabitantes (ListaHabitantes *l)
{
    int seletor;

    printf("--------------------------------------------------------------------------------\n");
    printf("                           Cadastro de Habitantes\n");
    printf("--------------------------------------------------------------------------------\n\n");
    printf("Entre com o numero da operacao desejada\n\n");
    printf("%d - Cadastrar habitante manualmente\n", MHABITANTE_INSERIRMANUAL);
    printf("%d - Cadastrar habitante por arquivo\n", MHABITANTE_INSERIRARQUIVO);
    printf("%d - Consultar habitante\n", MHABITANTE_CONSULTAR);
    printf("%d - Remover habitante\n", MHABITANTE_REMOVER);
    printf("%d - Voltar\n", CANCELAR);

    seletor = LerInteiro();

    switch (seletor) {
        case MHABITANTE_INSERIRMANUAL:
            MenuInserirHabitanteManual(l);
        case MHABITANTE_INSERIRARQUIVO:
            MenuInserirHabitanteArquivo(l);
        case MHABITANTE_CONSULTAR:
            MenuConsultarHabitante(l);
        case MHABITANTE_REMOVER:
            MenuRemoverHabitante(l);
        case CANCELAR:
            MenuPrincipal(l);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(l);
    }
}

/**
 * Menu de inserção manual de habitantes a lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: insere elemento na lista de habitantes
 */
void MenuInserirHabitanteManual (ListaHabitantes *l)
{
    DadosHabitante dados;

    LerHabitante(&dados);
    if (l == NULL || (consultarHabitante(dados.cpf, l) == NULL)) {
        l = inserirHabitante(l, dados);
        PrintMessage("Cadastrado.");
    }
    else {
        PrintMessage("CPF ja cadastrado.");
    }

    PrintMessage("Deseja cadastrar outro habitante?\n"
                     "0 - Nao\n"
                     "1 - Sim");
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirHabitanteManual(l);
        case CANCELAR:
            MenuHabitantes(l);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(l);
    }
}

/**
 * Menu de inserção por arquivo de habitantes a lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elementos de arquivo são inseridos à lista de habitantes
 */
void MenuInserirHabitanteArquivo (ListaHabitantes *l)
{
    char arquivo [TAM_MAX_STR];

    PrintMessage("Entre com o caminho do arquivo.");
    LerString(arquivo, 1);

    l = lerArquivo(l, arquivo);

    PrintMessage("Deseja cadastrar outra lista de habitantes?\n"
                    "0 - Nao\n"
                    "1 - Sim");
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirHabitanteArquivo(l);
        case CANCELAR:
            MenuHabitantes(l);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(l);
    }
}

/**
 * Menu de consulta por cpf na lista de habitantes
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuConsultarHabitante (ListaHabitantes *l)
{
    DadosHabitante *aux;
    char cpf[TAM_MAX_STR];

    PrintMessage("Entre com o cpf que deseja consultar");
    LerString(cpf, 1);

    aux = consultarHabitante(cpf, l);
    if (l != NULL && aux != NULL) {
        PrintMessage("Habitante:");
        printf("CPF: %s\n", aux->cpf);
    }
    else {
        PrintMessage("CPF nao encontrado");
    }

    PrintMessage("Deseja consultar outro habitante?\n"
                     "0 - Nao\n"
                     "1 - Sim");
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuConsultarHabitante(l);
        case CANCELAR:
            MenuHabitantes(l);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(l);
    }
}

/**
 * Menu de remoção de habitantes da lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento removido da lista de habitantes
 */
void MenuRemoverHabitante (ListaHabitantes *l)
{
    DadosHabitante *aux;
    char cpf[TAM_MAX_STR];

    PrintMessage("Entre com o cpf que deseja remover");
    LerString(cpf, 1);

    aux = consultarHabitante(cpf, l);
    if (l != NULL && aux != NULL) {
        PrintMessage("Habitante:");
        printf("CPF: %s\n", aux->cpf);

        PrintMessage("Confirme a remocao do habitante.\n"
                         "0 - Nao\n"
                         "1 - Sim");
        int confirmacao = LerIntervaloInteiro(0, 1);
        if (confirmacao == 1) {
            removerHabitante(aux->cpf, l);
            PrintMessage("habitante removido.");
        }
    }
    else {
        PrintMessage("CPF nao encontrado");
    }

    PrintMessage("Deseja remover outro habitante?\n"
                     "0 - Nao\n"
                     "1 - Sim");
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuRemoverHabitante(l);
        case CANCELAR:
            MenuHabitantes(l);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(l);
    }
}

void MenuVacina ()
{
    int seletor;

    printf("--------------------------------------------------------------------------------\n");
    printf("                           Cadastro de Vacinas\n");
    printf("--------------------------------------------------------------------------------\n\n");
    printf("Entre com o numero da operacao desejada\n\n");
    printf("%d - Cadastrar nova vacina\n", MVACINA_CADASTRARVACINA);
    printf("%d - Inserir lote de vacinas\n", MVACINA_INSERIRESTOQUE);
    printf("%d - Remover vacina\n", MVACINA_REMOVER);
    printf("%d - Voltar\n", CANCELAR);

    seletor = LerInteiro();


    switch (seletor) {
        case MVACINA_CADASTRARVACINA:
            break;
        case MVACINA_INSERIRESTOQUE:
            break;
        case MVACINA_REMOVER:
            break;
        case CANCELAR:
            MenuPrincipal(NULL);
            break;
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacina();
    }
}

void MenuVacinacao ()
{
    int seletor;

    printf("--------------------------------------------------------------------------------\n");
    printf("                          Registro de Vacinacao\n");
    printf("--------------------------------------------------------------------------------\n\n");
    printf("Entre com o numero da operacao desejada\n\n");
    printf("%d - Liberacao de grupo prioritario\n", MVACINACAO_LIBERARGRUPO);
    printf("%d - Registrar vacinacao\n", MVACINACAO_REGISTRO);
    printf("%d - Voltar\n", CANCELAR);

    seletor = LerInteiro();

    switch (seletor) {
        case MVACINACAO_LIBERARGRUPO:
            break;
        case MVACINACAO_REGISTRO:
            break;
        case MHABITANTE_REMOVER:
            break;
        case CANCELAR:
            MenuPrincipal(NULL);
            break;
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacinacao();
    }
}

void MenuRelatorio ()
{
    int seletor;

    printf("--------------------------------------------------------------------------------\n");
    printf("                                Relatorios\n");
    printf("--------------------------------------------------------------------------------\n\n");
    printf("Entre com o numero da operacao desejada\n\n");
    printf("%d - Numero de doses no estoque por tipo de vacina\n", MRELATORIO_ESTOQUE);
    printf("%d - Lista de habitantes vacinados somente com a 1a dose\n", MRELATORIO_PRIMEIRADOSE);
    printf("%d - Numero de habitantes vacinados com a 2a dose\n", MRELATORIO_SEGUNDADOSE);
    printf("%d - Lista de habitantes nao vacinados agrupados pelo grupo prioritario\n", MRELATORIO_NAOVACINADOS);
    printf("%d - Numero de habitantes por grupo prioritario\n", MRELATORIO_PRIORITARIO);
    printf("%d - Voltar\n", CANCELAR);

    seletor = LerInteiro();

    switch (seletor) {
        case MRELATORIO_ESTOQUE:
            break;
        case MRELATORIO_PRIMEIRADOSE:
            break;
        case MRELATORIO_SEGUNDADOSE:
            break;
        case MRELATORIO_NAOVACINADOS:
            break;
        case MRELATORIO_PRIORITARIO:
            break;
        case CANCELAR:
            MenuPrincipal(NULL);
            break;
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuRelatorio();
    }
}

/**
 * Imprime mensagem formatada
 * Entrada: string contendo o texto da mensagem
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void PrintMessage (char* str)
{
    printf("--------------------------------------------------------------------------------\n");
    printf("%s\n", str);
    printf("--------------------------------------------------------------------------------\n");

}
