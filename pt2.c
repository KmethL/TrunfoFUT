#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

#define MAX_JOGADORES 100

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarJogadores(Jogador *jogadores, int *qtd) {
    if (*qtd >= MAX_JOGADORES) {
        printf("Limite de jogadores atingido!\n");
        return;
    }

    printf("Nome do jogador: ");
    fgets(jogadores[*qtd].nome, sizeof(jogadores[*qtd].nome), stdin);
    strtok(jogadores[*qtd].nome, "\n");

    printf("Nacionalidade: ");
    fgets(jogadores[*qtd].nacionalidade, sizeof(jogadores[*qtd].nacionalidade), stdin);
    strtok(jogadores[*qtd].nacionalidade, "\n");

    printf("Clube: ");
    fgets(jogadores[*qtd].clube, sizeof(jogadores[*qtd].clube), stdin);
    strtok(jogadores[*qtd].clube, "\n");

    printf("Posição: ");
    fgets(jogadores[*qtd].posicao, sizeof(jogadores[*qtd].posicao), stdin);
    strtok(jogadores[*qtd].posicao, "\n");

    printf("Velocidade: ");
    scanf("%d", &jogadores[*qtd].velocidade);
    printf("Chute: ");
    scanf("%d", &jogadores[*qtd].chute);
    printf("Passe: ");
    scanf("%d", &jogadores[*qtd].passe);
    printf("Drible: ");
    scanf("%d", &jogadores[*qtd].drible);
    printf("Defesa: ");
    scanf("%d", &jogadores[*qtd].defesa);
    printf("Físico: ");
    scanf("%d", &jogadores[*qtd].fisico);

    limparBuffer();
    (*qtd)++;
}

void listarJogadores(Jogador *jogadores, int qtd) {
    if (qtd == 0) {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }
    printf("\nLista de jogadores:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d - %s (%s, %s, %s)\n", i + 1, jogadores[i].nome, jogadores[i].nacionalidade, jogadores[i].clube, jogadores[i].posicao);
    }
}

void excluirJogador(Jogador *jogadores, int *qtd) {
    if (*qtd == 0) {
        printf("Nenhum jogador para excluir.\n");
        return;
    }
    listarJogadores(jogadores, *qtd);
    int id;
    printf("Digite o número do jogador a ser removido: ");
    scanf("%d", &id);
    limparBuffer();
    if (id < 1 || id > *qtd) {
        printf("Número inválido.\n");
        return;
    }
    for (int i = id - 1; i < *qtd - 1; i++) {
        jogadores[i] = jogadores[i + 1];
    }
    (*qtd)--;
    printf("Jogador removido com sucesso!\n");
}
