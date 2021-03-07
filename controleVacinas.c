#include "controleVacinas.h"
#include "vacinas.h"
#include "habitantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "leitura_arquivo.h"
#include <string.h>



// Vetor global de grupos prioritarios
int grupo_prioritario[MAX_GRUPO_PRIORITARIO] = {1,2,3,4,5};


/**
 * Imprime os grupos prioritarios liberados para vacinacao
 * Entrada: nenhuma
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: imprime na tela os grupos prioritarios ja liberados para vacinacao
 */
void imprimeGruposPrioritarios(){
    int i = 0;
    printf("\nGrupos ja liberados para a vacinacao:\n");
    while(grupo_prioritario[i] && grupo_prioritario[i] != 0){
        printf("    %d", grupo_prioritario[i]);
        i++;
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
        printf("Invalido! Entre novamete: ");
        scanf("%d",grupo);
    }
    if(grupo_prioritario[*grupo-1] == *grupo){
        printf("Grupo ja liberado!\n");
        return 2;
    }else if(*grupo > 1 && grupo_prioritario[*grupo-2] == 0 ){
         printf("Grupo nao pode ser liberado!\n");
         return 2;
    }
    grupo_prioritario[*grupo-1] = *grupo;
    printf("Grupo prioritario %d foi adicionado!\n",*grupo);

    if(grupo_prioritario[4] != 0){
        printf("Grupos prioritarios completos!\n");
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
    if(grupo_prioritario[0] == 0)
        printf("\nLibere um grupo para a vacinacao!\n");
    else{
        imprimeGruposPrioritarios();
    }
    printf("\n");

    printf("\nEntre com o numero do grupo 1 a 5: ");
    scanf("%d",&grupo); // talvez tenha que mudar o nome da var

    if(validaGrupoPrioritario(&grupo) == 0) return 0;

    return 1;
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
    if(dadosH->nome == NULL){
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
DadosVacina* verificaEstoqueVacina(ListaVacinas *l, DadosVacina *dadosVac){
    //printf("\nTipo da vacina: %s\nEstoque: %d\n",lista->dados.tipo,lista->dados.estoque);
    printf("Insira o nome da vacina\n");
    gets(dadosVac->tipo);

    dadosVac = consultarVacina(l,dadosVac->tipo);

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
void registrarVacinacao(char *cpf, ListaVacinas *listaV,DadosVacina *dadosVac, DadosHabitante *dadosH){
    dataAgora(dadosH);
    strcpy(dadosH->tipo_vacina, dadosVac->tipo);

    dadosH->dose++;

    // Diminui do estoque
    dadosVac->estoque--;

    listaV = alterarVacina(listaV, dadosVac, listaV->dados.tipo);
}


int main()
{
    //testes
    ListaHabitantes *lista;
    lista = malloc (sizeof (ListaHabitantes));

    char caminhoArq [300];
    strcpy(caminhoArq, "habitantes.txt");
    lista = lerArquivo(lista, caminhoArq);

    DadosHabitante *dados;
    dados = malloc(sizeof(DadosHabitante));

    ListaVacinas *listaVac;
    listaVac = malloc(sizeof(ListaVacinas));

    DadosVacina *dadosVac;
    dadosVac = malloc(sizeof(DadosVacina));

    DadosVacina dadosV;

//    // consultar dados e imprimir
//    char cpf[8];
//    strcpy(cpf, "11111111111");
//    dados = consultarHabitante(cpf, lista);
//    printf ("%s \n", dados->cpf);
//
//    //remiver um H
//    printf ("H a remover %s \n", dados->nome);
//    lista = removerHabitante("11111111111",lista);
//
//    dados = consultarHabitante("11111111111", lista);
//    if(dados->nome == NULL) printf("H n existe\n");
//    else printf ("H encontrado: %s \n", dados->nome);
//
//    dados = consultarHabitante("66666666666", lista);
//    if(dados->nome == NULL) printf("H n existe\n");
//    else printf ("H encontrado: %s \n", dados->nome);
//

    // Registro de vacinacao

    // Liberer grupo prioritario
    // Testes
    //liberaGrupoPrioritario();



    // Inserir vacina
    // Testes
    strcpy(dadosV.tipo,"v1");
    dadosV.estoque = 2;

    listaVac = inserirVacina(listaVac, dadosV);
    if(listaVac == NULL) printf("\nErro ao inserir\n");

    strcpy(dadosV.tipo,"v2");
    dadosV.estoque = 0;

    listaVac = inserirVacina(listaVac, dadosV);
    if(listaVac == NULL) printf("\nErro ao inserir\n");

    strcpy(dadosV.tipo,"v3");
    dadosV.estoque = 1;

    listaVac = inserirVacina(listaVac, dadosV);
    if(listaVac == NULL) printf("\nErro ao inserir\n");

    char cpf[12];
    strcpy(cpf, "55555555555");
    //..


// Parte do registro de vacinacao do habitante //

    // Verifica se o habitante esta registrado
    if(verificaHabitanteRegistrado(lista, dados, cpf)){
        dados = consultarHabitante(cpf, lista);

        // Verifica o grupo prioritario do habitante

        // teste
        //dados->prioridade = 2;
        if(verificaGrupoPrioritarioH(dados)){

            dados = consultarHabitante(cpf, lista);

            // Teste
            //dados->dose = 0;

            // Verifica se o habitante ja foi vacinado
            if(verificaVacinaConcluida(dados)){

                // Veritfica se a vacina esta diponivel
                dadosVac = verificaEstoqueVacina(listaVac, dadosVac);
                if(dadosVac == NULL){
                    printf("Nao e possivel vacinar. Estoque zerado\n");

                }else{
                    // Registrar vacinacao
                    dados = consultarHabitante(cpf, lista);
                    registrarVacinacao(cpf,listaVac,dadosVac, dados);
                    //teste
                    printf("\nAlteracao:\ntipo vacina H = %s\nestoque = %d\nH = %s\ndose = %d\n",dados->tipo_vacina, listaVac->dados.estoque,dados->nome,dados->dose);
                    printf("data = %s\n",dados->data_vacinacao);
                }
            }else{
                printf("Habitante ja vacinado\n");
            }
        }else{
            printf("O habitante nao pode ser vacinado porque seu grupo nao esta liberado para vacinacao\n");
        }
    }else
        printf("Habitante nao registrado\n");

    return 0;
}




