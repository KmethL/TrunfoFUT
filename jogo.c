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

// Função para jogar com mecânica de GOATs e rivais
void jogar(Jogador *jogadores, int qtd) {
    if (qtd < 10) {
        printf("São necessários pelo menos 10 jogadores para iniciar uma partida além dos GOATs!\n");
        return;
    }
    
    Jogador time1[11], time2[11];
    time1[0] = CR7;
    time2[0] = Messi;
    
    int usados[qtd];
    memset(usados, 0, sizeof(usados));
    
    for (int i = 1; i < 11; i++) {
        int idx;
        do { idx = rand() % qtd; } while (usados[idx]);
        usados[idx] = 1;
        time1[i] = jogadores[idx];
        
        do { idx = rand() % qtd; } while (usados[idx]);
        usados[idx] = 1;
        time2[i] = jogadores[idx];
    }
    
    printf("Partida entre Time CR7 e Time Messi!\n");
    
    int pontos1 = 0, pontos2 = 0;
    for (int i = 0; i < 11; i++) {
        if (saoRivais(time1[i], time2[i])) {
            int soma1 = time1[i].velocidade + time1[i].chute + time1[i].passe +
                        time1[i].drible + time1[i].defesa + time1[i].fisico;
            int soma2 = time2[i].velocidade + time2[i].chute + time2[i].passe +
                        time2[i].drible + time2[i].defesa + time2[i].fisico;
            if (soma1 > soma2) pontos1++;
            else if (soma2 > soma1) pontos2++;
        } else {
            int atributo = rand() % 6;
            int val1 = ((int*)&time1[i].velocidade)[atributo];
            int val2 = ((int*)&time2[i].velocidade)[atributo];
            if (val1 > val2) pontos1++;
            else if (val2 > val1) pontos2++;
        }
    }
    
    printf("Placar final: Time CR7 %d x %d Time Messi\n", pontos1, pontos2);
    if (pontos1 > pontos2) printf("Time CR7 venceu!\n");
    else if (pontos2 > pontos1) printf("Time Messi venceu!\n");
    else printf("Empate!\n");
}

// Função principal com menu
int main() {
    srand(time(NULL));
    Jogador jogadores[MAX_JOGADORES];
    int qtd = 0;
    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar jogador\n");
        printf("2. Listar jogadores\n");
        printf("3. Excluir jogador\n");
        printf("4. Iniciar partida\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
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
    } while (opcao != 5);
    return 0;
}
