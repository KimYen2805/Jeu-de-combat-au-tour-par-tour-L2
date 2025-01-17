all: bin/test bin/affichage bin/CDKA

OBJ = obj/joueur.o obj/ennemi.o obj/sort.o obj/objet.o obj/effet.o obj/noeud.o obj/combat.o obj/dialogue.o obj/jeu.o obj/graphe.o

bin/CDKA: ${OBJ} obj/mainCDKA.o
	g++ -g ${OBJ} obj/mainCDKA.o -o bin/CDKA

bin/test: ${OBJ} obj/mainTest.o
	g++ -g ${OBJ} obj/mainTest.o -o bin/test

bin/affichage: ${OBJ} obj/mainAffichage.o obj/affichage.o 
	g++ -g ${OBJ} obj/mainAffichage.o obj/affichage.o  -o bin/affichage -lSDL2 -lSDL2_image -lSDL2_ttf

obj/mainCDKA.o: src/mainCDKA.cpp src/jeu.h 
	g++ -g -Wall -c src/mainCDKA.cpp -o obj/mainCDKA.o

obj/mainTest.o: src/mainTest.cpp src/joueur.h src/ennemi.h 
	g++ -g -Wall -c src/mainTest.cpp -o obj/mainTest.o

obj/affichage.o: src/affichage.cpp src/affichage.h 
	g++ -g -Wall -c src/affichage.cpp -o obj/affichage.o

obj/mainAffichage.o: src/mainAffichage.cpp src/affichage.h
	g++ -g -Wall -c src/mainAffichage.cpp -o obj/mainAffichage.o 

obj/jeu.o: src/jeu.cpp src/jeu.h src/graphe.h
	g++ -g -Wall -c src/jeu.cpp -o obj/jeu.o

obj/graphe.o: src/dialogue.h src/combat.h src/graphe.h src/graphe.cpp
	g++ -g -Wall -c src/graphe.cpp -o obj/graphe.o 

obj/combat.o: src/combat.cpp src/combat.h src/noeud.h src/ennemi.cpp
	g++ -g -Wall -c src/combat.cpp -o obj/combat.o

obj/dialogue.o: src/dialogue.cpp src/dialogue.h src/noeud.h
	g++ -g -Wall -c src/dialogue.cpp -o obj/dialogue.o
	
obj/noeud.o: src/noeud.cpp src/noeud.h src/joueur.h
	g++ -g -Wall -c src/noeud.cpp -o obj/noeud.o

obj/joueur.o: src/joueur.cpp src/joueur.h src/sort.h src/objet.h
	g++ -g -Wall -c src/joueur.cpp -o obj/joueur.o

obj/ennemi.o: src/ennemi.cpp src/ennemi.h src/sort.h
	g++ -g -Wall -c src/ennemi.cpp -o obj/ennemi.o

obj/sort.o: src/sort.cpp src/effet.cpp src/sort.h src/effet.h
	g++ -g -Wall -c src/sort.cpp -o obj/sort.o

obj/objet.o: src/objet.cpp src/effet.cpp src/objet.h src/effet.h
	g++ -g -Wall -c src/objet.cpp -o obj/objet.o
	
obj/effet.o: src/effet.cpp src/effet.h
	g++ -g -Wall -c src/effet.cpp -o obj/effet.o

#doc: doc/doxyfile
  	#doxygen doc/doxyfile

clean:
	rm -f obj/*.o bin/* 

veryclean: clean
	rm -r bin/* doc/html doc/latex