#include "controleVacinas.h"
#include "vacinas.h"
#include "habitantes.h"
#include "leitura_arquivo.h"
#include "readStdio.h"
#include "constantes.h"
#include "relatorio.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



// Vetor global de grupos prioritarios
int grupo_prioritario[MAX_GRUPO_PRIORITARIO] = {0};


/**
 * Imprime os grupos prioritarios liberados para vacinacao
 * Entrada: nenhuma
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: imprime na tela os grupos prioritarios ja liberados para vacinacao
 */
void imprimeGruposPrioritarios(){
    int i = 0;
    PrintMessage("Grupos ja liberados para a vacinacao:", 'e', 1, 0);
    if (grupo_prioritario[0] == 0){
        PrintMessage("Nenhum grupo liberado", 'e', 0, 0);
    }
    else {
        while (grupo_prioritario[i] && grupo_prioritario[i] != 0) {
            printf("    %d", grupo_prioritario[i]);
            i++;
        }
        printf("\n");
    }
}

/**
 * Valida os grupos prioritarios e adiciona um grupo
 * Entrada: um ponteiro de inteiro contendo um valor
 * Retorno: inteiro, 1 - grupo adicionado, 2 - ocorreu um erro de validacao, 0 - grupos completos
 * Pré-condição: variavel contendo um valor
 * Pós-condição: grupo validado adicionado ou mensagem com um erro
 */
int validaGrupoPrioritario(int *grupo){
    while(*grupo < 1 || *grupo > 5){
        PrintMessage("Invalido! Entre com o numero do grupo 1 a 5: ", 'e', 1, 0);
        *grupo = LerInteiro();
    }
    if(grupo_prioritario[*grupo-1] == *grupo){
        PrintMessage("Grupo ja liberado.", 'e', 1, 1);
        return 2;
    }else if(*grupo > 1 && grupo_prioritario[*grupo-2] == 0 ){
        PrintMessage("Grupo nao pode ser liberado.", 'e', 1, 1);
        return 2;
    }
    grupo_prioritario[*grupo-1] = *grupo;
    PrintMessage("Grupo pode ser liberado.", 'e', 1, 1);

    if(grupo_prioritario[4] != 0){
        PrintMessage("Ultimo grupo prioritario ja liberado.", 'e', 1, 1);
        return 0;
    }
    return 1;
}

/**
 * Libera grupos prioritarios
 * Entrada:nenhuma
 * Retorno: inteiro, 0 - para encerrar a liberacao dos grupos (quando todos os grupos foram adicionados), 1 - continuar liberando grupos
 * Pré-condição: nenhuma
 * Pós-condição: grupo liberado para vacinacao
 */
int liberaGrupoPrioritario(){
    int grupo = 1;
    imprimeGruposPrioritarios();

    PrintMessage("Entre com o numero do grupo 1 a 5: ", 'e', 1, 0);
    grupo = LerInteiro(); // talvez tenha que mudar o nome da var

    if(validaGrupoPrioritario(&grupo) == 1) return 1;

    return 0;
}

/**
 * Verifica se o habitente existe no registro
 * Entrada: lista, dados do habitante e cpf do habitante
 * Retorno: inteiro, 0 - se o habitante nao existe no reistro, 1 - se o habitante existe no registro
 * Pré-condição: numero do cpf, lista e dados preenchidos
 * Pós-condição: se o habitante foi encontrado ou nao
 */
int verificaHabitanteRegistrado(ListaHabitantes *lista, DadosHabitante *dadosH, char *cpf){
    dadosH = consultarHabitante(cpf, lista);
    if(dadosH == NULL){
        return 0;
    }else{
        //printf ("Habitante encontrado:\n nome: %s\n cpf: %s\n prioridade: %d\n", dadosH->nome, dadosH->cpf,dadosH->prioridade);
        return 1;
    }
}

/**
 * Verifica se o grupo prioritario do habitante
 * Entrada: dados do habitante
 * Retorno: inteiro, 0 - se o habitante nao esta no grupo prioritario, 1 - se o habitante esta no grupo prioritario
 * Pré-condição: dados do habitante preenchidos
 * Pós-condição: se o habitante esta no grupo prioritario para a vacinacao
 */
int verificaGrupoPrioritarioH(DadosHabitante *dadosH){
    int i = 0;
    for(i = 0; grupo_prioritario[i] != 0; i++){
        if(dadosH->prioridade == grupo_prioritario[i]){
            return 1;
        }
    }

    return 0;
}

/**
 * Verifica se o habitante ja foi vacinado
 * Entrada: dados do habitante
 * Retorno: inteiro, 0 - se o habitante ja tomou as 2 doses, 1 - se o habitante pode tomar vacina
 * Pré-condição: dados do habitante preenchidos
 * Pós-condição: se o habitante pode ou nao tomar vacina
 */
