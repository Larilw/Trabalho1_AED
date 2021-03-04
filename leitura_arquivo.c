#include "leitura_arquivo.h"
#include "habitantes.h"

void removerEspacos(char stringComEspaco[TAM_MAX_STR+9], char stringSemEspaco[TAM_MAX_STR]){
    int i;
    for(i = 1; i < strlen(stringComEspaco)+1; i++){
        stringSemEspaco[i-1] = stringComEspaco[i];
    }
}

void inserirEspacos(char linhaLida[TAM_MAX_STR], char linhaNova[TAM_MAX_STR+9]){
    int i, k = 1;
    linhaNova[0] = ' ';
    for(i = 0; i < strlen(linhaLida); i++){
        linhaNova[k++] = linhaLida[i];
        if(linhaLida[i] == ';'){
            linhaNova[k++] = ' ';
        }

    }
}

DadosHabitante separarDados(char *dados){
    char *aux, dadosEspacados[TAM_MAX_STR+9], auxSemEspacos[TAM_MAX_STR];
    inserirEspacos(dados, dadosEspacados);
    DadosHabitante habitante;
    aux = strtok(dadosEspacados, ";");
    removerEspacos(aux, auxSemEspacos);
    strcpy(habitante.nome, auxSemEspacos);
    aux = strtok(NULL, ";");
    habitante.idade = atoi(aux);
    aux = strtok(NULL, ";");
    habitante.sexo = aux[1];
    aux = strtok(NULL, ";");
    removerEspacos(aux, auxSemEspacos);
    strcpy(habitante.rg, auxSemEspacos);
    aux = strtok(NULL, ";");
    removerEspacos(aux, auxSemEspacos);
    strcpy(habitante.cpf, auxSemEspacos);
    aux = strtok(NULL, ";");
    removerEspacos(aux, auxSemEspacos);
    strcpy(habitante.telefone, auxSemEspacos);
    aux = strtok(NULL, ";");
    removerEspacos(aux, auxSemEspacos);
    strcpy(habitante.endereco, auxSemEspacos);
    aux = strtok(NULL, ";");
    removerEspacos(aux, auxSemEspacos);
    strcpy(habitante.profissao, auxSemEspacos);
    aux = strtok(NULL, ";");
    habitante.prioridade = atoi(aux);
    return habitante;
}

ListaHabitantes* lerArquivo(ListaHabitantes *l, char *caminhoArquivo){
    FILE *arq;
    DadosHabitante novoHabitante;
    char linhaLida[255];
    arq = fopen(caminhoArquivo, "r");
    if(arq != NULL){
        while(fgets(linhaLida, sizeof(linhaLida), arq) != NULL){
            novoHabitante = separarDados(linhaLida);
            //Checar Entradas do Habitante
            l = inserirHabitante(l, novoHabitante);
        }
    }
    return l;
}
/*
int main(){
    ListaHabitantes *lista;
    lista = malloc(sizeof(ListaHabitantes));
    char caminhoArq[255] = {"/home/larilw/Desktop/testeAED.txt"};
    char nova[300];
    char string[255] = {"Maria da Silva;70;F;123;11111111111;;;aposentada;2"};
    lista = lerArquivo(lista, caminhoArq);
    printf("%s\n", consultarHabitante("55555555555", lista)->endereco);
    return 0;
}*/