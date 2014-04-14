#include "travail4.h"

#include <iostream>
#include <malloc.h>

namespace {
	int score = 0;
	int objetsAlloues = 0;
	int objetsAllouesDebut = 0;
	int nombreAllocations = 0;
	int nombreAllocationsDebut = 0;
}

void debuteQuestion(const char* question) {
	std::cout << question << std::endl;
}

bool verifie(const char* message, bool correct) {
	std::cout << "  " << message;
	if(correct)
		std::cout << ": correct" << std::endl;
	else
		std::cout << ": incorrect" << std::endl;
	return correct;
}

void valideQuestion(int scoreQuestion, bool correct) {
	if(correct) {
		std::cout << "  " << scoreQuestion << " points" << std::endl << std::endl;
		score += scoreQuestion;
	}
	else
		std::cout << "  " << 0 << " points" << std::endl << std::endl;
}

void* operator new(size_t size) {
	nombreAllocations++;
	objetsAlloues++;
	return malloc(size);
}

void* operator new[](size_t size) {
	nombreAllocations++;
	objetsAlloues++;
	return malloc(size);
}

void operator delete(void* ptr) {
	free(ptr);
	objetsAlloues--;
}

void operator delete[](void* ptr) {
	free(ptr);
	objetsAlloues--;
}

void resetAllocation() {
	objetsAllouesDebut = objetsAlloues;
	nombreAllocationsDebut = nombreAllocations;
}

int deltaAllocation() {
	return objetsAlloues - objetsAllouesDebut;
}

int deltaNombreAllocations() {
	return nombreAllocations - nombreAllocationsDebut;
}

