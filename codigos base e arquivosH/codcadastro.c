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

    printf("Ritmo: ");
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
    printf("Digite o numero do jogador a ser removido: ");
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

void exportarJogadores(Jogador *jogadores, int qtd) {
    FILE *file = fopen("jogadores_fifa.csv", "w");
    if (!file) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(file, "Nome,Nacionalidade,Clube,Posição,Ritmo,Chute,Passe,Drible,Defesa,Físico\n");

    for (int i = 0; i < qtd; i++) {
        fprintf(file, "%s,%s,%s,%s,%d,%d,%d,%d,%d,%d\n",
                jogadores[i].nome, jogadores[i].nacionalidade, jogadores[i].clube,
                jogadores[i].posicao, jogadores[i].ritmo, jogadores[i].chute,
                jogadores[i].passe, jogadores[i].drible, jogadores[i].defesa,
                jogadores[i].fisico);
    }

    fclose(file);
    printf("Dados exportados com sucesso para jogadores_fifa.csv.\n");
}

void importarJogadores(Jogador *jogadores, int *qtd) {
    FILE *file = fopen("jogadores_fifa.csv", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file); // Ignorar o cabeçalho

    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (*qtd >= 50) break;

        sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d",
               jogadores[*qtd].nome, jogadores[*qtd].nacionalidade, jogadores[*qtd].clube,
               jogadores[*qtd].posicao, &jogadores[*qtd].ritmo, &jogadores[*qtd].chute,
               &jogadores[*qtd].passe, &jogadores[*qtd].drible, &jogadores[*qtd].defesa,
               &jogadores[*qtd].fisico);

        (*qtd)++;
    }

    fclose(file);
    printf("Dados importados com sucesso.\n");
}

int main() {
    Jogador jogadores[50];
    int qtd = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Jogador\n");
        printf("2. Listar Jogadores\n");
        printf("3. Excluir Jogador\n");
        printf("4. Exportar Dados para CSV\n");
        printf("5. Importar Dados de CSV\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

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
                exportarJogadores(jogadores, qtd);
                break;
            case 5:
                importarJogadores(jogadores, &qtd);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
