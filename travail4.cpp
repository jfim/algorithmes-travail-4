#include "travail4.h"

void ArbreBinaire::Insere(int valeur) {
	// S'il n'y a pas de racine, on insere la valeur comme racine
	if(racine == 0) {
		racine = new Noeud(valeur);
	} else {
		// Sinon, on insere de facon recursive
		Insere(0, racine, valeur);
	}
}

void ArbreBinaire::Insere(Noeud* parent, Noeud* actuel, int valeur) {
	if(actuel == 0) {
		// On a trouve le point d'insertion, alors on insere le noeud
		if (valeur < parent->valeur) {
			parent->gauche = new Noeud(valeur);
		} else {
			parent->droite = new Noeud(valeur);
		}
	} else {
		// On insere dans la bonne branche de l'arbre
		if (valeur < actuel->valeur) {
			Insere(actuel, actuel->gauche, valeur);
		} else {
			Insere(actuel, actuel->droite, valeur);
		}
	}
}

int ArbreBinaire::Hauteur() {
	return 0;
}

bool ArbreBinaire::Contient(int valeur) {
	return false;
}

void ArbreBinaire::Supprime(int valeur) {
}

void ArbreBinaire::ParcoursEnLargeur(int* valeurs) {
}

void ArbreBinaire::ParcoursPrefixe(int* valeurs) {
}

void ArbreBinaire::ParcoursPostfixe(int* valeurs) {
}

void ArbreBinaire::ParcoursEnOrdre(int* valeurs) {
}

int ArbreBinaire::Minimum() {
}

int ArbreBinaire::Maximum() {
}

void ArbreBinaire::SupprimeRecursivement(Noeud* noeud) {
}
