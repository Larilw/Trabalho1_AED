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
void MenuPrincipal(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina) {
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
            MenuHabitantes(listaHabitante, listaVacina);
        case MMENU_VACINA:
            MenuVacina(listaHabitante, listaVacina);
        case MMENU_VACINACAO:
            MenuVacinacao(listaVacina);
        case MMENU_RELATORIO:
            MenuRelatorio(listaHabitante);
        case CANCELAR:
            MenuPrincipal(listaHabitante, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuPrincipal(listaHabitante, listaVacina);
    }
}

/**
 * Menu de cadastro de habitantes
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuHabitantes(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina)
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
            MenuInserirHabitanteManual(listaHabitante, listaVacina);
        case MHABITANTE_INSERIRARQUIVO:
            MenuInserirHabitanteArquivo(listaHabitante, listaVacina);
        case MHABITANTE_CONSULTAR:
            MenuConsultarHabitante(listaHabitante, listaVacina);
        case MHABITANTE_REMOVER:
            MenuRemoverHabitante(listaHabitante, listaVacina);
        case CANCELAR:
            MenuPrincipal(listaHabitante, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitante, listaVacina);
    }
}

/**
 * Menu de inserção manual de habitantes a lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: insere elemento na lista de habitantes
 */
void MenuInserirHabitanteManual(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina)
{
    DadosHabitante dados;

    LerHabitante(&dados);
    if (listaHabitantes == NULL || (consultarHabitante(dados.cpf, listaHabitantes) == NULL)) {
        listaHabitantes = inserirHabitante(listaHabitantes, dados);
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
            MenuInserirHabitanteManual(listaHabitantes, listaVacina);
        case CANCELAR:
            MenuHabitantes(listaHabitantes, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitantes, listaVacina);
    }
}

/**
 * Menu de inserção por arquivo de habitantes a lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elementos de arquivo são inseridos à lista de habitantes
 */
void MenuInserirHabitanteArquivo(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina)
{
    char arquivo [TAM_MAX_STR];

    PrintMessage("Entre com o caminho do arquivo.");
    LerString(arquivo, 1);

    listaHabitante = lerArquivo(listaHabitante, arquivo);

    PrintMessage("Deseja cadastrar outra lista de habitantes?\n"
                    "0 - Nao\n"
                    "1 - Sim");
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirHabitanteArquivo(listaHabitante, listaVacina);
        case CANCELAR:
            MenuHabitantes(listaHabitante, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitante, listaVacina);
    }
}

/**
 * Menu de consulta por cpf na lista de habitantes
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuConsultarHabitante(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina)
{
    DadosHabitante *aux;
    char cpf[TAM_MAX_STR];

    PrintMessage("Entre com o cpf que deseja consultar");
    LerString(cpf, 1);

    aux = consultarHabitante(cpf, listaHabitante);
    if (listaHabitante != NULL && aux != NULL) {
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
            MenuConsultarHabitante(listaHabitante, listaVacina);
        case CANCELAR:
            MenuHabitantes(listaHabitante, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitante, listaVacina);
    }
}

/**
 * Menu de remoção de habitantes da lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento removido da lista de habitantes
 */
void MenuRemoverHabitante(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina)
{
    DadosHabitante *aux;
    char cpf[TAM_MAX_STR];

    PrintMessage("Entre com o cpf que deseja remover");
    LerString(cpf, 1);

    aux = consultarHabitante(cpf, listaHabitantes);
    if (listaHabitantes != NULL && aux != NULL) {
        PrintMessage("Habitante:");
        printf("CPF: %s\n", aux->cpf);

        PrintMessage("Confirme a remocao do habitante.\n"
                         "0 - Nao\n"
                         "1 - Sim");
        int confirmacao = LerIntervaloInteiro(0, 1);
        if (confirmacao == 1) {
            removerHabitante(aux->cpf, listaHabitantes);
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
            MenuRemoverHabitante(listaHabitantes, listaVacina);
        case CANCELAR:
            MenuHabitantes(listaHabitantes, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitantes, listaVacina);
    }
}

void MenuVacina(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina)
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
            MenuCadastrarVacina(listaHabitantes, listaVacina);
        case MVACINA_INSERIRESTOQUE:
            MenuInserirEstoque(listaHabitantes, listaVacina);
        case MVACINA_REMOVER:
            MenuRemoverVacina(listaHabitantes, listaVacina);
        case CANCELAR:
            MenuPrincipal(listaHabitantes, listaVacina);
            break;
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacina(listaHabitantes, listaVacina);
    }
}