int verificaVacinaConcluida(DadosHabitante *dadosH){
    if(dadosH->dose != 2){
        return 1;
    }
    return 0;
}

/**
 * Verifica se existe vacina disponivel no estoque
 * Entrada: lista de vacinas e dados da vacina
 * Retorno: dados da vacina disponivel ou NULL se nao a vacina disponivel
 * Pré-condição: nenhuma
 * Pós-condição: vacina disponivel para ser aplicada
 */
DadosVacina *verificaEstoqueVacina(DadosVacina *dadosVac) {
    //printf("\nTipo da vacina: %s\nEstoque: %d\n",lista->dados.tipo,lista->dados.estoque);
    if (dadosVac != NULL && dadosVac->estoque > 0)
        return dadosVac;
    else
        return NULL;
}

/**
 * Imprime estoque de vacinas
 * Entrada: lista de vacinas
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: imprime a lista de dados das vacinas presentes no estoque
 */
void imprimeVacinas(ListaVacinas *l){
    int i = 0;
    while(l != NULL && (l->dados.tipo != NULL)){
        l = l->pprox;
        printf("\n%d   Tipo da vacina: %s\nEstoque: %d\n",i,l->dados.tipo,l->dados.estoque);
        i++;
    }


}

/**
 * Registra a data atual da vacinacao
 * Entrada:dados do habitante
 * Retorno: nenhum
 * Pré-condição: nenhua
 * Pós-condição: data atual registrada no dados do habitante
 */
void dataAgora(DadosHabitante *dadosH){
    // Formatar data
    struct tm *dataAtual;
    time_t segundos;
    time(&segundos);
    dataAtual = localtime(&segundos);
    char dia[2];
    char mes[2];
    char ano[4];

    sprintf(dia, "%i", dataAtual->tm_mday);

    strcpy(dadosH->data_vacinacao,dia);
    strcat(dadosH->data_vacinacao, "/");

    sprintf(mes, "%i", dataAtual->tm_mon+1);

    strcat(dadosH->data_vacinacao, mes);
    strcat(dadosH->data_vacinacao, "/");

    sprintf(ano, "%i", dataAtual->tm_year+1900);
    strcat(dadosH->data_vacinacao, ano);
}

/**
 * Registra a vacinacao do habitante
 * Entrada: lista de vacinas, dados da vacina e habitante, e o cpf do habitante
 * Retorno: nenhum
 * Pré-condição: numero do cpf, listas preenchidas
 * Pós-condição: registra que o habitate foi vacinado
 */
void registrarVacinacao(char *cpf, DadosVacina *dadosVac, DadosHabitante *dadosH) {
    dataAgora(dadosH);
    strcpy(dadosH->tipo_vacina, dadosVac->tipo);

    dadosH->dose++;

    // Diminui do estoque
    dadosVac->estoque-=1;
}

/**
 * Verifica dados referente a vacinacao
 * Entrada: string com o cpf do habitante
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: verificacao dos dados
 */
void verificaRegistroVacinacao(ListaVacinas *listaVacina, ListaHabitantes *listaHabitante, char cpf[], char vacina[])
{
    DadosHabitante *dados;
    DadosVacina aux;
    DadosVacina *dadosVac;
    dadosVac = &aux;

    // Verifica se o habitante esta registrado
    dados = consultarHabitante(cpf, listaHabitante);
    if(verificaHabitanteRegistrado(listaHabitante, dados, cpf)){

        // Verifica o grupo prioritario do habitante
        if(verificaGrupoPrioritarioH(dados)){

            // Verifica se o habitante ja foi vacinado
            if(verificaVacinaConcluida(dados)){

                // Veritfica se a vacina esta diponivel
                dadosVac = consultarVacina(listaVacina, vacina);
                if(dadosVac == NULL || verificaEstoqueVacina(dadosVac) == NULL){
                    PrintMessage("Sem Estoque da vacina.", 'e', 1, 1);
                }
                else {
                    // Registrar vacinacao
                    registrarVacinacao(cpf, dadosVac, dados);

                    PrintMessage("Dados da vacinacao:", 'e', 1, 0);
                    printf("Tipo da vacina = %s\nEstoque = %d\nHabitante = %s\nDose = %d\n", dados->tipo_vacina, listaVacina->dados.estoque, dados->nome, dados->dose);
                    printf("Data = %s\n",dados->data_vacinacao);
                }
            }else{
                PrintMessage("Habitante ja recebeu as 2 doses da vacina.", 'e', 1, 1);
            }
        }else{
            PrintMessage("O habitante nao pode ser vacinado porque seu grupo nao esta liberado para vacinacao.", 'e', 1, 1);
        }
    }else
        PrintMessage("Habitante nao registrado.", 'e', 1, 1);
}




