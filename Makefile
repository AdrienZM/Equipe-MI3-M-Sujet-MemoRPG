# Nom de l'exécutable
TARGET = JeuAventure

# Compilateur
CC = gcc

# Options de compilation (-Wall pour les avertissements, -g pour le debug)
CFLAGS = -Wall -Wextra -g

# Liste des fichiers sources
SRCS = Programme(1).c Fonctions.c

# Liste des fichiers objets (générée automatiquement à partir des SRCS)
OBJS = $(SRCS:.c=.o)

# Règle par défaut : compile le projet
all: $(TARGET)

# Liaison des objets pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation des fichiers sources en fichiers objets
%.o: %.c structure.h Fonctions.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers temporaires
clean:
	rm -f $(OBJS) $(TARGET)

# Nettoyage plus profond
fclean: clean
	rm -f Game_History.txt

# Recompiler de zéro
re: fclean all

.PHONY: all clean fclean re
