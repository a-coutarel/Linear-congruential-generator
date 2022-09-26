/*
* @File:    geneCongruentiel.cpp
* @Project: Générateur de nombres pseuso-aléatoires - Mathématiques ESIREM 3A IT
* @Author:  Allan Coutarel, Valentin Cheny, Guillaume Imhoff
*/

#include <iostream>
#include "geneCongruentiel.h"

/**
 * Constructeur standard d'un générateur congruentiel
 * Initialise tous les paramètres du générateur
 * @param seed graine
 * @param a multiplicateur
 * @param c incrément
 * @param m module
 */
GeneCongruentiel::GeneCongruentiel(int seed, int a, int c, int m) : _seed(seed), _X(seed), _a(a), _c(c), _m(m){}


/**
 * @return multiplicateur du générateur
 */
int GeneCongruentiel::getA() const {
    return _a;
}

/**
 * @return incrément du générateur
 */
int GeneCongruentiel::getC() const {
    return _c;
}

/**
 * @return module du générateur
 */
int GeneCongruentiel::getM() const {
    return _m;
}

/**
 * @return graine du générateur
 */
int GeneCongruentiel::getSeed() const {
    return _seed;
}

/**
 * Renvoie un nombre pseudo aléatoire calculé à partir 
 * du dernier nombre pseudo-aléatoire généré
 * @return nombre pseudo aléatoire
 */
int GeneCongruentiel::genNb() {
    _X = (_a*_X+_c)%_m;
    return _X;
}

/**
 * Renvoie la suite des l premiers nombres pseudo-aléatoires générés par :
 * @param gene générateur congruentiel linéaire
 * @param l nombres d'éléments de la suite
 * @return suite de nombres pseudo-aléatoires
 */
std::vector<int> makeSequence(GeneCongruentiel gene, int l) {
    std::vector<int> sequence;
    gene._X = gene.getSeed();
    sequence.push_back(gene.getSeed());
    for(int i=1; i<l; i++)
        sequence.push_back(gene.genNb());
    return sequence;
}

/**
 * Renvoie la suite de tous les nombres pseudo-aléatoires différents générés par :
 * @param gene générateur congruentiel linéaire
 * @return suite de nombres pseudo-aléatoires (1 période)
 */
std::vector<int> getStats(GeneCongruentiel gene) {
    std::vector<int> sequence = makeSequence(gene, gene.getM());
    std::vector<int> res;
    res.push_back(sequence.at(0));
    res.push_back(sequence.at(1));
    bool find = false;
    int i=2;
    do {
        if(sequence.at(i)!=sequence.at(0) && sequence.at(i)!=sequence.at(1))
            res.push_back(sequence.at(i));
        else
            find = true;
        i++;
    }while(!find && i<gene.getM());
    return res;
}