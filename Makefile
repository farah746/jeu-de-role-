# Nom de l'exécutable à produire
TARGET = mon_programme

# Compilateur C++
CC = g++

# Options de compilation
CFLAGS = -std=c++11 -Wall

# Chemin vers les fichiers d'en-tête de SFML
SFML_INCLUDE = -I/path/to/SFML/include

# Chemins vers les bibliothèques SFML (ajustez-les en fonction de votre installation)
SFML_LIBS = -L/path/to/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

# Listez tous vos fichiers source
SOURCES = main.cpp Bullet.cpp Enemy.cpp Bouton.cpp Personne.cpp Terrain.cpp

# Obtenez une liste des fichiers objets à partir des fichiers source
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(SFML_LIBS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) $(SFML_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
