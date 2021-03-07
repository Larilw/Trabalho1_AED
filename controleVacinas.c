#include "controleVacinas.h"
#include "vacinas.h"
#include "habitantes.h"

#include <stdio.h>
#include <stdlib.h>


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
 * Entrada: lista de vacinas
 * Retorno: dados da vacina disponivel ou NULL se nao a vacina disponivel
 * Pré-condição: nenhuma
 * Pós-condição: vacina disponivel para ser aplicada
 */
DadosVacina* verificaEstoqueVacina(ListaVacinas *l){
    //printf("\nTipo da vacina: %s\nEstoque: %d\n",lista->dados.tipo,lista->dados.estoque);

    while(l != NULL && (l->dados.estoque == 0)){
        l = l->pprox;
    }

    if(l != NULL) return &l->dados;
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
 * Registra a vacinacao do habitante
 * Entrada: lista de vacinas, dados da vacina e habitante, e o cpf do habitante
 * Retorno: nenhum
 * Pré-condição: numero do cpf, listas preenchidas
 * Pós-condição: registra que o habitate foi vacinado
 */
void registrarVacinacao(char *cpf, ListaVacinas *listaV,DadosVacina *dadosVac, DadosHabitante *dadosH){

    printf("\nInsira uma data para a vacinacao: ");
    scanf("%s",dadosH->data_vacinacao);
    strcpy(dadosH->tipo_vacina, dadosVac->tipo);
    if(dadosH->dose == 0)
        dadosH->dose = 1;
    else if(dadosH->dose == 1)
            dadosH->dose = 2;

    // Diminui do estoque
    dadosVac->estoque--;

    listaV = alterarVacina(listaV, dadosVac, listaV->dados.tipo);

    //teste
    printf("\nAlteracao:\ntipo vacina H = %s\nestoque = %d\nH = %s\ndose = %d\n",dadosH->tipo_vacina, listaV->dados.estoque,dadosH->nome,dadosH->dose);
    printf("data = %s\n",dadosH->data_vacinacao);

}
/*
void inicializaDadosStructH(DadosHabitante dados){
    strcpy(dados.nome, "");
    dados.idade = 0;
   // strcpy(dados.sexo, "");
    strcpy(dados.rg, "");
    strcpy(dados.cpf, "");
    strcpy(dados.telefone, "");
    strcpy(dados.endereco, "");
    strcpy(dados.profissao, "");
    dados.prioridade = 0;
    strcpy(dados.data_vacinacao, "");
    strcpy(dados.tipo_vacina, "");
    dados.dose = 0;
}
*/
int main()
{

    // testes

    ListaHabitantes *lista;
    lista = malloc (sizeof (ListaHabitantes));

    char caminhoArq [300];
    strcpy(caminhoArq, "habitantes.txt");
    lista = lerArquivo(lista, caminhoArq);

    DadosHabitante *dados;
    dados = malloc(sizeof(DadosHabitante));
/**

    // consultar dados e imprimir
    char cpf[8];
    strcpy(cpf, "11111111111");
    dados = consultarHabitante(cpf, lista);
    printf ("%s \n", dados->cpf);

    //remiver um H
    printf ("H a remover %s \n", dados->nome);
    lista = removerHabitante("11111111111",lista);

    dados = consultarHabitante("11111111111", lista);
    if(dados->nome == NULL) printf("H n existe\n");
    else printf ("H encontrado: %s \n", dados->nome);

    dados = consultarHabitante("66666666666", lista);
    if(dados->nome == NULL) printf("H n existe\n");
    else printf ("H encontrado: %s \n", dados->nome);



    // Registro de vacinacao

    // Liberer grupo prioritario
    while(liberaGrupoPrioritario()); **/


    ListaVacinas *listaVac;
    listaVac = malloc(sizeof(ListaVacinas));

    DadosVacina *dadosVac;
    dadosVac = malloc(sizeof(DadosVacina));

    DadosVacina dadosV;

    //DadosHabitante dadosHH;



    // Inserir vacina

    // Testes
    strcpy(dadosV.tipo,"v1");
    dadosV.estoque = 12;

    listaVac = inserirVacina(listaVac, dadosV);
    if(listaVac == NULL) printf("\nErro ao inserir\n");

    strcpy(dadosV.tipo,"v2");
    dadosV.estoque = 3;

    listaVac = inserirVacina(listaVac, dadosV);
    if(listaVac == NULL) printf("\nErro ao inserir\n");

    strcpy(dadosV.tipo,"v3");
    dadosV.estoque = 0;

    listaVac = inserirVacina(listaVac, dadosV);
    if(listaVac == NULL) printf("\nErro ao inserir\n");

    char cpf[12];
    strcpy(cpf, "55555555555");


    //..


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

                /*** Veritfica se a vacina diponivel ***/
                dadosVac = verificaEstoqueVacina(listaVac);
                if(dadosVac == NULL){
                    printf("N˜ao e possıvel vacinar. Estoque zerado\n");

                }else{
                    //imprimeVacinas(listaVac);

                    // Registrar vacinacao

                    dados = consultarHabitante(cpf, lista);

                    registrarVacinacao(cpf,listaVac,dadosVac, dados);
                    printf("\nAlteracao:\ntipo = %s\nestoque = %d\nH = %s\ndose = %d\n",dadosVac->tipo, dadosVac->estoque,dados->nome,dados->dose);

                }

            }else{
                printf("\nHabitante ja vacinado\n");
            }
        }else{
            printf("\nO habitante nao pode ser vacinado porque seu grupo nao esta liberado para vacinacao\n");
        }
    }else
        printf("Habitante nao registrado\n");


    return 0;
}



