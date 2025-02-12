#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cadastro.h"

#define MIN_CARTAS 32 //minde jogadores por partida

//GOATs: CR& e Messi
Jogador CR7 = {"Cristiano Ronaldo", "Portugal", "Real Madrid", "Atacante", 92, 92, 81, 91, 33, 80};
Jogador Messi = {"Lionel Messi", "Argentina", "Barcelona", "Atacante", 93, 88, 86, 95, 24, 62};

//Lista de rivalidades 
const char *rivalidades[][2] = {
    {"Flamengo", "Fluminense"},
    {"Corinthians", "Palmeiras"},
    {"Gremio", "Internacional"},
    {"Atletico Mineiro", "Cruzeiro"},
    {"Bahia", "Vitoria"},
    {"Boca Juniors", "River Plate"},
    {"Real Madrid", "Barcelona"},
    {"Atletico de Madrid", "Real Madrid"},
    {"Liverpool", "Manchester United"},
    {"Arsenal", "Tottenham Hotspur"},
    {"Manchester City", "Manchester United"},
    {"Milan", "Inter de Milao"},
    {"Bayern de Munique", "Borussia Dortmund"},
    {"Benfica", "Porto"}, {"Sporting", "Benfica"},
    {"Brasil", "Argentina"}, 
    {"Uruguai", "Argentina"}, 
    {"Espanha", "Portugal"},
    {"Inglaterra", "Alemanha"}, 
    {"Italia", "Franca"}
};
const int num_rivalidades = sizeof(rivalidades) / sizeof(rivalidades[0]);

//verificar se dois jogadores sao rivais
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

//funcao principal com menu
int main() {
    srand(time(NULL)); //gerador de numeros aleatorios
    Jogador *jogadores = NULL; //ponteiro para armazenar os jogadores dinamicamente
    int qtd = 0; //quantidade de jogadores cadastrados
    char opcao[10]; //rrmazena a opcao do usuario

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar jogador\n");
        printf("2. Listar jogadores\n");
        printf("3. Excluir jogador\n");
        printf("4. Iniciar partida\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        fgets(opcao, sizeof(opcao), stdin);

        switch (atoi(opcao)) {
            case 1:
                jogadores = realloc(jogadores, (qtd + 1) * sizeof(Jogador)); //realoca memoria para novo jogador
                if (jogadores == NULL) {
                    printf("Erro de alocacao de memoria!\n");
                    exit(1);
                }
                cadastrarJogadores(jogadores, &qtd);
                break;
            case 2:
                listarJogadores(jogadores, qtd);
                break;
            case 3:
                excluirJogador(jogadores, &qtd);
                break;
            case 4:
                if (qtd >= MIN_CARTAS) {
                    jogar(jogadores, qtd);
                } else {
                    printf("\nErro: A partida requer no minimo %d jogadores cadastrados.\n", MIN_CARTAS);
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

        //verifica condicao de vitoria: se um jogador ficar sem cartas, o jogo termina
        if (qtd == 0) {
            printf("O jogo terminou! Um jogador ficou sem cartas.\n");
            break;
        }
    } while (atoi(opcao) != 5);

    free(jogadores); //libera memoria alocada antes de sair
    return 0;
}
