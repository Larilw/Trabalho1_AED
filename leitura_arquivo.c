#include "leitura_arquivo.h"
#include "habitantes.h"
#include "controleVacinas.h"

/**
 * Remove um espaço vazio do início de uma string
 * Entrada: string com espaço e string sem espaco
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: o espaço no início da string é removido
 */
void removerEspacos(char stringComEspaco[TAM_MAX_STR+9], char stringSemEspaco[TAM_MAX_STR]){
    int i;
    for(i = 1; i < strlen(stringComEspaco)+1; i++){
        stringSemEspaco[i-1] = stringComEspaco[i];
    }
}

/**
 * Insere um espaço no início de uma string e após cada ; presente na mesma 
 * Entrada: duas strings, uma recebida com espaços e uma a ser preenchida com os espaços faltantes
 * Retorno: nenhum
 * Pré-condição: nenhuma
 * Pós-condição: são adicionados espaços na string recebida
 */
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

/**
 * Separa uma string com os dados de um habitante e insere os mesmos nos campos de uma estrutura de habitante
 * Entrada: string com os dados do habitante
 * Retorno: dados do habitante
 * Pré-condição: nenhuma
 * Pós-condição: os dados são separados por tipo e inseridos na estrutura de habitante
 */
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
    strcpy(habitante.data_vacinacao, "");
    strcpy(habitante.tipo_vacina, "");
    habitante.dose = 0;

    return habitante;
}

/**
 * Realiza a leitura de um arquivo texto linha por linha e insere na lista os habitantes presentes no arquivo 
 * Entrada: lista e caminho do arquivo
 * Retorno: lista alterada
 * Pré-condição: nenhuma
 * Pós-condição: o arquivo é lido e os dados presentes nele são inseridos na lista  
 */
ListaHabitantes* lerArquivo(ListaHabitantes *l, char *caminhoArquivo){
    FILE *arq;
    DadosHabitante novoHabitante;
    char linhaLida[255];
    arq = fopen(caminhoArquivo, "r");
    if(arq != NULL){
        while(fgets(linhaLida, sizeof(linhaLida), arq) != NULL){
            novoHabitante = separarDados(linhaLida);
            if (!verificaHabitanteRegistrado(l, &novoHabitante, novoHabitante.cpf)) {
                l = inserirHabitante(l, novoHabitante);
                printf("Habitante de CPF %s cadastrado.\n", novoHabitante.cpf);
            }
            else {
                printf("Habitante de CPF %s nao pode ser cadastrado.\n", novoHabitante.cpf);
            }
        }
    }
    else printf("Arquivo nao encontrado.\n");
    return l;
}
