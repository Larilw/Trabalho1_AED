#include <stdio.h>

#include "Interface.h"
#include "readStdio.h"
#include "habitantes.h"
#include "constantes.h"
#include "leitura_arquivo.h"

int main()
{
    ListaHabitantes *habitantes = NULL;
    ListaVacinas *vacinas = NULL;
    int grupoPrioritario = 5;

    printf("--------------------------------------------------------------------------------\n"
           "        .',         _____                          _           _                     \n"
           "         |         / ____|                        (_)         | |                    \n"
           "         |        | |  __  ___ _ __ ___ _ __   ___ _  __ _  __| | ___  _ __          \n"
           "        _|_       | | |_ |/ _ \\ '__/ _ \\ '_ \\ / __| |/ _` |/ _` |/ _ \\| '__|     \n"
           "     __|___|__    | |__| |  __/ | |  __/ | | | (__| | (_| | (_| | (_) | |            \n"
           "    | _______ |    \\_____|\\___|_|  \\___|_| |_|\\___|_|\\__,_|\\__,_|\\___/|_|     \n"
           "    ||_______||                                                                      \n"
           "    ||_ |||  ||                                                                      \n"
           "    ||_ |||  ||       ___     __      __                             \n"
           "    ||_ |||  ||       | |     \\ \\    / /        (_)                            \n"
           "    ||_ |||  ||     __| | ___  \\ \\  / /__ _  ___ _ _ __   __ _  ___ __ _  ___  \n"
           "    ||_ |||  ||    / _` |/ _ \\  \\ \\/ // _` |/ __| | '_ \\ / _` |/ __/ _` |/ _ \\  \n"
           "   _||__|||__||_  | (_| |  __/   \\  /| (_| | (__| | | | | (_| | (_| (_| | (_) | \n"
           "  (_____|||_____)  \\__,_|\\___|    \\/  \\__,_|\\___|_|_| |_|\\__,_|\\  _\\__,_|\\___/ \n"
           "       _|||_                                                    )_)            \n"
           "      |_____|                                                                         \n"
           "--------------------------------------------------------------------------------\n");
    //printf("Pressione uma tecla para continuar...\n");
    //getchar();

    DadosVacina testeVacina;

    habitantes = lerArquivo(habitantes, "habitantes.txt");

    strcpy(testeVacina.tipo, "vac");
    testeVacina.estoque = 100;
    vacinas = inserirVacina(vacinas, testeVacina);

    MenuPrincipal(habitantes, vacinas, &grupoPrioritario);

    limparListaVacinas(vacinas);

    PrintMessage("Encerrando programa", 'c', 1 , 1);
    printf("Pressione uma tecla para continuar...\n");
    getchar();

    return 0;
}