int main(int argc, char** argv) {
	int noeudsArbreComplexe[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	int nombreNoeudsArbreComplexe = 9;

	{
		ArbreBinaire arbre;

		debuteQuestion("Un arbre binaire vide");
		valideQuestion(1,
			verifie("a une hauteur de 0", arbre.Hauteur() == 0)
		);
	}

	{
		ArbreBinaire arbre;
		arbre.Insere(2);
		arbre.Insere(1);
		arbre.Insere(3);

		debuteQuestion("Un arbre binaire trie, balance et complet contenant 1, 2 et 3");

		valideQuestion(1,
			verifie("a une hauteur de 2", arbre.Hauteur() == 2)
		);

		valideQuestion(1,
			verifie("contient l'element 1", arbre.Contient(1)) &&
			verifie("contient l'element 2", arbre.Contient(2)) &&
			verifie("contient l'element 3", arbre.Contient(3))
		);
	}

	{
		ArbreBinaire arbre;
		arbre.Insere(2);
		arbre.Insere(1);
		arbre.Insere(3);

		debuteQuestion("Un arbre binaire trie, balance et complet contenant 1, 2 et 3, et dont on supprime la valeur 1");

		arbre.Supprime(1);

		valideQuestion(1,
			verifie("a une hauteur de 2", arbre.Hauteur() == 2) &&
			verifie("ne contient pas l'element 1", !arbre.Contient(1)) &&
			verifie("contient l'element 2", arbre.Contient(2)) &&
			verifie("contient l'element 3", arbre.Contient(3))
		);
	}

	{
		ArbreBinaire arbre;
		arbre.Insere(2);
		arbre.Insere(1);
		arbre.Insere(3);

		debuteQuestion("Un arbre binaire trie, balance et complet contenant 1, 2 et 3, et dont on supprime la racine");

		arbre.Supprime(2);

		valideQuestion(1,
			verifie("a une hauteur de 2", arbre.Hauteur() == 2) &&
			verifie("contient l'element 1", arbre.Contient(1)) &&
			verifie("ne contient pas l'element 2", !arbre.Contient(2)) &&
			verifie("contient l'element 3", arbre.Contient(3))
		);
	}

	{
		ArbreBinaire arbre;
		for(int i = 0; i < nombreNoeudsArbreComplexe; ++i)
			arbre.Insere(noeudsArbreComplexe[i]);

		debuteQuestion("Un arbre binaire complexe, dont on supprime le noeud 6");

		arbre.Supprime(6);
		
		valideQuestion(1,
			verifie("a une hauteur de 4", arbre.Hauteur() == 4) &&
			verifie("ne contient pas l'element 6", !arbre.Contient(6)) &&
			verifie("contient l'element 1", arbre.Contient(1)) &&
			verifie("contient l'element 4", arbre.Contient(4)) &&
			verifie("contient l'element 7", arbre.Contient(7)) &&
			verifie("contient l'element 3", arbre.Contient(3)) &&
			verifie("contient l'element 13", arbre.Contient(13)) &&
			verifie("contient l'element 14", arbre.Contient(14)) &&
			verifie("contient l'element 10", arbre.Contient(10)) &&
			verifie("contient l'element 8", arbre.Contient(8))
		);

		debuteQuestion("Et si on supprime le noeud 3");

		arbre.Supprime(3);

		valideQuestion(1,
			verifie("ne contient pas l'element 6", !arbre.Contient(6)) &&
			verifie("ne contient pas l'element 3", !arbre.Contient(3)) &&
			verifie("contient l'element 1", arbre.Contient(1)) &&
			verifie("contient l'element 4", arbre.Contient(4)) &&
			verifie("contient l'element 7", arbre.Contient(7)) &&
			verifie("contient l'element 13", arbre.Contient(13)) &&
			verifie("contient l'element 14", arbre.Contient(14)) &&
			verifie("contient l'element 10", arbre.Contient(10)) &&
			verifie("contient l'element 8", arbre.Contient(8))
		);

	}

	{
		ArbreBinaire arbre;
		for(int i = 0; i < nombreNoeudsArbreComplexe; ++i)
			arbre.Insere(noeudsArbreComplexe[i]);

		debuteQuestion("Un arbre binaire complexe");
		
		valideQuestion(1,
			verifie("possede un minimum de 1", arbre.Minimum() == 1)
		);
		
		valideQuestion(1,
			verifie("possede un maximum de 14", arbre.Maximum() == 14)
		);

		int valeursEnLargeur[12];
		int valeursPrefixe[12];
		int valeursPostfixe[12];
		int valeursEnOrdre[12];
		int valeursCorrectesEnLargeur[] = {8,3,10,1,6,14,4,7,13};
		int valeursCorrectesPrefixe[] = {8,3,1,6,4,7,10,14,13};
		int valeursCorrectesPostfixe[] = {1,4,7,6,3,13,14,10,8};
		int valeursCorrectesEnOrdre[] = {1,3,4,6,7,8,10,13,14};
		bool correct;

		arbre.ParcoursEnLargeur(valeursEnLargeur);
		correct = true;
		for(int i = 0; i < nombreNoeudsArbreComplexe; ++i) {
			if(valeursEnLargeur[i] != valeursCorrectesEnLargeur[i]) {
				correct = false;
				break;
			}
		}
		valideQuestion(1,
			verifie("est parcouru en largeur correctement", correct)
		);

		arbre.ParcoursPrefixe(valeursPrefixe);
		correct = true;
		for(int i = 0; i < nombreNoeudsArbreComplexe; ++i) {
			if(valeursPrefixe[i] != valeursCorrectesPrefixe[i]) {
				correct = false;
				break;
			}
		}
		valideQuestion(1,
			verifie("est parcouru en prefixe correctement", correct)
		);

		arbre.ParcoursPostfixe(valeursPostfixe);
		correct = true;
		for(int i = 0; i < nombreNoeudsArbreComplexe; ++i) {
			if(valeursPostfixe[i] != valeursCorrectesPostfixe[i]) {
				correct = false;
				break;
			}
		}
		valideQuestion(1,
			verifie("est parcouru en postfixe correctement", correct)
		);

		arbre.ParcoursEnOrdre(valeursEnOrdre);
		correct = true;
		for(int i = 0; i < nombreNoeudsArbreComplexe; ++i) {
			if(valeursEnOrdre[i] != valeursCorrectesEnOrdre[i]) {
				correct = false;
				break;
			}
		}
		valideQuestion(1,
			verifie("est parcouru en ordre correctement", correct)
		);
	}

	debuteQuestion("Et apres tout avoir execute");
	valideQuestion(1,
		verifie("il n'y a pas de fuite de memoire", objetsAlloues == 0)
	);

	std::cout << "Score " << score << "/14" << std::endl;
}
