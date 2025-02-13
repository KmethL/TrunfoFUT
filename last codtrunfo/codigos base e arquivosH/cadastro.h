#ifndef JOGADOR_H 
#define JOGADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INICIAL 30

typedef struct {
    char *Nomejogador;
    char *Nacionalidade;
    char *Clube;
    char *POSICAO;
    int ritmo;
    int CHUTE;
    int PASSE;
    int DRIBLE;
    int DEFESA;
    int FISICO;
    char *HISTORIA;
} JOGADOR;

// Declaração das funções
void cadastrar_jogadores();
void importar_csv();
void pesquisar_jogador();
void excluir_jogador();
void exportar_csv();

#endif
