/*
* @File:    main.cpp
* @Project: Générateur de nombres pseuso-aléatoires - Mathématiques ESIREM 3A IT
* @Author:  Allan Coutarel, Valentin Cheny, Guillaume Imhoff
*/

#include <iostream>
#include "geneCongruentiel.h"
#include "superGeneCongruentiel.h"
#include <fstream>
#include <algorithm>
#include <vector>

//ICI IL S'AGIT D'UN CODE D'EXEMPLE D'IMPLEMENTATION
//ON PEUT BIEN SUR L'ADAPTER A NOS BESOINS

//Exemple d'utilisation du générateur congruentiel linéaire
void exImpGC() {
	int taille_periode = 0;
	GeneCongruentiel gene(30, 12, 0, 31);
	std::cout << gene.genNb() << std::endl;
	std::cout << gene.genNb() << std::endl;
	std::cout << gene.genNb() << std::endl;
	std::vector<int> suite = makeSequence(gene, 100);
	std::vector<int> stats = getStats(gene);
	for (int i : suite)
		std::cout << i << " ";
	std::ofstream data("data.csv");
	for (int i : stats) {
		data << i << std::endl;
		taille_periode++;
	}
	std::cout << std::endl;
	std::cout << "La taille de la période du générateur est : " << taille_periode << std::endl;
}

//Construction du super générateur
SuperGeneCongruentiel exempleSGC() {
	GeneCongruentiel geneChoix(34, 13, 349, 509);
	GeneCongruentiel gene1(122, 367, 127, 509);
	GeneCongruentiel gene2(347, 257, 97, 509);
	GeneCongruentiel gene3(502, 53, 211, 509);
	GeneCongruentiel gene4(107, 47, 17, 509);

	SuperGeneCongruentiel superGene(geneChoix);
	superGene.addGene(gene1);
	superGene.addGene(gene2);
	superGene.addGene(gene3);
	superGene.addGene(gene4);

	return superGene;
}

//Exemple d'utilisation du super générateur congruentiel linéaire
void testsSGC() {
	auto SGC = exempleSGC();
	// obtenir la période
	periodeSGC(SGC, 300000);

	// exemples de valeurs
	auto suite = makeSequence(SGC, 200);
	for (auto x : suite)
		std::cout << x << std::endl;

	//enregistrer les valeurs
	std::ofstream data("data.csv");
	for (int i : suite)
		data << i << std::endl;
}

int main(){
	exImpGC();
	//testsSGC();
	return 0;
}