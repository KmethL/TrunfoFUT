#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarJogadores(Jogador *jogadores, int *qtd) {
    if (*qtd >= 50) {
        printf("Limite de jogadores atingido!\n");
        return;
    }

    printf("Nome do jogador: ");
    fgets(jogadores[*qtd].nome, sizeof(jogadores[*qtd].nome), stdin);
    jogadores[*qtd].nome[strcspn(jogadores[*qtd].nome, "\n")] = '\0';

    printf("Nacionalidade: ");
    fgets(jogadores[*qtd].nacionalidade, sizeof(jogadores[*qtd].nacionalidade), stdin);
    jogadores[*qtd].nacionalidade[strcspn(jogadores[*qtd].nacionalidade, "\n")] = '\0';

    printf("Clube: ");
    fgets(jogadores[*qtd].clube, sizeof(jogadores[*qtd].clube), stdin);
    jogadores[*qtd].clube[strcspn(jogadores[*qtd].clube, "\n")] = '\0';

    printf("Posição: ");
    fgets(jogadores[*qtd].posicao, sizeof(jogadores[*qtd].posicao), stdin);
    jogadores[*qtd].posicao[strcspn(jogadores[*qtd].posicao, "\n")] = '\0';

    printf("ritmo: ");
    scanf("%d", &jogadores[*qtd].ritmo);
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

    limparBuffer(); // Evita problemas com fgets após scanf()
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
