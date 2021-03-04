#include "habitantes.h"

/**
 * Insere um habitante na cabeca da lista de habitantes
 * Entrada: lista e dados do habitante a serem inseridos
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: elemento é inserido na lista de habitantes
 */
ListaHabitantes* inserirHabitante(ListaHabitantes* l, DadosHabitante dados){
    ListaHabitantes* aux = (ListaHabitantes*) malloc(sizeof(ListaHabitantes));
    strcpy(aux->habitante.cpf, dados.cpf);
    strcpy(aux->habitante.data_vacinacao, dados.data_vacinacao);
    strcpy(aux->habitante.tipo_vacina, dados.tipo_vacina);
    strcpy(aux->habitante.telefone, dados.telefone);
    strcpy(aux->habitante.endereco, dados.endereco);
    strcpy(aux->habitante.rg, dados.rg);
    strcpy(aux->habitante.nome, dados.nome);
    strcpy(aux->habitante.profissao, dados.profissao);
    aux->habitante.idade = dados.idade;
    aux->habitante.sexo = dados.sexo;
    aux->habitante.prioridade = dados.prioridade;
    aux->habitante.dose = dados.dose;
    aux->pprox = l;
    return aux;
}

/**
 * Remove um habitante da lista de habitantes
 * Entrada: cpf do habitante a ser removido e lista
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: elemento é removido da lista de habitantes
 */
ListaHabitantes* removerHabitante(char *cpf, ListaHabitantes* l){
    ListaHabitantes* ant = l;
    ListaHabitantes* prox = l;
    while(prox != NULL && (strcmp(cpf, prox->habitante.cpf) != 0)){
        ant = prox;
        prox = prox->pprox;
    }
    if(prox != NULL){
        if(prox == l){
            l = l->pprox;
        }
        else
            ant->pprox = prox->pprox;
        free(prox);
    }
    return l;
}


/**
 * Consulta um habitante da lista
 * Entrada: cpf do habitante a ser consultado e lista
 * Retorno: dados do habitante se ele for encontrado ou NULL caso contrário
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
DadosHabitante* consultarHabitante(char *cpf, ListaHabitantes *l){
    while(l != NULL && (strcmp(cpf, l->habitante.cpf) != 0)){
        l = l->pprox;
    }
    if(l != NULL) return &l->habitante;
    return NULL;
}

/**
 * Altera os dados de um habitante na lista
 * Entrada: cpf do habitante, lista e dados novos a serem inseridos no habitante
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: o habitante é alterado
 */
ListaHabitantes* alterarHabitante(char *cpf, ListaHabitantes *l, DadosHabitante habitante){
    DadosHabitante *aux;
    aux = consultarHabitante(cpf, l);
    strcpy(aux->cpf, habitante.cpf);
    strcpy(aux->data_vacinacao, habitante.data_vacinacao);
    strcpy(aux->tipo_vacina, habitante.tipo_vacina);
    strcpy(aux->telefone, habitante.telefone);
    strcpy(aux->endereco, habitante.endereco);
    strcpy(aux->rg, habitante.rg);
    strcpy(aux->nome, habitante.nome);
    strcpy(aux->profissao, habitante.profissao);
    aux->idade = habitante.idade;
    aux->sexo = habitante.sexo;
    aux->prioridade = habitante.prioridade;
    aux->dose = habitante.dose;
    return l;
}
