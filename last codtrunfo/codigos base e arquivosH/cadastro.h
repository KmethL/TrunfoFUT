#ifndef CADASTRO_H
#define CADASTRO_H

typedef struct {
    char nome[100];
    char nacionalidade[50];
    char clube[50];
    char posicao[20];
    int ritmo;
    int chute;
    int passe;
    int drible;
    int defesa;
    int fisico;
} Jogador;

void cadastrarJogadores(Jogador *jogadores, int *qtd);
void listarJogadores(Jogador *jogadores, int qtd);
void excluirJogador(Jogador *jogadores, int *qtd);

#endif