void MenuCadastrarVacina (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina)
{
    DadosVacina dados;

    LerVacina(&dados);
    if (listaVacina == NULL || (consultarVacina(listaVacina, dados.tipo) == NULL)) {
        listaVacina = inserirVacina(listaVacina, dados);
        PrintMessage("Vacina cadastrada.");
    }
    else {
        PrintMessage("Vacina ja cadastrada.");
    }

    PrintMessage("Deseja cadastrar outra Vacina?\n"
                 "0 - Nao\n"
                 "1 - Sim");
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuCadastrarVacina(listaHabitante, listaVacina);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacina(listaHabitante, listaVacina);
    }
}

void MenuInserirEstoque (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina)
{
    DadosVacina dados;
    DadosVacina *aux;
    char vacina [TAM_MAX_STR];

    PrintMessage("Entre com o nome da vacina que deseja alterar o estoque");
    LerString(vacina, 1);
    aux = consultarVacina(listaVacina, vacina);
    if (listaVacina != NULL && aux != NULL) {
        PrintMessage("Alteracao de estoque");
        printf("Estoque da vacina %s: %d\n", aux->tipo, aux->estoque);
        dados = *aux;
        LerVacinaEstoque(&dados);
        dados.estoque += aux->estoque;
        if (dados.estoque >= 0) {
            listaVacina = alterarVacina(listaVacina, &dados, vacina);
            printf("Novo estoque da vacina %s: %d\n", aux->tipo, aux->estoque);
        }
        else {
            PrintMessage("Valor de estoque invalido");
        }
    }
    else {
        PrintMessage("Vacina nao encontrada.");
    }

    PrintMessage("Deseja altera o estoque de outra vacina?\n"
                 "0 - Nao\n"
                 "1 - Sim");
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirEstoque(listaHabitante, listaVacina);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacina(listaHabitante, listaVacina);
    }
}

void MenuRemoverVacina (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina)
{
    DadosVacina dados;
    DadosVacina *aux;
    char vacina [TAM_MAX_STR];


    PrintMessage("Entre com o nome da vacina que deseja remover");
    LerString(vacina, 1);

    aux = consultarVacina(listaVacina, vacina);
    if (listaVacina != NULL && aux != NULL) {
        PrintMessage("Vacina:");
        printf("Nome da vacina: %s\n", aux->tipo);

        PrintMessage("Confirme a remocao da vacina.\n"
                     "0 - Nao\n"
                     "1 - Sim");
        int confirmacao = LerIntervaloInteiro(0, 1);
        if (confirmacao == 1) {
            /* alterar funcao */
            limparListaVacinas(listaVacina);
            PrintMessage("Vacina removida.");
        }
    }
    else {
        PrintMessage("Vacina nao encontrada");
    }

    PrintMessage("Deseja remover outro habitante?\n"
                 "0 - Nao\n"
                 "1 - Sim");
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuRemoverVacina(listaHabitante, listaVacina);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacina(listaHabitante, listaVacina);
    }
}

void MenuVacinacao (ListaVacinas *listaVacina)
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
        case MVACINACAO_REGISTRO:
        case MHABITANTE_REMOVER:
            break;
        case CANCELAR:
            MenuPrincipal(NULL, listaVacina);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacinacao(listaVacina);
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
        case MRELATORIO_PRIMEIRADOSE:
        case MRELATORIO_SEGUNDADOSE:
        case MRELATORIO_NAOVACINADOS:
        case MRELATORIO_PRIORITARIO:
            break;
        case CANCELAR:
            MenuPrincipal(NULL, NULL);
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
