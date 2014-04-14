class Noeud {
	public:
		Noeud(int valeur) : valeur(valeur), gauche(0), droite(0) {}
		int valeur;
		Noeud* gauche;
		Noeud* droite;
};

class ArbreBinaire {
	public:
		ArbreBinaire() : racine(0) {}
		~ArbreBinaire() {
			SupprimeRecursivement(racine);
		}

	public:
		void Insere(int valeur);
		int Hauteur();
		bool Contient(int valeur);
		void Supprime(int valeur);
		void ParcoursEnLargeur(int* valeurs);
		void ParcoursPrefixe(int* valeurs);
		void ParcoursPostfixe(int* valeurs);
		void ParcoursEnOrdre(int* valeurs);
		int Minimum();
		int Maximum();
	
	private:
		Noeud* racine;
		void SupprimeRecursivement(Noeud* noeud);
		void Insere(Noeud* parent, Noeud* actuel, int valeur);
};
