#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "partida.h"
#include "mecanicas.h"

int main() {
    // Criar um array de jogadores
    Jogador *jogadores = NULL;
    int qtdJogadores = 0;

    // Chamar a função para cadastrar jogadores
    cadastrarJogadores(&jogadores, &qtdJogadores);

    // Iniciar a partida
    jogar(jogadores, qtdJogadores);

    // Liberar a memória alocada para os jogadores
    free(jogadores);

    return 0;
}
