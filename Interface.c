#include <stdio.h>
#include "Interface.h"
#include "habitantes.h"
#include "readStdio.h"
#include "leitura_arquivo.h"
#include "controleVacinas.h"

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
void MenuPrincipal(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario) {
    int seletor;

    /*
    printf("--------------------------------------------------------------------------------\n");
    printf("                              Menu Principal\n");
    printf("--------------------------------------------------------------------------------\n\n");
    */
    PrintMessage("Menu Principal", 'c', 1, 1);
    printf("Entre com o numero da operacao desejada\n\n");
    printf("%d - Cadastro de habitantes\n", MMENU_HABITANTE);
    printf("%d - Cadastro de Vacinas\n", MMENU_VACINA);
    printf("%d - Registro de vacinacao\n", MMENU_VACINACAO);
    printf("%d - Relatorios\n", MMENU_RELATORIO);
    printf("%d - Encerrar programa\n", CANCELAR);

    seletor = LerInteiro();

    switch (seletor) {
        case MMENU_HABITANTE:
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
        case MMENU_VACINA:
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
        case MMENU_VACINACAO:
            MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
        case MMENU_RELATORIO:
            MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            return;
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuPrincipal(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de cadastro de habitantes
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuHabitantes(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
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
            MenuInserirHabitanteManual(listaHabitante, listaVacina, grupoPrioritario);
        case MHABITANTE_INSERIRARQUIVO:
            MenuInserirHabitanteArquivo(listaHabitante, listaVacina, grupoPrioritario);
        case MHABITANTE_CONSULTAR:
            MenuConsultarHabitante(listaHabitante, listaVacina, grupoPrioritario);
        case MHABITANTE_REMOVER:
            MenuRemoverHabitante(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuPrincipal(listaHabitante, listaVacina, grupoPrioritario);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de inserção manual de habitantes a lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: insere elemento na lista de habitantes
 */
void MenuInserirHabitanteManual(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosHabitante dados;

    LerHabitante(&dados);
    if (listaHabitantes == NULL || (consultarHabitante(dados.cpf, listaHabitantes) == NULL)) {
        listaHabitantes = inserirHabitante(listaHabitantes, dados);
        PrintMessage("Cadastrado.", 'd', 1, 1);
    }
    else {
        PrintMessage("CPF ja cadastrado.", 'd', 1, 1);
    }

    PrintMessage("Deseja cadastrar outro habitante?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'd', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirHabitanteManual(listaHabitantes, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuHabitantes(listaHabitantes, listaVacina, grupoPrioritario);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitantes, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de inserção por arquivo de habitantes a lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elementos de arquivo são inseridos à lista de habitantes
 */
void MenuInserirHabitanteArquivo(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    char arquivo [TAM_MAX_STR];

    PrintMessage("Entre com o caminho do arquivo.", 'd', 1, 1);
    LerString(arquivo, 1);

    listaHabitante = lerArquivo(listaHabitante, arquivo);

    PrintMessage("Deseja cadastrar outra lista de habitantes?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'd', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirHabitanteArquivo(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de consulta por cpf na lista de habitantes
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuConsultarHabitante(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosHabitante *aux;
    char cpf[TAM_MAX_STR];

    PrintMessage("Entre com o cpf que deseja consultar", 'd', 1, 1);
    LerString(cpf, 1);

    aux = consultarHabitante(cpf, listaHabitante);
    if (listaHabitante != NULL && aux != NULL) {
        PrintMessage("Habitante:", 'd', 1, 1);
        printf("CPF: %s\n", aux->cpf);
    }
    else {
        PrintMessage("CPF nao encontrado", 'd', 1, 1);
    }

    PrintMessage("Deseja consultar outro habitante?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'd', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuConsultarHabitante(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de remoção de habitantes da lista
 * Entrada: lista de habitantes
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento removido da lista de habitantes
 */
void MenuRemoverHabitante(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosHabitante *aux;
    char cpf[TAM_MAX_STR];

    PrintMessage("Entre com o cpf que deseja remover", 'd', 1, 1);
    LerString(cpf, 1);

    aux = consultarHabitante(cpf, listaHabitantes);
    if (listaHabitantes != NULL && aux != NULL) {
        PrintMessage("Habitante:", 'd', 1, 1);
        printf("CPF: %s\n", aux->cpf);

        PrintMessage("Confirme a remocao do habitante.\n"
                     "0 - Nao\n"
                     "1 - Sim", 'd', 1, 1);
        int confirmacao = LerIntervaloInteiro(0, 1);
        if (confirmacao == 1) {
            removerHabitante(aux->cpf, listaHabitantes);
            PrintMessage("habitante removido.", 'd', 1, 1);
        }
    }
    else {
        PrintMessage("CPF nao encontrado", 'd', 1, 1);
    }

    PrintMessage("Deseja remover outro habitante?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'd', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuRemoverHabitante(listaHabitantes, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuHabitantes(listaHabitantes, listaVacina, grupoPrioritario);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuHabitantes(listaHabitantes, listaVacina, grupoPrioritario);
    }
}

void MenuVacina(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario)
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
            MenuCadastrarVacina(listaHabitantes, listaVacina, grupoPrioritario);
        case MVACINA_INSERIRESTOQUE:
            MenuInserirEstoque(listaHabitantes, listaVacina, grupoPrioritario);
        case MVACINA_REMOVER:
            MenuRemoverVacina(listaHabitantes, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuPrincipal(listaHabitantes, listaVacina, grupoPrioritario);
            break;
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacina(listaHabitantes, listaVacina, grupoPrioritario);
    }
}

void MenuCadastrarVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosVacina dados;

    LerVacina(&dados);
    if (listaVacina == NULL || (consultarVacina(listaVacina, dados.tipo) == NULL)) {
        listaVacina = inserirVacina(listaVacina, dados);
        PrintMessage("Vacina cadastrada.", 'd', 1, 1);
    }
    else {
        PrintMessage("Vacina ja cadastrada.", 'd', 1, 1);
    }

    PrintMessage("Deseja cadastrar outra Vacina?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'd', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuCadastrarVacina(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
    }
}

void MenuInserirEstoque(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosVacina dados;
    DadosVacina *aux;
    char vacina [TAM_MAX_STR];

    PrintMessage("Entre com o nome da vacina que deseja alterar o estoque", 'd', 1, 1);
    LerString(vacina, 1);
    aux = consultarVacina(listaVacina, vacina);
    if (listaVacina != NULL && aux != NULL) {
        PrintMessage("Alteracao de estoque", 'd', 1, 1);
        printf("Estoque da vacina %s: %d\n", aux->tipo, aux->estoque);
        dados = *aux;
        LerVacinaEstoque(&dados);
        dados.estoque += aux->estoque;
        if (dados.estoque >= 0) {
            listaVacina = alterarVacina(listaVacina, &dados, vacina);
            printf("Novo estoque da vacina %s: %d\n", aux->tipo, aux->estoque);
        }
        else {
            PrintMessage("Valor de estoque invalido", 'd', 1, 1);
        }
    }
    else {
        PrintMessage("Vacina nao encontrada.", 'd', 1, 1);
    }

    PrintMessage("Deseja alterar o estoque de outra vacina?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'd', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirEstoque(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
    }
}

void MenuRemoverVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosVacina *aux;
    char vacina [TAM_MAX_STR];

    PrintMessage("Entre com o nome da vacina que deseja remover", 'd', 1, 1);
    LerString(vacina, 1);

    aux = consultarVacina(listaVacina, vacina);
    if (listaVacina != NULL && aux != NULL) {
        PrintMessage("Nome da vacina:", 'd', 1, 0);
        printf("- %s\n", aux->tipo);

        PrintMessage("Confirme a remocao da vacina.\n"
                     "0 - Nao\n"
                     "1 - Sim", 'd', 1, 1);
        int confirmacao = LerIntervaloInteiro(0, 1);
        if (confirmacao == 1) {
            removerVacina(vacina, listaVacina);
            PrintMessage("Vacina removida.", 'd', 1, 1);
        }
    }
    else {
        PrintMessage("Vacina nao encontrada", 'd', 1, 1);
    }

    PrintMessage("Deseja remover outra vacina?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'd', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuRemoverVacina(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'd', 1, 1);
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
    }
}

void MenuVacinacao(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    int seletor;

    PrintMessage("Gerenciamento de Vacinacao", 'c', 1, 1);
    printf("Entre com o numero da operacao desejada\n");
    printf("%d - Liberacao de grupo prioritario\n", MVACINACAO_LIBERARGRUPO);
    printf("%d - Registrar vacinacao\n", MVACINACAO_REGISTRO);
    printf("%d - Voltar\n", CANCELAR);

    seletor = LerInteiro();

    switch (seletor) {
        case MVACINACAO_LIBERARGRUPO:
            MenuLiberarPrioritario(listaHabitante, listaVacina, grupoPrioritario);
        case MVACINACAO_REGISTRO:
            MenuRegistrarVacinacao(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuPrincipal(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'd', 1, 1);
            MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
    }
}

void MenuLiberarPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    PrintMessage("Liberacao de grupo prioritario.", 'd', 1, 0);
    imprimeGruposPrioritarios();

    if (*grupoPrioritario < 5) {
        PrintMessage("Confirme a liberacao do grupo proximo grupo prioritario\n"
                     "0 - Nao\n"
                     "1 - Sim", 'd', 1, 0);
        int confirmacao = LerIntervaloInteiro(0, 1);
        if (confirmacao == 1) {
            *grupoPrioritario += 1;
            PrintMessage("Grupo liberado", 'd', 1, 1);
            printf("Grupo prioritario atual: %d\n", *grupoPrioritario);
        }
        PrintMessage("Deseja liberar outro grupo prioritario?\n"
                     "0 - Nao\n"
                     "1 - Sim", 'd', 1, 0);

        int seletor = LerIntervaloInteiro(0,1);

        switch (seletor) {
            case CONFIMAR:
                MenuLiberarPrioritario(listaHabitante, listaVacina, grupoPrioritario);
            case CANCELAR:
                MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
            default:
                PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'd', 1, 1);
                MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
        }
    }
    else {
        PrintMessage("Ultimo grupo prioritario ja liberado.", 'd', 1, 1);
        MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
    }
}

void MenuRegistrarVacinacao (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosHabitante *auxHabitante;
    DadosVacina *auxVacina;
    char cpf[TAM_MAX_STR];
    char vacina[TAM_MAX_STR];

    PrintMessage("Registro de vacinacao.", 'd', 1, 0);
    imprimeGruposPrioritarios();
    PrintMessage("", 'd', 0, 1);

    PrintMessage("Entre com o cpf do habitante que deseja vacinar.", 'd', 1, 1);
    LerString(cpf, 1);

    auxHabitante = consultarHabitante(cpf, listaHabitante);
    if (listaHabitante != NULL && auxHabitante != NULL) {
        PrintMessage("Habitante:", 'd', 1, 0);
        printf("CPF: %s\n", auxHabitante->cpf);
        printf("Nome: %s\n", auxHabitante->nome);
        printf("Dose: %d\n", auxHabitante->dose);
        printf("Vacina: %s\n", auxHabitante->tipo_vacina);
        printf("Grupo prioritario: %d\n", auxHabitante->prioridade);

        if (auxHabitante->dose >= 2){
            PrintMessage("Habitante ja recebeu as 2 doses da vacina.", 'd', 1, 0);
        }
        else if (auxHabitante->prioridade <= *grupoPrioritario && auxHabitante->dose == 0) {
            PrintMessage("Entre com o nome da vacina", 'd', 1, 0);
            LerString(vacina, 1);
            auxVacina = consultarVacina(listaVacina, vacina);
            if (listaVacina != NULL && auxVacina != NULL && auxVacina->estoque > 0) {
                auxHabitante->dose++;
                strcpy(auxHabitante->tipo_vacina, vacina);
                auxVacina->estoque-=1;
                PrintMessage("Habitante Vacinado.", 'd', 1, 1);
            }
            else {
                PrintMessage("Sem Estoque da vacina ou a vacina nao existe.", 'd', 1, 1);
            }
        }
        else if (auxHabitante->prioridade <= *grupoPrioritario && auxHabitante->dose == 1) {
            auxVacina = consultarVacina(listaVacina, auxHabitante->tipo_vacina);
            if (listaVacina != NULL && auxVacina != NULL && auxVacina->estoque > 0) {
                auxHabitante->dose++;
                auxVacina->estoque-=1;
                PrintMessage("Habitante Vacinado.", 'd', 1, 1);
            }
            else {
                PrintMessage("Sem Estoque da vacina ou a vacina nao existe.", 'd', 1, 1);
            }
        }
        else {
            PrintMessage("Grupo prioritario do habitante nao foi liberado para vacinacao.", 'd', 1, 1);
        }
    }
    else {
        PrintMessage("CPF nao encontrado", 'd', 1, 1);
    }

    PrintMessage("Deseja vacinar outro habitante?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'd', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuRegistrarVacinacao(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
        default:
            printf("--------------------------------------------------------------------------------\n");
            printf("O valor digitado nao corresponde a nenhuma das operacoes\n");
            printf("--------------------------------------------------------------------------------\n");
            MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
    }
}

void MenuRelatorio (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    int seletor;

    PrintMessage("Relatorios", 'c', 1, 1);
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
            MenuRelatorioEstoque(listaHabitante, listaVacina, grupoPrioritario);
        case MRELATORIO_PRIMEIRADOSE:
            MenuRelatorioPrimeiraDose(listaHabitante, listaVacina, grupoPrioritario);
        case MRELATORIO_SEGUNDADOSE:
            MenuRelatorioSegundaDose(listaHabitante, listaVacina, grupoPrioritario);
        case MRELATORIO_NAOVACINADOS:
            MenuRelatorioNaoVacinados(listaHabitante, listaVacina, grupoPrioritario);
        case MRELATORIO_PRIORITARIO:
            MenuRelatorioPrioritario(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuPrincipal(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'd', 1, 1);
            MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
    }
}

void MenuRelatorioEstoque (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    ListaVacinas *aux = listaVacina;

    PrintMessage("Estoque de Vacinas:", 'd', 1, 0);
    if (strcmp(aux->dados.tipo, "") != 0 && aux != NULL) {
        while(aux != NULL) {
            printf("Vacina %s: %d\n", aux->dados.tipo, aux->dados.estoque);
            aux = aux->pprox;
        }
    }
    else {
        PrintMessage("Sem Vacinas Cadastradas", 'd', 0,1);
    }
    PrintMessage("Pressione uma tecla para continuar...", 'd', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

void MenuRelatorioPrimeiraDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    ListaHabitantes *aux = listaHabitante;

    PrintMessage("Habitantes vacinados com a 1a dose:", 'd', 1, 1);
    if (strcmp(aux->habitante.cpf, "") != 0 && aux != NULL) {
        printf("%*s       | %*s\n", 8, "CPF", 7, "Nome");
        while(aux != NULL) {
            if (aux->habitante.dose == 1) {
                printf("%-15s| %s  \n", aux->habitante.cpf, aux->habitante.nome);
            }
            aux = aux->pprox;
        }
    }
    else {
        PrintMessage("Sem habitantes cadastrados.", 'd', 0,1);
    }
    PrintMessage("Pressione uma tecla para continuar...", 'd', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

void MenuRelatorioSegundaDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    int count = 0;
    ListaHabitantes *aux = listaHabitante;

    PrintMessage("Habitantes vacinados com a 2a dose:", 'd', 1, 1);
    if (strcmp(aux->habitante.cpf, "") != 0 && aux != NULL) {
        while(aux != NULL) {
            if (aux->habitante.dose == 2) {
                count++;
            }
            aux = aux->pprox;
        }
        printf("Numero de vacinados com a segunda dose: %d \n", count);
    }
    else {
        PrintMessage("Sem habitantes cadastrados.", 'd', 0,1);
    }

    PrintMessage("Pressione uma tecla para continuar...", 'd', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

void MenuRelatorioNaoVacinados (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    int count = 0;
    ListaHabitantes *aux = listaHabitante;

    PrintMessage("Habitantes nao vacinados:", 'd', 1, 1);
    if (strcmp(aux->habitante.cpf, "") != 0 && aux != NULL) {
        for (int i = 1; i <= 5; i++) {
            printf("\nPrioridade: %d\n", i);
            printf("%*s       | %*s\n", 8, "CPF", 7, "Nome");
            while(aux != NULL) {
                if (aux->habitante.dose == 0 && aux->habitante.prioridade == i) {
                    printf("%-15s| %s  \n", aux->habitante.cpf, aux->habitante.nome);
                    count++;
                }
                aux = aux->pprox;
            }
            aux = listaHabitante;
        }
        printf("Pessoas nao vacinadas: %d \n", count);
    }
    else {
        PrintMessage("Sem habitantes cadastrados.", 'd', 0,1);
    }

    PrintMessage("Pressione uma tecla para continuar...", 'd', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

void MenuRelatorioPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    int count = 0;
    ListaHabitantes *aux = listaHabitante;

    PrintMessage("Numero de pessoas por grupo prioritario:", 'd', 1, 1);
    if (strcmp(aux->habitante.cpf, "") != 0 && aux != NULL) {
        for (int i = 1; i <= 5; i++) {
            while(aux != NULL) {
                if (aux->habitante.dose == 0 && aux->habitante.prioridade == i) {
                    count++;
                }
                aux = aux->pprox;
            }
            printf("Grupo prioritário %d: %d \n", i, count);
            count = 0;
            aux = listaHabitante;
        }
    }
    else {
        PrintMessage("Sem habitantes cadastrados.", 'd', 0,1);
    }

    PrintMessage("Pressione uma tecla para continuar...", 'd', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

/**
 * Imprime mensagem formatada
 * Entrada: string contendo o texto da mensagem e opcoes de formatacao
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void PrintMessage(char *str, char alinhamento, int barraTopo, int barraBase)
{
    int tamanho = 80;
    tamanho -= strlen(str);

    if (barraTopo == 1) {
        printf("--------------------------------------------------------------------------------\n");
    }
    if (alinhamento == 'd') {
        printf("%s\n", str);
    }
    else if (alinhamento == 'c') {
        for (int i = 0; i < tamanho / 2; i++) {
            printf(" ");
        }
        printf("%s\n", str);
    }
    else if (alinhamento == 'e') {
        for (int i = 0; i < tamanho; i++) {
            printf(" ");
        }
        printf("%s\n", str);
    }
    if (barraBase == 1) {
        printf("--------------------------------------------------------------------------------\n");
    }

}
