#include <stdio.h>
#include "Interface.h"
#include "habitantes.h"
#include "readStdio.h"
#include "leitura_arquivo.h"
#include "controleVacinas.h"
#include "relatorio.h"

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
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuPrincipal(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario) {
    int seletor;

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
            break;
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuPrincipal(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de cadastro de habitantes
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuHabitantes(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    int seletor;

    PrintMessage("Cadastro de Habitantes", 'c', 1, 1);
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
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de inserção manual de habitantes a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: insere elemento na lista de habitantes
 */
void MenuInserirHabitanteManual(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosHabitante dados;


    if (LerHabitante(&dados, listaHabitantes) != NULL) {
        listaHabitantes = inserirHabitante(listaHabitantes, dados);
        PrintMessage("Habitante cadastrado.", 'e', 1, 1);
    }
    else {
        PrintMessage("CPF ja cadastrado.", 'e', 1, 1);
    }

    PrintMessage("Deseja cadastrar outro habitante?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'e', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirHabitanteManual(listaHabitantes, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuHabitantes(listaHabitantes, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuHabitantes(listaHabitantes, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de inserção por arquivo de habitantes a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elementos de arquivo são inseridos à lista de habitantes
 */
void MenuInserirHabitanteArquivo(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    char arquivo [TAM_MAX_STR];

    PrintMessage("Entre com o caminho do arquivo.", 'e', 1, 1);
    LerString(arquivo, 1);

    listaHabitante = lerArquivo(listaHabitante, arquivo);

    PrintMessage("Deseja cadastrar outra lista de habitantes?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'e', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirHabitanteArquivo(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de consulta por cpf na lista de habitantes
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuConsultarHabitante(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosHabitante *aux;
    char cpf[TAM_MAX_STR];

    PrintMessage("Entre com o cpf que deseja consultar", 'e', 1, 1);
    LerString(cpf, 1);

    aux = consultarHabitante(cpf, listaHabitante);
    if (verificaHabitanteRegistrado(listaHabitante, aux, cpf)) {
        PrintMessage("Habitante:", 'e', 1, 1);
        printf("CPF: %s\n", aux->cpf);
        printf("Nome: %s\n", aux->nome);
        printf("Prioridade: %d\n", aux->prioridade);
        printf("Dose: %d\n", aux->dose);
        if (aux->dose > 0) {
            printf("Vacina: %s\n", aux->tipo_vacina);
            printf("Data da Vacinação: %s\n", aux->data_vacinacao);
        }
    }
    else {
        PrintMessage("CPF nao encontrado", 'e', 1, 1);
    }

    PrintMessage("Deseja consultar outro habitante?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'e', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuConsultarHabitante(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuHabitantes(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de remoção de habitantes da lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento removido da lista de habitantes
 */
void MenuRemoverHabitante(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosHabitante *aux;
    char cpf[TAM_MAX_STR];

    PrintMessage("Entre com o cpf que deseja remover", 'e', 1, 1);
    LerString(cpf, 1);

    aux = consultarHabitante(cpf, listaHabitantes);
    if (verificaHabitanteRegistrado(listaHabitantes, aux, cpf)) {
        PrintMessage("Habitante:", 'e', 1, 1);
        printf("CPF: %s\n", aux->cpf);

        PrintMessage("Confirme a remocao do habitante.\n"
                     "0 - Nao\n"
                     "1 - Sim", 'e', 1, 1);
        int confirmacao = LerIntervaloInteiro(0, 1);
        if (confirmacao == 1) {
            removerHabitante(aux->cpf, listaHabitantes);
            PrintMessage("habitante removido.", 'e', 1, 1);
        }
    }
    else {
        PrintMessage("CPF nao encontrado", 'e', 1, 1);
    }

    PrintMessage("Deseja remover outro habitante?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'e', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuRemoverHabitante(listaHabitantes, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuHabitantes(listaHabitantes, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuHabitantes(listaHabitantes, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de chamada das funções de gerenciamento do cadastro de vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuVacina(ListaHabitantes *listaHabitantes, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    int seletor;

    PrintMessage("Cadastro de Vacinas", 'c', 1, 1);
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
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuVacina(listaHabitantes, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de insercao de vacina a lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento inserido a lista de vacinas
 */
void MenuCadastrarVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosVacina dados;

    LerVacina(&dados);
    if (listaVacina == NULL || (consultarVacina(listaVacina, dados.tipo) == NULL)) {
        listaVacina = inserirVacina(listaVacina, dados);
        PrintMessage("Vacina cadastrada.", 'e', 1, 1);
    }
    else {
        PrintMessage("Vacina ja cadastrada.", 'e', 1, 1);
    }

    PrintMessage("Deseja cadastrar outra Vacina?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'e', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuCadastrarVacina(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de alteraçao de estoque da vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: estoque de elemento da lista de vacinas é alterado
 */
void MenuInserirEstoque(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosVacina dados;
    DadosVacina *aux;
    char vacina [TAM_MAX_STR];

    PrintMessage("Entre com o nome da vacina que deseja alterar o estoque", 'e', 1, 1);
    LerString(vacina, 1);
    aux = consultarVacina(listaVacina, vacina);
    if (listaVacina != NULL && aux != NULL) {
        PrintMessage("Alteracao de estoque", 'e', 1, 1);
        printf("Estoque da vacina %s: %d\n", aux->tipo, aux->estoque);
        dados = *aux;
        LerVacinaEstoque(&dados);
        dados.estoque += aux->estoque;
        if (dados.estoque >= 0) {
            listaVacina = alterarVacina(listaVacina, &dados, dados.tipo);
            printf("Novo estoque da vacina %s: %d\n", aux->tipo, aux->estoque);
        }
        else {
            PrintMessage("Valor de estoque invalido", 'e', 1, 1);
        }
    }
    else {
        PrintMessage("Vacina nao encontrada.", 'e', 1, 1);
    }

    PrintMessage("Deseja alterar o estoque de outra vacina?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'e', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuInserirEstoque(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de remoção de vacina da lista
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: elemento da lista de vacinas é removido
 */
void MenuRemoverVacina(ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosVacina *aux;
    char vacina [TAM_MAX_STR];

    PrintMessage("Entre com o nome da vacina que deseja remover", 'e', 1, 1);
    LerString(vacina, 1);

    aux = consultarVacina(listaVacina, vacina);
    if (listaVacina != NULL && aux != NULL) {
        PrintMessage("Nome da vacina:", 'e', 1, 0);
        printf("- %s\n", aux->tipo);

        PrintMessage("Confirme a remocao da vacina.\n"
                     "0 - Nao\n"
                     "1 - Sim", 'e', 1, 1);
        int confirmacao = LerIntervaloInteiro(0, 1);
        if (confirmacao == 1) {
            removerVacina(vacina, listaVacina);
            PrintMessage("Vacina removida.", 'e', 1, 1);
        }
    }
    else {
        PrintMessage("Vacina nao encontrada", 'e', 1, 1);
    }

    PrintMessage("Deseja remover outra vacina?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'e', 1, 1);
    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuRemoverVacina(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuVacina(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de chamada das funções de gerenciamento da vacinação
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
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
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de liberação de grupo prioritário
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: grupo prioritário é liberado
 */
void MenuLiberarPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    PrintMessage("Liberacao de grupo prioritario.", 'e', 1, 0);

    if (liberaGrupoPrioritario()) {
        *grupoPrioritario += 1;
        PrintMessage("Grupo liberado", 'e', 1, 1);

    }
    imprimeGruposPrioritarios();

    PrintMessage("Deseja liberar outro grupo prioritario?\n"
                 "0 - Nao\n"
                 "1 - Sim", 'e', 1, 0);

    int seletor = LerIntervaloInteiro(0,1);

    switch (seletor) {
        case CONFIMAR:
            MenuLiberarPrioritario(listaHabitante, listaVacina, grupoPrioritario);
        case CANCELAR:
            MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
        default:
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu de registro de vacinação
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: grupo prioritario do elemento liberado
 * Pos-Condição: vacininação do elemento é registrada
 */
void MenuRegistrarVacinacao (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    DadosHabitante *auxHabitante;
    char cpf[TAM_MAX_STR];
    char vacina[TAM_MAX_STR];

    PrintMessage("Registro de vacinacao.", 'e', 1, 0);
    imprimeGruposPrioritarios();
    PrintMessage("", 'e', 0, 1);

    PrintMessage("Entre com o cpf do habitante que deseja vacinar.", 'e', 1, 1);
    LerString(cpf, 1);

    auxHabitante = consultarHabitante(cpf, listaHabitante);
    if (auxHabitante != NULL) {
        PrintMessage("Habitante:", 'e', 1, 0);
        printf("CPF: %s\n", auxHabitante->cpf);
        printf("Nome: %s\n", auxHabitante->nome);
        printf("Dose: %d\n", auxHabitante->dose);
        printf("Vacina: %s\n", auxHabitante->tipo_vacina);
        printf("Grupo prioritario: %d\n", auxHabitante->prioridade);
        if (!verificaVacinaConcluida(auxHabitante)){
            PrintMessage("Habitante ja recebeu as 2 doses da vacina.", 'e', 1, 0);
        }
        LerString(vacina, 1);
        if (auxHabitante->dose == 1 && (strcmp(auxHabitante->tipo_vacina, vacina) != 0)) {
            PrintMessage("Vacina diferente da usada na primeira dose.", 'e', 1, 1);
        }
        else {
            verificaRegistroVacinacao(listaVacina, listaHabitante, auxHabitante->cpf, vacina);
        }
    }
    else {
        PrintMessage("CPF nao encontrado", 'e', 1, 1);
    }

    MenuVacinacao(listaHabitante, listaVacina, grupoPrioritario);
}

/**
 * Menu de relatorios
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
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
            PrintMessage("O valor digitado nao corresponde a nenhuma das operacoes", 'e', 1, 1);
            MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
    }
}

/**
 * Menu que chama função de impressão do relatorio de estoque da vacina
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioEstoque (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    PrintRelatorioEstoque(listaVacina);

    PrintMessage("Pressione uma tecla para continuar...", 'e', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

/**
 * Menu que chama função de impressão do relatorio de vacinados com a primeira dose
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioPrimeiraDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    PrintRelatorioPrimeiraDose(listaHabitante);

    PrintMessage("Pressione uma tecla para continuar...", 'e', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

/**
 * Menu que chama função de impressão do relatorio de vacinados com a segunda dose
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioSegundaDose (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    PrintRelatorioSegundaDose(listaHabitante);

    PrintMessage("Pressione uma tecla para continuar...", 'e', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

/**
 * Menu que chama função de impressão do relatorio de não vacinados
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioNaoVacinados (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    PrintRelatorioNaoVacinados(listaHabitante, grupoPrioritario);

    PrintMessage("Pressione uma tecla para continuar...", 'e', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

/**
 * Menu que chama função de impressão do relatorio de habitantes por grupo prioritario
 * Entrada: lista de habitantes, lista de vacinas e grupo prioritario atual
 * Retorno:nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void MenuRelatorioPrioritario (ListaHabitantes *listaHabitante, ListaVacinas *listaVacina, int *grupoPrioritario)
{
    PrintRelatorioPrioritario(listaHabitante, grupoPrioritario);

    PrintMessage("Pressione uma tecla para continuar...", 'e', 1, 0);
    getchar();
    MenuRelatorio(listaHabitante, listaVacina, grupoPrioritario);
}

