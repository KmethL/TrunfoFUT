#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"



// Lista de rivalidades (clubes e seleções)
    char *rivalidades[][2] = {
    {"Flamengo", "Fluminense"}, {"Corinthians", "Palmeiras"}, {"Gremio", "Internacional"},
    {"Atletico Mineiro", "Cruzeiro"}, {"Bahia", "Vitoria"}, {"Boca Juniors", "River Plate"},
    {"Real Madrid", "Barcelona"}, {"Atletico de Madrid", "Real Madrid"},
    {"Liverpool", "Manchester United"}, {"Arsenal", "Tottenham Hotspur"},
    {"Manchester City", "Manchester United"}, {"Milan", "Inter de Milão"},
    {"Bayern de Munique", "Borussia Dortmund"}, {"Benfica", "Porto"}, {"Sporting", "Benfica"},
    {"Brasil", "Argentina"}, {"Uruguai", "Argentina"}, {"Espanha", "Portugal"},
    {"Inglaterra", "Alemanha"}, {"Itália", "França"}
};
    int num_rivalidades = sizeof(rivalidades) / sizeof(rivalidades[0]);

// Função para verificar se dois jogadores são rivais
jogador =JOGADOR;

int saoRivais(jogador j1, jogador j2) {
    for (int i = 0; i < num_rivalidades; i++) {
        if ((strcmp(j1.clube, rivalidades[i][0]) == 0 && strcmp(j2.clube, rivalidades[i][1]) == 0) ||
            (strcmp(j1.clube, rivalidades[i][1]) == 0 && strcmp(j2.clube, rivalidades[i][0]) == 0) ||
            (strcmp(j1.nacionalidade, rivalidades[i][0]) == 0 && strcmp(j2.nacionalidade, rivalidades[i][1]) == 0) ||
            (strcmp(j1.nacionalidade, rivalidades[i][1]) == 0 && strcmp(j2.nacionalidade, rivalidades[i][0]) == 0)) {
            return 1;
        }
    }
    return 0;
}
