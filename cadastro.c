#ifndef CADASTRO_H
#define CADASTRO_H

typedef struct {
    char nome[50];
    char nacionalidade[30];
    char clube[30];
    char posicao[20];
    int velocidade;
    int chute;
    int passe;
    int drible;
    int defesa;
    int fisico;
} Jogador;

void cadastrarJogadores(Jogador *jogadores, int *qtd);
void listarJogadores(Jogador *jogadores, int qtd);
void excluirJogador(Jogador *jogadores, int *qtd);
void jogar(Jogador *jogadores, int qtd);

#endif