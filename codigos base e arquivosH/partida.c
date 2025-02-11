#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cadastro.h"

void jogar(Jogador *jogadores, int qtd) {
    if (qtd < 10) {
        printf("É necessário pelo menos 10 jogadores cadastrados para iniciar a partida!\n");
        return;
    }
    
    srand(time(NULL));
    int jogadorHumano = rand() % 2; // Sorteia quem começa (0: humano, 1: computador)
    int atributoAnterior = -1; // Nenhum atributo foi escolhido ainda
    
    Jogador *timeHumano[11];
    Jogador *timeComputador[11];
    
    printf("Escolha uma formação (ex: 4-4-2, 3-5-2, 4-3-3): ");
    char formacao[10];
    fgets(formacao, sizeof(formacao), stdin);
    
    // Seleciona jogadores aleatoriamente para cada posição (exceto o GOAT)
    for (int i = 0; i < 10; i++) {
        timeHumano[i] = &jogadores[rand() % qtd];
        timeComputador[i] = &jogadores[rand() % qtd];
    }
    
    // Define o GOAT
    timeHumano[10] = &CR7;
    timeComputador[10] = &Messi;
    
    printf("Partida iniciada! Sorteando quem começa...\n");
    printf("%s começa!\n", jogadorHumano ? "Computador" : "Jogador");
    
    while (1) {
        printf("\n--- Nova Rodada ---\n");
        Jogador *jogadorAtual = jogadorHumano ? timeHumano[rand() % 11] : timeComputador[rand() % 11];
        printf("Seu jogador: %s\n", jogadorAtual->nome);
        
        int atributo;
        do {
            printf("Escolha um atributo para comparar:\n");
            printf("1 - Velocidade, 2 - Chute, 3 - Passe, 4 - Drible, 5 - Defesa, 6 - Físico\n");
            scanf("%d", &atributo);
        } while (atributo == atributoAnterior || atributo < 1 || atributo > 6);
        atributoAnterior = atributo;
        
        Jogador *adversario = jogadorHumano ? timeComputador[rand() % 11] : timeHumano[rand() % 11];
        printf("Comparando com o jogador adversário...\n");
        
        int valorJogador, valorAdversario;
        switch (atributo) {
            case 1: valorJogador = jogadorAtual->velocidade; valorAdversario = adversario->velocidade; break;
            case 2: valorJogador = jogadorAtual->chute; valorAdversario = adversario->chute; break;
            case 3: valorJogador = jogadorAtual->passe; valorAdversario = adversario->passe; break;
            case 4: valorJogador = jogadorAtual->drible; valorAdversario = adversario->drible; break;
            case 5: valorJogador = jogadorAtual->defesa; valorAdversario = adversario->defesa; break;
            case 6: valorJogador = jogadorAtual->fisico; valorAdversario = adversario->fisico; break;
        }
        
        printf("%s: %d vs %s: %d\n", jogadorAtual->nome, valorJogador, adversario->nome, valorAdversario);
        if (valorJogador > valorAdversario) {
            printf("Você venceu esta rodada!\n");
        } else if (valorJogador < valorAdversario) {
            printf("O computador venceu esta rodada!\n");
        } else {
            printf("Empate!\n");
        }
        
        jogadorHumano = !jogadorHumano; // Alterna turno
    }
}
