#include "vacinas.h"

ListaVacinas* inserirVacina(ListaVacinas *l, DadosVacina dadosVac){
    ListaVacinas* aux = (ListaVacinas*) malloc(sizeof(ListaVacinas));
    aux->dados.estoque = dadosVac.estoque;
    strcpy(aux->dados.tipo, dadosVac.tipo);
    aux->pprox = l;
    return aux;
}

void limparListaVacinas(ListaVacinas *l){
    ListaVacinas* aux = l;
    if(aux != NULL){
        l = l->pprox;
        free(aux);
    } 
}

DadosVacina* consultarVacina(ListaVacinas *l, char* tipoVacina){
    while(l != NULL && (strcmp(l->dados.tipo, tipoVacina) != 0)){
        l = l->pprox;
    }
    if(l != NULL) return &l->dados;
    return NULL;
}

ListaVacinas* alterarVacina(ListaVacinas *l, DadosVacina *vac, char *tipoVac){
    DadosVacina *aux;
    aux = consultarVacina(l, tipoVac);
    strcpy(aux->tipo, vac->tipo);
    aux->estoque = vac->estoque;
    return l;
}
