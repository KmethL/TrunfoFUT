#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INICIAL 30

//função para ler uma string com controle de tamanho
void lestring(char texto[], int tamanho) {
    setbuf(stdin, NULL);
    fgets(texto, tamanho, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

//definição da estrutura JOGADOR
typedef struct {
    char Nomejogador[20];
    char Nacionalidade[20];
    char Clube[20];
    char POSICAO[20];
    int ritmo;
    int CHUTE;
    int PASSE;
    int DRIBLE;
    int DEFESA;
    int FISICO;
} JOGADOR;

//função para cadastrar novos jogadores
void cadastrar_jogadores() {
    FILE *arq = fopen("jogadores.dat", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    JOGADOR jogador;
    while (1) {
        printf("\nNome do jogador (ou 'fim' para encerrar):\n");
        lestring(jogador.Nomejogador, 20);
        if (strcmp(jogador.Nomejogador, "fim") == 0) {
            break;
        }

        printf("Nacionalidade:\n");
        lestring(jogador.Nacionalidade, 20);

        printf("Clube:\n");
        lestring(jogador.Clube, 20);

        printf("POSICAO (ZAGUEIRO, LATERAL, MEIA, ATACANTE):\n");
        lestring(jogador.POSICAO, 20);

        printf("DIGITE OS ATRIBUTOS DESSE JOGADOR\n");

        printf("ritmo:\n");
        scanf("%d", &jogador.ritmo);
        printf("CHUTE:\n");
        scanf("%d", &jogador.CHUTE);
        printf("PASSE:\n");
        scanf("%d", &jogador.PASSE);
        printf("DRIBLE:\n");
        scanf("%d", &jogador.DRIBLE);
        printf("DEFESA:\n");
        scanf("%d", &jogador.DEFESA);
        printf("FISICO:\n");
        scanf("%d", &jogador.FISICO);
        setbuf(stdin, NULL); // Limpa o buffer

        fwrite(&jogador, sizeof(JOGADOR), 1, arq);
    }
    fclose(arq);
}

//função para pesquisar jogadores por nome
void pesquisar_jogador() {
    FILE *arq = fopen("jogadores.dat", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char nome[20];
    printf("\nDigite o nome do jogador para pesquisar:\n");
    lestring(nome, 20);

    JOGADOR jogador;
    int encontrado = 0;

    while (fread(&jogador, sizeof(JOGADOR), 1, arq) == 1) {
        if (strcmp(jogador.Nomejogador, nome) == 0) {
            printf("\nJogador encontrado:\n");
            printf("Nome: %s, Nacionalidade: %s, Clube: %s, Posição: %s\n", 
                   jogador.Nomejogador, jogador.Nacionalidade, jogador.Clube, jogador.POSICAO);
            printf("ritmo: %d, CHUTE: %d, PASSE: %d, DRIBLE: %d, DEFESA: %d, FISICO: %d\n", 
                   jogador.ritmo, jogador.CHUTE, jogador.PASSE, jogador.DRIBLE, jogador.DEFESA, jogador.FISICO);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Jogador não encontrado.\n");
    }

    fclose(arq);
}

// Função para excluir um jogador pelo nome
void excluir_jogador() {
    FILE *arq = fopen("jogadores.dat", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arq);
        return;
    }

    char nome[20];
    printf("\nDigite o nome do jogador para excluir:\n");
    lestring(nome, 20);

    JOGADOR jogador;
    int encontrado = 0;

    while (fread(&jogador, sizeof(JOGADOR), 1, arq) == 1) {
        if (strcmp(jogador.Nomejogador, nome) != 0) {
            fwrite(&jogador, sizeof(JOGADOR), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq);
    fclose(temp);

    if (encontrado) {
        remove("jogadores.dat");
        rename("temp.dat", "jogadores.dat");
        printf("Jogador excluído com sucesso.\n");
    } else {
        remove("temp.dat");
        printf("Jogador nao encontrado.\n");
    }
}

// Função principal com menu
int main() {
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar novos jogadores\n");
        printf("2. Pesquisar jogador\n");
        printf("3. Excluir jogador\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL); // Limpa o buffer

        switch (opcao) {
            case 1:
                cadastrar_jogadores();
                break;
            case 2:
                pesquisar_jogador();
                break;
            case 3:
                excluir_jogador();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);
    return 0;
}