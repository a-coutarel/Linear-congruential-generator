/*
* @File:    superGeneCongruentiel.cpp
* @Project: Générateur de nombres pseuso-aléatoires - Mathématiques ESIREM 3A IT
* @Author:  Allan Coutarel, Valentin Cheny, Guillaume Imhoff
*/

#include <iostream>
#include "superGeneCongruentiel.h"

/**
 * Constructeur standard d'un super générateur congruentiel
 * Initialise tous les paramétres du générateur
 * @param nouveauGene : définit le générateur congruentiel linéaire utilisé pour choisir entre les générateurs fournis
 */
SuperGeneCongruentiel::SuperGeneCongruentiel(GeneCongruentiel geneChoix) : _geneChoix(geneChoix) {}

/**
 * Retourne _geneChoix
 * @return générateur congruentiel linéaire permettant de choisir
 */
GeneCongruentiel SuperGeneCongruentiel::getGeneChoix() const {
    return _geneChoix;
}

/**
 * Ajouter un générateur supplémentaire dans la liste des générateurs utilisés
 * @param nouveauGene générateur congruentiel linéaire à ajouter
 */
void SuperGeneCongruentiel::addGene(GeneCongruentiel nouveauGene) {
    _listGene.push_back(nouveauGene);
}

/**
 * Retourne le n ième générateur utilisé
 * @param nouveauGene générateur congruentiel linéaire à ajouter
 * @return n ième générateur
 */
GeneCongruentiel SuperGeneCongruentiel::getGene(int n) const {
    return _listGene[n];
}

/**
 * Renvoie un nombre pseudo aléatoire calculé à partir
 * des derniers nombre pseudo-aléatoire généré par chaque sous-générateur
 * @return nombre pseudo aléatoire
 */
int SuperGeneCongruentiel::genNb() {
    return _listGene[_geneChoix.genNb() % _listGene.size()].genNb();
}

/**
 * Renvoie la suite des l premiers nombres pseudo-aléatoires générés par :
 * @param gene super générateur congruentiel linéaire
 * @param l nombres d'éléments de la suite
 * @return suite de nombres pseudo-aléatoires
 */
std::vector<int> makeSequence(SuperGeneCongruentiel gene, int l) {
    std::vector<int> sequence;
	size_t L = l;
    for (size_t i = 1; i < L; i++)
        sequence.push_back(gene.genNb());
    return sequence;
}

bool presentHere(int n, std::vector<int> liste1, std::vector<int> liste2) {
	// test si la liste 1 est dans la liste 2 à la position n
	for (size_t i = 0; i < liste1.size(); i++) {
		if (liste1[i] != liste2[i + n])
			return false;
	}
	return true;
}

void periodeSGC(SuperGeneCongruentiel gene, int p_max) {

	std::vector<int> suite_debut = makeSequence(gene, 10);
	std::vector<int> suite = makeSequence(gene, p_max);

	for (size_t i = 0; i < suite.size(); i++) {
		if (presentHere(i, suite_debut, suite))
		{
			std::cout << i << std::endl;
		}
	}
}