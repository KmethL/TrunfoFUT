# Variáveis
CC = gcc
CFLAGS = -Wall -std=c99
OBJ = main.o cadastro.o partida.o mecanicas.o
EXEC = jogoApp

# Alvo padrão (compila tudo)
all: $(EXEC)

# Como compilar o arquivo principal
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Como compilar main.o
main.o: main.c cadastro.h partida.h mecanicas.h
	$(CC) $(CFLAGS) -c main.c

# Como compilar cadastro.o
cadastro.o: cadastro.c cadastro.h
	$(CC) $(CFLAGS) -c cadastro.c

# Como compilar partida.o
partida.o: partida.c partida.h
	$(CC) $(CFLAGS) -c partida.c

# Como compilar mecanicas.o
mecanicas.o: mecanicas.c mecanicas.h
	$(CC) $(CFLAGS) -c mecanicas.c

# Limpar os arquivos compilados
clean:
	rm -f $(OBJ) $(EXEC)
