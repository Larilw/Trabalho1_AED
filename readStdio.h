#ifndef TRABALHO_1_READSTDIO_H
#define TRABALHO_1_READSTDIO_H

#include "readStdio.h"
#include "constantes.h"
#include "habitantes.h"
#include "vacinas.h"
#include "relatorio.h"

/**
 * Faz a leitura de um inteiro
 * Entrada: nenhuma
 * Retorno: n�mero inteiro
 * Pr�-condi��o: nenhuma
 * P�s-condi��o: nenhuma
 */
int LerInteiro ();

/**
 * Faz a leitura de inteiros entre um intervalo
 * entrada dois extremos do intervalo
 * returno Retorna um inteiro caso esteja dentro do intervalo
 * Pr�-condi��o: nenhuma
 * P�s-condi��o: nenhuma
 */
int LerIntervaloInteiro (int numA, int numB);

/**
 * Faz a leitura de uma string
 * entrada string de destino e inteiro para demarcar obrigatoriedade de preenchimento
 * returno Retorna flag 1 caso string esteja vazia
 * Pr�-condi��o: nenhuma
 * P�s-condi��o: str preenchida com entrada do teclado
 */
int LerString (char * str, int obrigatorio);

/**
 * Limpa o buffer entrada do teclado at� encontrar nova linha
 * Entrada: nenhuma
 * Returno: nenhum
 * Pr�-condi��o: nenhuma
 * P�s-condi��o: nenhuma
 */
void LimpaBuffer ();

/**
 * Faz a leitura de um char
 * entrada nenhuma
 * returno caractere
 * Pr�-condi��o: nenhuma
 * P�s-condi��o: nenhuma
 */
char LerChar ();

/**
 * Faz a leitura de dados do habitante
 * Entrada: struct de dados do habitante e lista de habitantes
 * returno struct de dados do habitante preenchida
 * Pr�-condi��o: nenhuma
 * P�s-condi��o: nenhuma
 */
DadosHabitante *LerHabitante(DadosHabitante *dados, ListaHabitantes *listaHabitante);

/**
 * Faz a leitura de dados de uma vacina
 * Entrada: struct de dados da vacinas
 * returno struct de dados da vacina preenchida
 * Pr�-condi��o: nenhuma
 * P�s-condi��o: nenhuma
 */
DadosVacina * LerVacina (DadosVacina *dados);

/**
 * Faz a leitura de estoque de uma vacina
 * Entrada: struct de dados da vacinas
 * returno: struct de dados da vacina com novo estoque
 * Pr�-condi��o: nenhuma
 * P�s-condi��o: nenhuma
 */
DadosVacina * LerVacinaEstoque (DadosVacina *dados);

#endif //TRABALHO_1_READSTDIO_H
