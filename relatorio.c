#include "relatorio.h"

/**
 * Imprime relatorio com nome e estoque de vacinas
 * Entrada: struct da lista de vacinas
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void PrintRelatorioEstoque (ListaVacinas *listaVacina)
{
    ListaVacinas *aux = listaVacina;

    PrintMessage("Estoque de Vacinas:", 'e', 1, 0);
    if (strcmp(aux->dados.tipo, "") != 0 && aux != NULL) {
        while(aux != NULL) {
            printf("Vacina %s: %d\n", aux->dados.tipo, aux->dados.estoque);
            aux = aux->pprox;
        }
    }
    else {
        PrintMessage("Sem Vacinas Cadastradas", 'e', 0,1);
    }
}

/**
 * Imprime relatorio com nome e cpf de habitantes vacinados com a primeira dose
 * Entrada: struct da lista de habitantes
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void PrintRelatorioPrimeiraDose(ListaHabitantes *listaHabitante)
{
    int count = 0;
    ListaHabitantes *aux = listaHabitante;

    PrintMessage("Habitantes vacinados com a 1a dose:", 'e', 1, 1);
    if (strcmp(aux->habitante.cpf, "") != 0 && aux != NULL) {
        printf("%*s       | %*s\n", 8, "CPF", 7, "Nome");
        while (aux != NULL) {
            if (aux->habitante.dose == 1) {
                printf("%-15s| %s  \n", aux->habitante.cpf, aux->habitante.nome);
                count++;
            }
            aux = aux->pprox;
        }
        if (count == 0) {
            PrintMessage("Sem habitantes vacinados com a 1a dose.", 'e', 1, 1);
        }
    } else {
        PrintMessage("Sem habitantes cadastrados.", 'e', 0, 1);
    }
}

/**
 * Imprime relatorio do numero de habitantes vacinados com a segunda dose
 * Entrada: struct da lista de habitantes
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void PrintRelatorioSegundaDose(ListaHabitantes *listaHabitante) {
    int count = 0;
    ListaHabitantes *aux = listaHabitante;

    PrintMessage("Habitantes vacinados com a 2a dose:", 'e', 1, 1);
    if (strcmp(aux->habitante.cpf, "") != 0 && aux != NULL) {
        while (aux != NULL) {
            if (aux->habitante.dose == 2) {
                count++;
            }
            aux = aux->pprox;
        }
        printf("Numero de vacinados com a segunda dose: %d \n", count);
    } else {
        PrintMessage("Sem habitantes cadastrados.", 'e', 0, 1);
    }
}

/**
 * Imprime relatorio de habitantes não vacinados por grupo prioritario
 * Entrada: struct da lista de habitantes e numero ultimo do grupo prioritario liberado
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void PrintRelatorioNaoVacinados(ListaHabitantes *listaHabitante, int *grupoPrioritario)
{
    int count = 0;
    ListaHabitantes *aux = listaHabitante;

    PrintMessage("Habitantes nao vacinados:", 'e', 1, 1);
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
        PrintMessage("Sem habitantes cadastrados.", 'e', 0,1);
    }
}

/**
 * Imprime relatorio de habitantes por grupo prioritario
 * Entrada: struct da lista de habitantes e numero ultimo do grupo prioritario liberado
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pos-Condição: nenhuma
 */
void PrintRelatorioPrioritario (ListaHabitantes *listaHabitante, int *grupoPrioritario)
{
    int count = 0;
    ListaHabitantes *aux = listaHabitante;

    PrintMessage("Numero de pessoas por grupo prioritario:", 'e', 1, 1);
    if (strcmp(aux->habitante.cpf, "") != 0 && aux != NULL) {
        for (int i = 1; i <= 5; i++) {
            while(aux != NULL) {
                if (aux->habitante.prioridade == i) {
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
        PrintMessage("Sem habitantes cadastrados.", 'e', 0,1);
    }
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
    if (strcmp(str, "") != 0  && alinhamento == 'e') {
        printf("%s\n", str);
    }
    else if (strcmp(str, "") != 0  && alinhamento == 'c') {
        for (int i = 0; i < tamanho / 2; i++) {
            printf(" ");
        }
        printf("%s\n", str);
    }
    else if (strcmp(str, "") != 0  && alinhamento == 'd') {
        for (int i = 0; i < tamanho; i++) {
            printf(" ");
        }
        printf("%s\n", str);
    }
    if (barraBase == 1) {
        printf("--------------------------------------------------------------------------------\n");
    }
}
