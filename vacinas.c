#include "vacinas.h"

/**
 * Insere uma vacina na cabeca da lista
 * Entrada: lista e dados da vacina a ser inserida
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: a vacina é inserida na lista
 */
ListaVacinas* inserirVacina(ListaVacinas *l, DadosVacina dadosVac){
    ListaVacinas* aux = (ListaVacinas*) malloc(sizeof(ListaVacinas));
    aux->dados.estoque = dadosVac.estoque;
    strcpy(aux->dados.tipo, dadosVac.tipo);
    aux->pprox = l;
    return aux;
}

/**
 * Limpa a lista de vacinas uma a uma
 * Entrada: lista
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: os elementos da lista são todos removidos
 */
void limparListaVacinas(ListaVacinas *l){
    ListaVacinas* aux = l;
    if(aux != NULL){
        l = l->pprox;
        free(aux);
    } 
}

/**
 * Consulta uma vacina da lista
 * Entrada: tipo da vacina a ser consultada e lista
 * Retorno: dados da vacina se ela for encontrada ou NULL caso contrário
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
DadosVacina* consultarVacina(ListaVacinas *l, char* tipoVacina){
    while(l != NULL && (strcmp(l->dados.tipo, tipoVacina) != 0)){
        l = l->pprox;
    }
    if(l != NULL) return &l->dados;
    return NULL;
}

/**
 * Altera os dados de uma vacina na lista
 * Entrada: tipo da vacina, lista e dados novos a serem inseridos na vacina
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: a vacina é alterada
 */
ListaVacinas* alterarVacina(ListaVacinas *l, DadosVacina *vac, char *tipoVac){
    DadosVacina *aux;
    aux = consultarVacina(l, tipoVac);
    strcpy(aux->tipo, vac->tipo);
    aux->estoque = vac->estoque;
    return l;
}

/**
 * Remove uma vacina da lista de vacinas
 * Entrada: tipo da vacina a ser removida e lista
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: elemento é removido da lista de vacinas
 */
ListaVacinas* removerVacina(char *tipoVac, ListaVacinas* l){
    ListaVacinas* ant = l;
    ListaVacinas* prox = l;
    while(prox != NULL && (strcmp(tipoVac, prox->dados.tipo) != 0)){
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

