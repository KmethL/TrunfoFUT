#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INICIAL 30

void lestring(char texto[], int tamanho) {
    setbuf(stdin, NULL);
    fgets(texto, tamanho, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

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

void cadastrar_jogadores() {
    FILE *arq = fopen("jogadores.csv", "a");
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
        
        int posicao;
        do {
            printf("Escolha a POSICAO:\n");
            printf("1 - ZAGUEIRO\n2 - LATERAL\n3 - MEIA\n4 - ATACANTE\n");
            scanf("%d", &posicao);
            setbuf(stdin, NULL);

            switch (posicao) {
                case 1: strcpy(jogador.POSICAO, "ZAGUEIRO"); break;
                case 2: strcpy(jogador.POSICAO, "LATERAL"); break;
                case 3: strcpy(jogador.POSICAO, "MEIA"); break;
                case 4: strcpy(jogador.POSICAO, "ATACANTE"); break;
                default: printf("Opcao invalida. Tente novamente.\n");
            }
        } while (posicao < 1 || posicao > 4);

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
        setbuf(stdin, NULL);

        fprintf(arq, "%s,%s,%s,%s,%d,%d,%d,%d,%d,%d\n",
                jogador.Nomejogador, jogador.Nacionalidade, jogador.Clube, jogador.POSICAO,
                jogador.ritmo, jogador.CHUTE, jogador.PASSE, jogador.DRIBLE, jogador.DEFESA, jogador.FISICO);
    }
    fclose(arq);
}

void importar_csv() {
    FILE *arq = fopen("jogadores.csv", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nJogadores cadastrados:\n");
    char linha[200];
    while (fgets(linha, 200, arq)) {
        printf("%s", linha);
    }
    fclose(arq);
}

void pesquisar_jogador() {
    FILE *arq = fopen("jogadores.csv", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char nome[20];
    printf("\nDigite o nome do jogador para pesquisar:\n");
    lestring(nome, 20);

    char linha[200];
    int encontrado = 0;
    while (fgets(linha, 200, arq)) {
        if (strstr(linha, nome) != NULL) {
            printf("%s", linha);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Jogador nao encontrado.\n");
    }
    fclose(arq);
}

void excluir_jogador() {
    FILE *arq = fopen("jogadores.csv", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arq);
        return;
    }

    char nome[20];
    printf("\nDigite o nome do jogador para excluir:\n");
    lestring(nome, 20);

    char linha[200];
    int encontrado = 0;

    while (fgets(linha, 200, arq)) {
        if (strstr(linha, nome) == NULL) {
            fprintf(temp, "%s", linha);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq);
    fclose(temp);

    if (encontrado) {
        remove("jogadores.csv");
        rename("temp.csv", "jogadores.csv");
        printf("Jogador excluído com sucesso.\n");
    } else {
        remove("temp.csv");
        printf("Jogador nao encontrado.\n");
    }
}

void exportar_csv() {
    FILE *arq = fopen("jogadores.csv", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *exp = fopen("exportados.csv", "w");
    if (exp == NULL) {
        printf("Erro ao criar arquivo exportado.\n");
        fclose(arq);
        return;
    }

    char linha[200];
    while (fgets(linha, 200, arq)) {
        fprintf(exp, "%s", linha);
    }
    fclose(arq);
    fclose(exp);
    printf("Arquivo exportado com sucesso!\n");
}

int main() {
    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar novos jogadores\n");
        printf("2. Importar jogadores do CSV\n");
        printf("3. Exportar jogadores para CSV\n");
        printf("4. Pesquisar jogador\n");
        printf("5. Excluir jogador\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao) {
            case 1: cadastrar_jogadores(); break;
            case 2: importar_csv(); break;
            case 3: exportar_csv(); break;
            case 4: pesquisar_jogador(); break;
            case 5: excluir_jogador(); break;
            case 6: printf("Saindo do programa...\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);
    return 0;
}
