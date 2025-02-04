#include <stdio.h>
#include <string.h>
#include "cadastro.h"

// Função para cadastrar um novo jogador
void cadastrarJogadores(Jogador *jogadores, int *qtd) {
    if (*qtd >= 100) {
        printf("Limite de jogadores atingido!\n");
        return;
    }

    Jogador novo;
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);
    printf("Nacionalidade: ");
    scanf(" %[^\n]", novo.nacionalidade);
    printf("Clube: ");
    scanf(" %[^\n]", novo.clube);
    printf("Posição: ");
    scanf(" %[^\n]", novo.posicao);
    printf("Velocidade: ");
    scanf("%d", &novo.velocidade);
    printf("Chute: ");
    scanf("%d", &novo.chute);
    printf("Passe: ");
    scanf("%d", &novo.passe);
    printf("Drible: ");
    scanf("%d", &novo.drible);
    printf("Defesa: ");
    scanf("%d", &novo.defesa);
    printf("Físico: ");
    scanf("%d", &novo.fisico);

    jogadores[*qtd] = novo;
    (*qtd)++;
    printf("Jogador cadastrado com sucesso!\n");
}

// Função para listar todos os jogadores cadastrados
void listarJogadores(Jogador *jogadores, int qtd) {
    if (qtd == 0) {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s - %s - %s - %s | Vel: %d, Chute: %d, Passe: %d, Drible: %d, Defesa: %d, Físico: %d\n",
               i + 1, jogadores[i].nome, jogadores[i].nacionalidade, jogadores[i].clube, jogadores[i].posicao,
               jogadores[i].velocidade, jogadores[i].chute, jogadores[i].passe, jogadores[i].drible, jogadores[i].defesa, jogadores[i].fisico);
    }
}

// Função para excluir um jogador cadastrado
void excluirJogador(Jogador *jogadores, int *qtd) {
    if (*qtd == 0) {
        printf("Não há jogadores para excluir.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do jogador a ser excluído: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < *qtd; i++) {
        if (strcmp(jogadores[i].nome, nome) == 0) {
            for (int j = i; j < *qtd - 1; j++) {
                jogadores[j] = jogadores[j + 1];
            }
            (*qtd)--;
            printf("Jogador %s excluído com sucesso!\n", nome);
            return;
        }
    }
    printf("Jogador não encontrado.\n");
}
