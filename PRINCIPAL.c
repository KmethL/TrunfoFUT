#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cadastro.h"

#define MAX_JOGADORES 100

// GOATs: Cristiano Ronaldo e Messi
Jogador CR7 = {"Cristiano Ronaldo", "Portugal", "Real Madrid", "Atacante", 92, 92, 81, 91, 33, 80};
Jogador Messi = {"Lionel Messi", "Argentina", "Barcelona", "Atacante", 93, 88, 86, 95, 24, 62};

// Lista de rivalidades (clubes e seleções)
const char *rivalidades[][2] = {
    {"Flamengo", "Fluminense"}, {"Corinthians", "Palmeiras"}, {"Grêmio", "Internacional"},
    {"Atlético Mineiro", "Cruzeiro"}, {"Bahia", "Vitória"}, {"Boca Juniors", "River Plate"},
    {"Real Madrid", "Barcelona"}, {"Atlético de Madrid", "Real Madrid"},
    {"Liverpool", "Manchester United"}, {"Arsenal", "Tottenham Hotspur"},
    {"Manchester City", "Manchester United"}, {"Milan", "Inter de Milão"},
    {"Bayern de Munique", "Borussia Dortmund"}, {"Benfica", "Porto"}, {"Sporting", "Benfica"},
    {"Brasil", "Argentina"}, {"Uruguai", "Argentina"}, {"Espanha", "Portugal"},
    {"Inglaterra", "Alemanha"}, {"Itália", "França"}
};
const int num_rivalidades = sizeof(rivalidades) / sizeof(rivalidades[0]);

// Função para verificar se dois jogadores são rivais
int saoRivais(Jogador j1, Jogador j2) {
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

// Função principal com menu
int main() {
    srand(time(NULL));
    Jogador jogadores[MAX_JOGADORES];
    int qtd = 0;
    char opcao[10];
    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar jogador\n");
        printf("2. Listar jogadores\n");
        printf("3. Excluir jogador\n");
        printf("4. Iniciar partida\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        fgets(opcao, sizeof(opcao), stdin);
        switch (atoi(opcao)) {
            case 1:
                cadastrarJogadores(jogadores, &qtd);
                break;
            case 2:
                listarJogadores(jogadores, qtd);
                break;
            case 3:
                excluirJogador(jogadores, &qtd);
                break;
            case 4:
                jogar(jogadores, qtd);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (atoi(opcao) != 5);
    return 0;
}
